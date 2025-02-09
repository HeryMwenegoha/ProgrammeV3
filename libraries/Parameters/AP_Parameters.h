/* Created by Hery A Mwenegoha (C) 2015
 * eeprom parameter list for this MAV
 * EEPROM ADDRESSES 3000 - 3999 allocated for parameters 
 * 3999 - NEW PARAMETER VERSION 
 * if old and new are either both 0 or 255 then no parameters are present.
 * stores approximately 250 float parameters
 */

#pragma once
#include "Arduino.h"
#include <EEPROM.h>
#include "mavlink.h"
#define GROUP_INFO(index, datatype, position, length, id, val) {index, datatype, position, length,  id, val}
#define PARAMETER_VERSION 0x01
#define EEPROM_PARAMETER_PAGE 3000

//#if defined(CHARS_TABLE)
const char RUDDER_MIX[] 	 PROGMEM  = "RUDDER_MIX";
const char REV_ROLL_SIG[] 	 PROGMEM  = "REV_ROLL_SIG";
const char REV_PITCH_SIG[] 	 PROGMEM  = "REV_PITCH_SIG";
const char REV_YAW_SIG[] 	 PROGMEM  = "REV_YAW_SIG";
const char REV_THR_SIG[] 	 PROGMEM  = "REV_THR_SIG";
const char ROLL_PID_KP[] 	 PROGMEM  = "ROLL_PID_KP";
const char ROLL_PID_KI[] 	 PROGMEM  = "ROLL_PID_KI";
const char ROLL_PID_KD[] 	 PROGMEM  = "ROLL_PID_KD";
const char ROLL_TAU[] 		 PROGMEM  = "ROLL_TAU";
const char ROLL_RMAX[] 		 PROGMEM  = "ROLL_RMAX";
const char ROLL_IMAX[] 		 PROGMEM  = "ROLL_IMAX";
const char MAX_ROLL_DEG[] 	 PROGMEM  = "MAX_ROLL_DEG";
const char MAX_ROLL_AUX[]	 PROGMEM  = "MAX_ROLL_AUX";
const char MIN_ROLL_AUX[] 	 PROGMEM  = "MIN_ROLL_AUX";
const char PITCH_PID_KP[]	 PROGMEM  = "PITCH_PID_KP";
const char PITCH_PID_KI[] 	 PROGMEM  = "PITCH_PID_KI";
const char PITCH_PID_KD[]  	 PROGMEM  = "PITCH_PID_KD";
const char PITCH_TAU[] 		 PROGMEM  = "PITCH_TAU";
const char PITCH_RMAX[] 	 PROGMEM  = "PITCH_RMAX";
const char PITCH_IMAX[] 	 PROGMEM  = "PITCH_IMAX";
const char MAX_PITCH_DEG[]   PROGMEM  = "MAX_PITCH_DEG";
const char PTCH2SRV_RLL[] 	 PROGMEM  = "PTCH2SRV_RLL";
const char MAX_PITCH_AUX[] 	 PROGMEM  = "MAX_PITCH_AUX";
const char MIN_PITCH_AUX[] 	 PROGMEM  = "MIN_PITCH_AUX";
const char STEER_PID_KP[] 	 PROGMEM  = "STEER_PID_KP";
const char STEER_PID_KI[] 	 PROGMEM  = "STEER_PID_KI";
const char STEER_PID_KD[] 	 PROGMEM  = "STEER_PID_KD";
const char STEER_TAU[] 		 PROGMEM  = "STEER_TAU";
const char STEER_RMAX[] 	 PROGMEM  = "STEER_RMAX";
const char STEER_IMAX[] 	 PROGMEM  = "STEER_IMAX";
const char YAW2SRV_SLP[] 	 PROGMEM  = "YAW2SRV_SLP";
const char YAW2SRV_RLL[] 	 PROGMEM  = "YAW2SRV_RLL";
//const char YAW_FFRDDRMIX[] 	 PROGMEM  = "YAW_FFRDDRMIX";
const char MAX_YAW_AUX[] 	 PROGMEM  = "MAX_YAW_AUX";
const char MIN_YAW_AUX[] 	 PROGMEM  = "MIN_YAW_AUX";
const char L1_DAMPING[] 	 PROGMEM  = "L1_DAMPING";
const char L1_PERIOD[] 		 PROGMEM  = "L1_PERIOD";
const char L1_BANK[] 		 PROGMEM  = "L1_BANK";
const char L1_GRAVITY[] 	 PROGMEM  = "L1_GRAVITY";
const char MAX_THR_AUX[] 	 PROGMEM  = "MAX_THR_AUX";
const char MIN_THR_AUX[] 	 PROGMEM  = "MIN_THR_AUX";
const char MAX_THR_PERC[] 	 PROGMEM  = "MAX_THR_PERC";
const char MIN_THR_PERC[] 	 PROGMEM  = "MIN_THR_PERC";
const char CRUISE_THR[] 	 PROGMEM  = "CRUISE_THR";
const char SLEW_RATE[] 		 PROGMEM  = "SLEW_RATE";
const char MAX_SPEED[] 		 PROGMEM  = "MAX_SPEED";
const char MIN_SPEED[] 		 PROGMEM  = "MIN_SPEED";
const char CRUISE_SPEED[] 	 PROGMEM  = "CRUISE_SPEED";
const char LAND_SPEED[]		 PROGMEM  = "LAND_SPEED";
const char CRUISE_ALT[] 	 PROGMEM  = "CRUISE_ALT";
const char APPROACH[] 		 PROGMEM  = "APPROACH";

