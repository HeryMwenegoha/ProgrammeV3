// -*- Mode: C++; c-basic-offset: 8; indent-tabs-mode: nil -*-
//
// Interrupt-driven serial transmit/receive library.
//
//      Copyright (c) 2010 Michael Smith. All rights reserved.
//
// Receive and baudrate calculations derived from the Arduino 
// HardwareSerial driver:
//
//      Copyright (c) 2006 Nicholas Zambetti.  All right reserved.
//
// Transmit algorithm inspired by work:
//
//      Code Jose Julio and Jordi Munoz. DIYDrones.com
//
//      This library is free software; you can redistribute it and/or
//      modify it under the terms of the GNU Lesser General Public
//      License as published by the Free Software Foundation; either
//      version 2.1 of the License, or (at your option) any later
//      version.
//
//      This library is distributed in the hope that it will be
//      useful, but WITHOUT ANY WARRANTY; without even the implied
//      warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//      PURPOSE.  See the GNU Lesser General Public License for more
//      details.
//
//      You should have received a copy of the GNU Lesser General
//      Public License along with this library; if not, write to the
//      Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
//      Boston, MA 02110-1301 USA
//

//
// Note that this library does not pre-declare drivers for serial
// ports; the user must explicitly create drivers for the ports they
// wish to use.  This is less friendly than the stock Arduino driver,
// but it saves 24 bytes of RAM for every unused port and frees up
// the vector for another driver (e.g. MSPIM on USARTs).
//

#ifndef FastSerial_h
#define FastSerial_h


// disable the stock Arduino serial driver
#ifdef HardwareSerial_h
# error Must include FastSerial.h before the Arduino serial driver is defined.
#endif
#define HardwareSerial_h

#include <inttypes.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "BetterStream.h"

//
// Because Arduino libraries aren't really libraries, but we want to
// only define interrupt handlers for serial ports that are actually
// used, we have to force our users to define them using a macro.
//
// Due to the way interrupt vectors are specified, we have to have
// a separate macro for every port.  Ugh.
//
// The macros are:
//
// FastSerialPort0(<port name>)         creates <port name> referencing serial port 0
// FastSerialPort1(<port name>)         creates <port name> referencing serial port 1
// FastSerialPort2(<port name>)         creates <port name> referencing serial port 2
// FastSerialPort3(<port name>)         creates <port name> referencing serial port 3
//
// Note that macros are only defined for ports that exist on the target device.
//

//
// Forward declarations for clients that want to assume that the
// default Serial* objects exist.
//
// Note that the application is responsible for ensuring that these
// actually get defined, otherwise Arduino will suck in the
// HardwareSerial library and linking will fail.
//
extern class FastSerial Serial;
extern class FastSerial Serial1;
extern class FastSerial Serial2;
extern class FastSerial Serial3;

class FastSerial : public BetterStream {
public:
        FastSerial(const uint8_t portNumber,
                   volatile uint8_t *ubrrh,
                   volatile uint8_t *ubrrl,
                   volatile uint8_t *ucsra,
                   volatile uint8_t *ucsrb,
                   const uint8_t u2x,
                   const uint8_t portEnableBits,
                   const uint8_t portTxBits);

        // Serial API
        virtual void    begin(long baud);
        virtual void    begin(long baud, unsigned int rxSpace, unsigned int txSpace);
        virtual void    end(void);
        virtual int     available(void);
        virtual int     read(void);
		virtual int     TXroom(void);
        virtual int     peek(void);
        virtual void    flush(void);
        virtual size_t    write(uint8_t c);
        using BetterStream::write;

        // public so the interrupt handlers can see it
        struct Buffer {
                volatile uint16_t head, tail;
                uint16_t        mask;
                uint8_t         *bytes;
        };

private:
        // register accessors
        volatile uint8_t *_ubrrh;
        volatile uint8_t *_ubrrl;
        volatile uint8_t *_ucsra;
        volatile uint8_t *_ucsrb;

        // register magic numbers
        uint8_t         _portEnableBits;        // rx, tx and rx interrupt enables
        uint8_t         _portTxBits;            // tx data and completion interrupt enables
        uint8_t         _u2x;

        // ring buffers
        Buffer          *_rxBuffer;
        Buffer          *_txBuffer;
        bool            _open;

        static bool     _allocBuffer(Buffer *buffer, unsigned int size);
        static void     _freeBuffer(Buffer *buffer);
};

// Used by the per-port interrupt vectors
extern FastSerial::Buffer	__FastSerial__rxBuffer[];
extern FastSerial::Buffer	__FastSerial__txBuffer[];

