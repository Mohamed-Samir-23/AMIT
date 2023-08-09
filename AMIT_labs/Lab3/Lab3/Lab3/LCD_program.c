#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_interface.h"

#include <util/delay.h>


Std_ReturnType LCD_udtInitialized(void)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	DIO_udtSetPinDirection(LCD_CONTROL_Port,RS,DIO_OUTPUT);
	DIO_udtSetPinDirection(LCD_CONTROL_Port,RW,DIO_OUTPUT);
	DIO_udtSetPinDirection(LCD_CONTROL_Port,E,DIO_OUTPUT);
	#if LCD_MODE == 4
		udtReturnType=DIO_udtSetPinDirection(LCD_Data_Port,LCD_Data_D4,DIO_OUTPUT);
		udtReturnType=DIO_udtSetPinDirection(LCD_Data_Port,LCD_Data_D5,DIO_OUTPUT);
		udtReturnType=DIO_udtSetPinDirection(LCD_Data_Port,LCD_Data_D6,DIO_OUTPUT);
		udtReturnType=DIO_udtSetPinDirection(LCD_Data_Port,LCD_Data_D7,DIO_OUTPUT);
		_delay_ms(15);
		udtReturnType=Send_instruction(0x33);   // Send command 0x33
		udtReturnType=Send_instruction(0x32);   // Send command 0x32
		udtReturnType=Send_instruction(0x28);   // Function set: 4-bit mode, 2 lines, 5x8 font
		udtReturnType=Send_instruction(0x0C);   // Display control: Display ON, Cursor OFF, Blink OFF
		udtReturnType=Send_instruction(0x06);   // Entry mode set: Increment cursor, No shift
		udtReturnType=Send_instruction(0x01);   // Clear display
		_delay_ms(2);   // Delay
		udtReturnType=Send_instruction(0x01);
		udtReturnType=Send_instruction(0x80);
	#elif LCD_MODE == 8
		udtReturnType=DIO_udtSetPortDirection(LCD_Data_Port,0xFF);
		udtReturnType=DIO_udtSetPortValue(LCD_Data_Port,DIO_LOW);
		udtReturnType=Send_instruction(0x33);   // Send command 0x33
		udtReturnType=Send_instruction(0x32);   // Send command 0x32
		udtReturnType=Send_instruction(0x38);	
		_delay_us(50);
		udtReturnType=Send_instruction(0x0C);	
		_delay_us(50);
		udtReturnType=Send_instruction(0x01);
		_delay_ms(2);
		udtReturnType=Send_instruction(0x06);

	#else
		udtReturnType=E_NOT_OK;
	#endif
	
	return udtReturnType;
}



static Std_ReturnType Send_instruction(unit8 instruction)
{
	
	Std_ReturnType udtReturnType=E_NOT_OK;
	
	/*ins will go in instruction register*/
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,RS,DIO_LOW);
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,RW,DIO_LOW);
	#if LCD_MODE == 4
		/*read port*/
		unit8 u8TempPort =0;
		DIO_udtGetPortValue(LCD_Data_Port,&u8TempPort);
		u8TempPort=(u8TempPort&0x0F)|(instruction&0xF0);
		udtReturnType=u8TempPort=DIO_udtSetPortValue(LCD_Data_Port,u8TempPort);
		DIO_udtSetPinValue(LCD_CONTROL_Port,E,DIO_HIGH);
		_delay_us(1);
		udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,E,DIO_LOW);
		_delay_us(200);
		udtReturnType=DIO_udtGetPortValue(LCD_Data_Port,&u8TempPort);
		u8TempPort=(u8TempPort&0x0F)|((instruction<<4));
		u8TempPort=DIO_udtSetPortValue(LCD_Data_Port,u8TempPort);
		udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,E,DIO_HIGH);
		_delay_us(1);
		udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,E,DIO_LOW);
		 _delay_us(2000); // Delay
		
		
	#elif LCD_MODE == 8
	
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,E,DIO_HIGH);
	_delay_ms(1);
	udtReturnType=DIO_udtSetPortValue(LCD_Data_Port,instruction);
	_delay_ms(1);
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,E,DIO_LOW);
	#else
	udtReturnType=E_NOT_OK;
	#endif
	return udtReturnType;
}