/*
const char TECS_PGAIN[] 	 PROGMEM  = "TECS_PGAIN";
const char TECS_IGAIN[] 	 PROGMEM  = "TECS_IGAIN";
const char TECS_DGAIN[] 	 PROGMEM  = "TECS_DGAIN";
const char TECS_TCONST[] 	 PROGMEM  = "TECS_TCONST";
const char TECS_RMAX[] 		 PROGMEM  = "TECS_RMAX";
const char TECS_THR_SLEW[] 	 PROGMEM  = "TECS_THR_SLEW";
*/
const char TECS_THR_LAND[] 	 PROGMEM  = "TECS_THR_LAND";
const char TECS_THR_TOMAX[]  PROGMEM  = "TECS_THR_TOMAX";
const char AUTO_PITCHMAX[] 	 PROGMEM  = "AUTO_PITCHMAX";
const char AUTO_PITCHMIN[] 	 PROGMEM  = "AUTO_PITCHMIN";
const char LAND_PITCH_MAX[]  PROGMEM  = "LAND_PITCH_MAX";
const char LAND_PITCH_MIN[]  PROGMEM  = "LAND_PITCH_MIN";

/*
const char MAX_CLIMBRATE[] 	 PROGMEM  = "MAX_CLIMBRATE";
const char MAX_SINKRATE[] 	 PROGMEM  = "MAX_SINKRATE";
const char MIN_SINKRATE[] 	 PROGMEM  = "MIN_SINKRATE";
const char TECS_FLARE_SECS[] PROGMEM = "TECS_FLARE_SECS";
*/
const char ARSPD_ENABLED[] 	 PROGMEM = "ARSPD_ENABLED";
const char STALL_PREVENT[] 	 PROGMEM = "STALL_PREVENT";
const char POWERMODULE_GAIN[]PROGMEM = "PWR_GAIN";

/*
const char ACCEL1_OFFSETX[]  PROGMEM  = "ACCEL1_OFFSETX";
const char ACCEL1_OFFSETY[]  PROGMEM = "ACCEL1_OFFSETY";
const char ACCEL1_OFFSETZ[]  PROGMEM = "ACCEL1_OFFSETZ";
const char ACCEL1_LSBX[]	 PROGMEM = "ACCEL1_LSBX";
const char ACCEL1_LSBY[]	 PROGMEM = "ACCEL1_LSBY";
const char ACCEL1_LSBZ[]	 PROGMEM = "ACCEL1_LSBZ";
*/

const char ACCEL2_OFFSETX[]  PROGMEM = "ACCEL2_OFFSETX";
const char ACCEL2_OFFSETY[]  PROGMEM = "ACCEL2_OFFSETY";
const char ACCEL2_OFFSETZ[]  PROGMEM = "ACCEL2_OFFSETZ";
const char ACCEL2_LSBX[]	 PROGMEM = "ACCEL2_LSBX";
const char ACCEL2_LSBY[]	 PROGMEM = "ACCEL2_LSBY";
const char ACCEL2_LSBZ[]	 PROGMEM = "ACCEL2_LSBZ";