// Generic Rx/Tx vectors for a serial port - needs to know magic numbers
#define FastSerialHandler(_PORT, _RXVECTOR, _TXVECTOR, _UDR, _UCSRB, _TXBITS) \
ISR(_RXVECTOR, ISR_BLOCK)                                               \
{                                                                       \
        uint8_t c;                                                      \
        int16_t i;                                                      \
                                                                        \
        /* read the byte as quickly as possible */                      \
        c = _UDR;                                                       \
        /* work out where the head will go next */                      \
        i = (__FastSerial__rxBuffer[_PORT].head + 1) & __FastSerial__rxBuffer[_PORT].mask; \
        /* decide whether we have space for another byte */             \
        if (i != __FastSerial__rxBuffer[_PORT].tail) {                  \
                /* we do, move the head */                              \
                __FastSerial__rxBuffer[_PORT].bytes[__FastSerial__rxBuffer[_PORT].head] = c; \
                __FastSerial__rxBuffer[_PORT].head = i;                 \
        }                                                               \
}                                                                       \
ISR(_TXVECTOR, ISR_BLOCK)                                               \
{                                                                       \
        /* if there is another character to send */                     \
        if (__FastSerial__txBuffer[_PORT].tail != __FastSerial__txBuffer[_PORT].head) { \
                _UDR = __FastSerial__txBuffer[_PORT].bytes[__FastSerial__txBuffer[_PORT].tail]; \
                /* increment the tail */                                \
                __FastSerial__txBuffer[_PORT].tail =                    \
                        (__FastSerial__txBuffer[_PORT].tail + 1) & __FastSerial__txBuffer[_PORT].mask; \
        } else {                                                        \
                /* there are no more bytes to send, disable the interrupt */ \
                if (__FastSerial__txBuffer[_PORT].head == __FastSerial__txBuffer[_PORT].tail) \
                        _UCSRB &= ~_TXBITS;                             \
        }                                                               \
}                                                                       \
struct hack

//
// Portability; convert various older sets of defines for U(S)ART0 up
// to match the definitions for the 1280 and later devices.
//
#if !defined(USART0_RX_vect)
# if defined(USART_RX_vect)
#  define USART0_RX_vect        USART_RX_vect
#  define USART0_UDRE_vect      USART_UDRE_vect
# elif defined(UART0_RX_vect)
#  define USART0_RX_vect        UART0_RX_vect
#  define USART0_UDRE_vect      UART0_UDRE_vect
# endif
#endif

#if !defined(USART1_RX_vect)
# if defined(UART1_RX_vect)
#  define USART1_RX_vect        UART1_RX_vect
#  define USART1_UDRE_vect      UART1_UDRE_vect
# endif
#endif

#if !defined(UDR0)
# if defined(UDR)
#  define UDR0                  UDR
#  define UBRR0H                UBRRH
#  define UBRR0L                UBRRL
#  define UCSR0A                UCSRA
#  define UCSR0B                UCSRB
#  define U2X0                  U2X
#  define RXEN0                 RXEN
#  define TXEN0                 TXEN
#  define RXCIE0                RXCIE
#  define UDRIE0                UDRIE
# endif
#endif

//
// Macro defining a FastSerial port instance.
//
#define FastSerialPort(_name, _num)                                     \
	FastSerial _name(_num,                                          \
                         &UBRR##_num##H,                                \
                         &UBRR##_num##L,                                \
                         &UCSR##_num##A,                                \
                         &UCSR##_num##B,                                \
                         U2X##_num,                                     \
                         (_BV(RXEN##_num) |  _BV(TXEN##_num) | _BV(RXCIE##_num)), \
                         (_BV(UDRIE##_num)));                           \
	FastSerialHandler(_num,                                         \
                          USART##_num##_RX_vect,                        \
                          USART##_num##_UDRE_vect,                      \
                          UDR##_num,                                    \
                          UCSR##_num##B,                                \
                          _BV(UDRIE##_num))

//
// Compatibility macros for previous FastSerial versions.
//
// Note that these are not conditionally defined, as the errors
// generated when using these macros for a board that does not support
// the port are better than the errors generated for a macro that's not
// defined at all.
//
#define FastSerialPort0(_portName)     FastSerialPort(_portName, 0)
#define FastSerialPort1(_portName)     FastSerialPort(_portName, 1)
#define FastSerialPort2(_portName)     FastSerialPort(_portName, 2)
#define FastSerialPort3(_portName)     FastSerialPort(_portName, 3)

#endif // FastSerial_h