Std_ReturnType LCD_udtSendData (unit8 u8Data)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	#if LCD_MODE == 4
	/*ins will go in Data register*/
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,RS,DIO_HIGH);
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,RW,DIO_LOW);
	/*read port and set high nibble*/
	unit8 u8TempPort =0;
	udtReturnType=DIO_udtGetPortValue(LCD_Data_Port,&u8TempPort);
	u8TempPort=(u8TempPort&(0x0F))|(u8Data&(0xF0));
	udtReturnType=DIO_udtSetPortValue(LCD_Data_Port,u8TempPort);
	/*Enable pulse*/
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,E,DIO_HIGH);
	_delay_ms(1);
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,E,DIO_LOW);
	/*read port and shift and set low nibble*/
	udtReturnType=DIO_udtGetPortValue(LCD_Data_Port,&u8TempPort);
	u8TempPort=(u8TempPort&(0x0F))|((u8Data<<4));
	udtReturnType=DIO_udtSetPortValue(LCD_Data_Port,u8TempPort);
	/*Enable pulse*/
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,E,DIO_HIGH);
	_delay_ms(1);
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,E,DIO_LOW);
	_delay_ms(2);
	#elif LCD_MODE == 8
	/*ins will go in Data register*/
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,RS,DIO_HIGH);
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,RW,DIO_LOW);
	_delay_ms(1);
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,E,DIO_HIGH);
	_delay_ms(1);
	udtReturnType=DIO_udtSetPortValue(LCD_Data_Port,u8Data);
	_delay_ms(1);
	udtReturnType=DIO_udtSetPinValue(LCD_CONTROL_Port,E,DIO_LOW);
	#else

	#endif
	return udtReturnType;
}



Std_ReturnType LCD_udtClear(void)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	udtReturnType=Send_instruction(Clear_display); 
	return udtReturnType;
}


Std_ReturnType LCD_udtGoTo(unit8 u8X, unit8 u8Y)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
    unit8 rowOffsets[] = {0x00, 0x40};   // Row offsets for a 2-line LCD (change if using a different size)
    unit8 address = rowOffsets[u8X] + u8Y;  // Calculate the address based on the row and column
    udtReturnType=Send_instruction(0x80 | address);
	return udtReturnType;
}



Std_ReturnType LCD_udtPrintString(unit8 * u8str)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	unit8 u8Counter = 0;
	while(u8str[u8Counter] != '\0')
	{
		udtReturnType=LCD_udtSendData(u8str[u8Counter]);
		u8Counter++;
	}
	return udtReturnType;
}


Std_ReturnType LCD_udtShiftRight(void)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	udtReturnType=Send_instruction(Shift_Right);
	return udtReturnType;
}

Std_ReturnType LCD_udtShiftLeft(void)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	udtReturnType=Send_instruction(Shift_left);
	return udtReturnType;
}


Std_ReturnType LCD_udtPrintStringAtXY(unit8 *u8str,unit8 u8X, unit8 u8Y)
{
	Std_ReturnType udtReturnType=E_NOT_OK;

	LCD_udtGoTo(u8X,u8Y);
	unit8 * ptr=u8str;
	unit8 index =0,line=0;
	while(((*ptr)!='\0')&&((16*u8X)+(index+u8Y))<32)
	{
		if(((16*u8X)+(index+u8Y))<16)
		{

			udtReturnType=LCD_udtSendData(*ptr);
			index++;
			ptr++;
		}
		else if ((((16*u8X)+(index+u8Y))==16)&&line==0)
		{

			udtReturnType=LCD_udtGoTo(1,0);
			line++;
		}
		else if (((16*u8X)+(index+u8Y))<32&&line==1)
		{
			udtReturnType=LCD_udtSendData(*ptr);
			index++;
			ptr++;
		}
		else
		{



		}

	}

	return udtReturnType;
}


Std_ReturnType LCD_udtAddSpecialChar(unit8 *u8str, unit8 u8CGRAM_index)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	unit8 u8address =0;


	if(u8CGRAM_index<8)
	{
		u8address=u8CGRAM_index*8;
		/*0-1-D5-D4-D3-D2-D1-D0 TO GO TO CGRAM D5-D0 LOCATION 0-7*/
		SET_BIT(u8address,6);
		udtReturnType=Send_instruction(u8address);
		unit8 u8i;
		for(u8i=0;u8i<8;u8i++)
		{
			udtReturnType=LCD_udtSendData(u8str[u8i]);
		}
		udtReturnType=Send_instruction(Return_Home);
	}
	else
	{

		udtReturnType=E_NOT_OK;

	}


	return udtReturnType;
}
Std_ReturnType LCD_udtPrintSpecialChar(unit8 u8CGRAM_index,unit8 u8X, unit8 u8Y)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	if(u8CGRAM_index<8)
	{
		udtReturnType=LCD_udtGoTo(u8X,u8Y);
		udtReturnType=LCD_udtSendData(u8CGRAM_index);
	}
	else
	{

		udtReturnType=E_NOT_OK;
	}
	return udtReturnType;
}