const  char* const param_table[] PROGMEM = 
{
  RUDDER_MIX,
  REV_ROLL_SIG,
  REV_PITCH_SIG,
  REV_YAW_SIG,
  REV_THR_SIG,
  ROLL_PID_KP,
  ROLL_PID_KI,
  ROLL_PID_KD,
  ROLL_TAU,
  ROLL_RMAX,
  ROLL_IMAX,
  MAX_ROLL_DEG,
  MAX_ROLL_AUX,
  MIN_ROLL_AUX,
  PITCH_PID_KP,
  PITCH_PID_KI,
  PITCH_PID_KD,
  PITCH_TAU,
  PITCH_RMAX,
  PITCH_IMAX,
  MAX_PITCH_DEG,
  PTCH2SRV_RLL,
  MAX_PITCH_AUX,
  MIN_PITCH_AUX,
  STEER_PID_KP,
  STEER_PID_KI,
  STEER_PID_KD,
  STEER_TAU,
  STEER_RMAX,
  STEER_IMAX,
  YAW2SRV_SLP,
  YAW2SRV_RLL,
  //YAW_FFRDDRMIX,
  MAX_YAW_AUX,
  MIN_YAW_AUX,
  L1_DAMPING,
  L1_PERIOD,
  L1_BANK,
  L1_GRAVITY,
  MAX_THR_AUX,
  MIN_THR_AUX,
  MAX_THR_PERC,
  MIN_THR_PERC,
  CRUISE_THR,
  //SLEW_RATE,
  MAX_SPEED,
  MIN_SPEED,
  CRUISE_SPEED,
  LAND_SPEED,
  CRUISE_ALT,
  APPROACH,
  /*
  TECS_PGAIN,
  TECS_IGAIN,
  TECS_DGAIN,
  TECS_TCONST,
  TECS_RMAX,
  TECS_THR_SLEW,
  */
  TECS_THR_LAND,
  TECS_THR_TOMAX,
  AUTO_PITCHMAX,
  AUTO_PITCHMIN,
  LAND_PITCH_MAX,
  LAND_PITCH_MIN,
  /*
  MAX_CLIMBRATE,
  MAX_SINKRATE,
  MIN_SINKRATE,
  TECS_FLARE_SECS,
  */
  ARSPD_ENABLED,
  STALL_PREVENT,
  POWERMODULE_GAIN,
  
  /*
  ACCEL1_OFFSETX,
  ACCEL1_OFFSETY,
  ACCEL1_OFFSETZ,
  ACCEL1_LSBX,
  ACCEL1_LSBY,
  ACCEL1_LSBZ,
  */
  
  ACCEL2_OFFSETX,
  ACCEL2_OFFSETY,
  ACCEL2_OFFSETZ,
  ACCEL2_LSBX,
  ACCEL2_LSBY,
  ACCEL2_LSBZ,
};
//#endif

/*
 * Different Data Types defined in MAV_TYPE
 */
enum DATA_TYPES{
	FLOAT   = 0,  		/* 32 bit float*/
	U8 		= 1,  		/* 8 bit unsigned integer*/
	I8		= 2,  		/* 8 bit signed integer*/
	U16		= 3,  		/* 16 bit unsigned integer*/
	I16		= 4,  		/* 16 bit signed integer*/
	U32		= 5,  		/* 32 bit unsigned integer*/
	I32		= 6,  		/* 32 bit signed integer*/
	DATA_TYPES_END = 7,	/* */
};


/*
 * Structure defining elements in the PROGMEM Parameter Table
 */
struct _GROUP_DATA{
   int8_t         idx;
   int8_t        type;
   int8_t         pos;
   int8_t         len;
   const char     *id;
   float          val;
};


