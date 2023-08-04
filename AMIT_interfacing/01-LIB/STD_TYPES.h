#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

/********************************** Standard type for unsigned integer ********************************/
typedef unsigned char unit8;
typedef unsigned short unit16;
typedef unsigned long int unit32;
/********************************** Standard type for signed integer **********************************/
typedef signed char snit8;
typedef signed short snit16;
typedef signed long int snit32;
/********************************** Standard type for floats ******************************************/
typedef float f32;
typedef double f64;


typedef enum
{
	E_OK,
	E_NOT_OK,
	E_PENDING
	
}Std_ReturnType;




#endif