const _GROUP_DATA GROUP_DATA[] PROGMEM =
{
	GROUP_INFO(0, 	FLOAT,	0,	4,	RUDDER_MIX,			0.3),
	GROUP_INFO(1, 	I8,		4,	1,	REV_ROLL_SIG,		1),
	GROUP_INFO(2, 	I8,		5,	1,	REV_PITCH_SIG,		1),
	GROUP_INFO(3, 	I8,		6,	1,	REV_YAW_SIG,		1),
	GROUP_INFO(4, 	I8,		7,	1,	REV_THR_SIG,		1),
	
	// ROLL
	GROUP_INFO(5, 	FLOAT,	8,	4,	ROLL_PID_KP,		0.85),
	GROUP_INFO(6,	FLOAT,	12,	4,	ROLL_PID_KI,		0.2),
	GROUP_INFO(7, 	FLOAT,	16,	4,	ROLL_PID_KD,		0.02),
	GROUP_INFO(8, 	FLOAT,	20,	4,	ROLL_TAU,			0.5),
	GROUP_INFO(9, 	U8,		24,	1,	ROLL_RMAX,			60),
	GROUP_INFO(10,	U8,		25,	1,	ROLL_IMAX,			15),
	GROUP_INFO(11,	U8,		26,	1,	MAX_ROLL_DEG,		45),
	GROUP_INFO(12,	U16,	27,	2,	MAX_ROLL_AUX,		2000),
	GROUP_INFO(13,	U16,	29,	2,	MIN_ROLL_AUX,		1044),
	
	// PITCH
	GROUP_INFO(14, 	FLOAT,	31,	4,	PITCH_PID_KP,		0.85),
	GROUP_INFO(15,	FLOAT,	35,	4,	PITCH_PID_KI,		0.25),
	GROUP_INFO(16, 	FLOAT,	39,	4,	PITCH_PID_KD,		0.05),
	GROUP_INFO(17, 	FLOAT,	43,	4,	PITCH_TAU,			0.5),
	GROUP_INFO(18, 	U8,		47,	1,	PITCH_RMAX,			60),
	GROUP_INFO(19,	U8,		48,	1,	PITCH_IMAX,			15),
	GROUP_INFO(20,	U8,		49,	1,	MAX_PITCH_DEG,		25),
	GROUP_INFO(21,	FLOAT,	50,	4,	PTCH2SRV_RLL,		1),
	GROUP_INFO(22,	U16,	54,	2,	MAX_PITCH_AUX,		2000),
	GROUP_INFO(23,	U16,	56,	2,	MIN_PITCH_AUX,		1044),
	
	// STEER
	GROUP_INFO(24, 	FLOAT,	58,	4,	STEER_PID_KP,		2.0),
	GROUP_INFO(25,	FLOAT,	62,	4,	STEER_PID_KI,		0.2),
	GROUP_INFO(26, 	FLOAT,	66,	4,	STEER_PID_KD,		0.02),
	GROUP_INFO(27, 	FLOAT,	70,	4,	STEER_TAU,			0.5),
	GROUP_INFO(28, 	U8,		74,	1,	STEER_RMAX,			90),
	GROUP_INFO(29,	U8,		75,	1,	STEER_IMAX,			15),
	GROUP_INFO(30,	FLOAT,	76,	4,	YAW2SRV_SLP,		0),
	GROUP_INFO(31,	FLOAT,	80,	4,	YAW2SRV_RLL,		1),
	GROUP_INFO(32,	U16,	84,	2,	MAX_YAW_AUX,		2000),
	GROUP_INFO(33,	U16,	86,	2,	MIN_YAW_AUX,		1044),
	
	// L1
	GROUP_INFO(34, 	FLOAT,	88,	4,	L1_DAMPING,			0.707),
	GROUP_INFO(35,	FLOAT,	92,	4,	L1_PERIOD,			17),
	GROUP_INFO(36, 	FLOAT,	96,	4,	L1_BANK,			45),
	GROUP_INFO(37, 	FLOAT,	100,4,	L1_GRAVITY,			9.806),
	
	GROUP_INFO(38, 	U16,	104,2,	MAX_THR_AUX,		2000),
	GROUP_INFO(39,	U16,	106,2,	MIN_THR_AUX,		1044),
	GROUP_INFO(40,	U8,		108,1,	MAX_THR_PERC,		100),
	GROUP_INFO(41,	U8,		109,1,	MIN_THR_PERC,		0),
	GROUP_INFO(42,	U8,		110,1,	CRUISE_THR,			60),	
	GROUP_INFO(43,	U8,		111,1,	SLEW_RATE,			75),
	GROUP_INFO(44,	U8,		112,1,	MAX_SPEED,			20),		
	GROUP_INFO(45,	U8,		113,1,	MIN_SPEED,			5),
	GROUP_INFO(46,	U8,		114,1,	CRUISE_SPEED,		14),
	GROUP_INFO(47,	U8,		115,1,	LAND_SPEED,			11),
	GROUP_INFO(48,	U16,	116,2,	CRUISE_ALT,			100),	
	GROUP_INFO(49,	U8,		118,1,	APPROACH,			0),

	// TECS	
	GROUP_INFO(50, 	U8,		119,1,	TECS_THR_LAND,		30),
	GROUP_INFO(51,	U8,		120,1,	TECS_THR_TOMAX,		100),
	GROUP_INFO(52, 	I8,		121,1,	AUTO_PITCHMAX,		15),
	GROUP_INFO(53, 	I8,		122,1,	AUTO_PITCHMIN,   	-15),
	GROUP_INFO(54, 	I8,		123,1,	LAND_PITCH_MAX,		5),
	GROUP_INFO(55,	I8,		124,1,	LAND_PITCH_MIN,  	-5),
	GROUP_INFO(56,	U8,		125,1,	ARSPD_ENABLED,		1),
	GROUP_INFO(57,	U8,		126,1,	STALL_PREVENT,		1),
	GROUP_INFO(58,	FLOAT,	127,4,	POWERMODULE_GAIN,	0.047),
	
	// IMU
	GROUP_INFO(59, 	I16,	131,2,	ACCEL2_OFFSETX,		0),
	GROUP_INFO(60,	I16,	133,2,	ACCEL2_OFFSETY,		0),
	GROUP_INFO(61, 	I16,	135,2,	ACCEL2_OFFSETZ,		0),
	GROUP_INFO(62, 	U16,	137,2,	ACCEL2_LSBX,		8192),
	GROUP_INFO(63, 	U16,	139,2,	ACCEL2_LSBY,		8192),
	GROUP_INFO(64,	U16,	141,2,	ACCEL2_LSBZ,		8192),
};

struct _Param_t{
	
   public:
   _Param_t(){
	   index = 0;
	  type  = 0;
      val   = 0;
      count = 0;	
	  strcpy_P(id, (char *)pgm_read_word(&GROUP_DATA[0].id));
   }
   
   
   uint8_t    type;
   char 	  id[16];
   float      val;
   uint16_t   count;
   uint16_t   index;
};

#define GROUP_DATA_SIZE 65
	
struct _parameter_list_t
{
  float   	rudder_mix    ; 		// Pos 0
  int8_t  	rev_roll_sig  ; 		// Pos 1
  int8_t  	rev_pitch_sig ; 		// Pos 2
  int8_t  	rev_yaw_sig   ; 		// Pos 3
  int8_t  	rev_thr_sig   ; 		// Pos 4  
  
  float 	roll_kp       ; 		// Pos 5
  float 	roll_ki       ;			// Pos 6
  float 	roll_kd       ; 		// Pos 7
  float 	roll_tau      ; 		// --> 8
  uint8_t 	roll_rmax     ; 		// --> 9	0 - 180 deg/sec
  uint8_t 	roll_imax     ; 		// --> 10   0 - 45  deg 
  uint8_t 	max_roll_deg  ; 		// Pos 11   0 - 90  deg
  uint16_t 	max_roll_aux  ; 		// Pos 12   1000 - 2000
  uint16_t 	min_roll_aux  ; 		// Pos 13   1000 - 2000
  
  float 	pitch_kp      ; 		// Pos 14 
  float 	pitch_ki      ; 		// Pos 15 
  float 	pitch_kd      ; 		// Pos 16 
  float 	pitch_tau     ; 		// --> 17
  uint8_t 	pitch_rmax    ;			// --> 18  0 - 180 deg/sec
  uint8_t 	pitch_imax    ; 		// --> 19  0 - 45 deg
  uint8_t 	max_pitch_deg ; 		// Pos 20  0 - 90 deg
  float 	PTCH2SRV_RLL  ; 		// --> 21  
  uint16_t 	max_pitch_aux ; 		// Pos 22
  uint16_t 	min_pitch_aux ; 		// Pos 23
  
  float 	steer_kp      ; 		// Pos 24
  float 	steer_ki      ; 		// Pos 25
  float 	steer_kd      ; 		// Pos 26
  float 	steer_tau     ; 		// --> 27
  uint8_t 	steer_rmax    ;			// --> 28
  uint8_t 	steer_imax    ; 		// --> 29
  float 	YAW2SRV_SLP   ; 		// --> 30
  float 	YAW2SRV_RLL   ; 		// --> 31
  uint16_t 	max_yaw_aux   ; 		// Pos 33
  uint16_t 	min_yaw_aux   ; 		// Pos 34
  
  float		L1_damping    ; 		// --> 35
  float 	L1_period     ; 		// --> 36
  float 	L1_bank       ; 		// --> 37
  float 	L1_gravity    ; 		// --> 38
  
  uint16_t	max_thr_aux   ; 		// Pos 39    1000 - 2000
  uint16_t 	min_thr_aux   ; 		// Pos 40    1000 - 2000
  uint8_t	max_thr_perc  ; 		// Pos 41    0 - 100
  uint8_t	min_thr_perc  ; 		// Pos 42    0 - 100
  uint8_t	cru_thr       ; 		// Pos 43    0 - 100
  uint8_t   slew_rate     ; 		// Pos 44    0 - 100
 
  uint8_t	max_speed     ; 		// --> 45    m/s
  uint8_t	min_speed     ; 		// --> 46
  uint8_t	cru_speed     ; 		// Pos 47
  uint8_t 	land_speed    ;         // Pos 48
  uint16_t 	cru_altitude  ; 		// Pos 49 
  uint8_t 	APPROACH      ;       	// Pos 49
  
  /*
  float		TECS_thr_Proportional;	// Pos 50
  float		TECS_thr_Integrator;  	// Pos 51
  float		TECS_thr_Damping;    	// Pos 52
  float		TECS_thr_TCONST;     	// Pos 53
  float		TECS_thr_rmax;       	// Pos 54
  float		TECS_thr_SlewRate;  	// Pos 55
  */
  
  uint8_t	TECS_thr_land;      	// Pos 56
  uint8_t	TECS_thr_tomax;     	// Pos 57
  int8_t	AUTO_pitchmax;          // Pos 58
  int8_t	AUTO_pitchmin;          // Pos 59
  int8_t	TECS_land_pitchmax;     // Pos 60
  int8_t	TECS_land_pitchmin;     // Pos 61
  
  /*
  float		TECS_maxClimbRate;      // Pos 62
  float		TECS_maxSinkRate;       // Pos 63
  float		TECS_minSinkRate;       // Pos 64
  float		TECS_flare_secs;        // Pos 65
  */
  
  uint8_t	arspdEnabled;    	    // Pos 66
  uint8_t	TECS_stallPrevent;      // Pos 67
  float		PowerModule_Gain;	    // Pos 68
 
  int16_t	Accel2_offsetX;		    // Pos 75  L3GD20	(Currently Primary Instance) 
  int16_t	Accel2_offsetY;		    // Pos 76
  int16_t	Accel2_offsetZ;		    // Pos 77
  uint16_t	Accel2_lsbX;		    // Pos 78
  uint16_t	Accel2_lsbY;		    // Pos 79
  uint16_t	Accel2_lsbZ;		    // Pos 80
};


class AP_Storage
{
  public:
  AP_Storage();

  /*
   * Keeping it similar for compatibility
   */
  typedef union _EEPROM_parameters_t
  {
    _parameter_list_t list;
    byte paramBuffer[sizeof(_parameter_list_t)];
  };  
  _EEPROM_parameters_t ParameterStorage;
  
  
  /*
   * Initialise Parameters
   */
  void initialise(HardwareSerial *_port);  
  
  
  /*
   * Function called once a parameter has been received -> check proper mavlink message
   * Writes a received parameter to storage
   * Checks the received parameter ID and writes to storage
   *
   */
  void UpdateStorage(const char param_id[16], float param_value, bool write_eeprom);

  
  /*
   * read all parameters from storage
   */
  void ReadAll(void);
  
  
  /*
   * writes all parameters to storage
   */
  void WriteAll(void);  
  
  
  /*
   * returns a struct parameter given parameter index 
   */ 
  _Param_t    get_param(const char param_id[16]);
  
  
  /*
   * returns a struct parameter given parameter id
   */
  _Param_t    get_param(const uint16_t x); 


  /*
   * prints all parameters
   */
  void     print_all();  
  
  private:
  HardwareSerial *Port;
  uint8_t  get_type(const uint8_t x);
  uint8_t  get_type(const char param_id[16]);
  uint16_t get_index(const char param_id[16]);
  
  union _f_un
  {
	float val;
	uint8_t buffer[sizeof(float)];
  };
  
  union _i8_un
  {
	int8_t val;
	uint8_t buffer[sizeof(int8_t)];
  };
  
  union _u8_un
  {
	uint8_t val;
	uint8_t buffer[sizeof(uint8_t)];
  };
 
  union _u16_un
  {
	uint16_t val;
	uint8_t buffer[sizeof(uint16_t)];
  }; 
  
  union _i16_un
  {
	int16_t val;
	uint8_t buffer[sizeof(int16_t)];
  }; 
  
  union _i32_un
  {
	int32_t val;
	uint8_t buffer[sizeof(int32_t)];
  };
  
  union _u32_un
  {
	uint32_t val;
	uint8_t buffer[sizeof(uint32_t)];
  };
};

extern AP_Storage  AP_params;