#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "KEYPAD_interface.h"

Std_ReturnType KEYPAD_voidInit(void)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	udtReturnType=DIO_udtSetPinDirection(KEYPAD_R0_PIN, DIO_OUTPUT);
	udtReturnType=DIO_udtSetPinDirection(KEYPAD_R1_PIN, DIO_OUTPUT);
	udtReturnType=DIO_udtSetPinDirection(KEYPAD_R2_PIN, DIO_OUTPUT);
	udtReturnType=DIO_udtSetPinDirection(KEYPAD_R3_PIN, DIO_OUTPUT);
	
	
	udtReturnType=DIO_udtSetPinValue(KEYPAD_R0_PIN, DIO_HIGH);
	udtReturnType=DIO_udtSetPinValue(KEYPAD_R1_PIN, DIO_HIGH);
	udtReturnType=DIO_udtSetPinValue(KEYPAD_R2_PIN, DIO_HIGH);
	udtReturnType=DIO_udtSetPinValue(KEYPAD_R3_PIN, DIO_HIGH);
	
	
	udtReturnType=DIO_udtSetPinDirection(KEYPAD_C0_PIN, DIO_INPUT);
	udtReturnType=DIO_udtSetPinDirection(KEYPAD_C1_PIN, DIO_INPUT);
	udtReturnType=DIO_udtSetPinDirection(KEYPAD_C2_PIN, DIO_INPUT);
	udtReturnType=DIO_udtSetPinDirection(KEYPAD_C3_PIN, DIO_INPUT);
	
	
	udtReturnType=DIO_udtSetPinValue(KEYPAD_C0_PIN, DIO_HIGH);
	udtReturnType=DIO_udtSetPinValue(KEYPAD_C1_PIN, DIO_HIGH);
	udtReturnType=DIO_udtSetPinValue(KEYPAD_C2_PIN, DIO_HIGH);
	udtReturnType=DIO_udtSetPinValue(KEYPAD_C3_PIN, DIO_HIGH);
	
	return udtReturnType;
}


Std_ReturnType KEYPAD_u8GetPressedKey(unit8 * pu8Value)
{
	Std_ReturnType udtReturnType=E_NOT_OK;
	*pu8Value=KEYPAD_NOT_PRESSED;
	unit8 u8KeypadMatrix[ROW_NUM][COL_NUM]=KPD_BUTTONS;
	unit8 u8ColumID,u8RowID,u8PinState=0;
	for(u8RowID=0u;u8RowID<ROW_NUM;u8RowID++)
	{
		switch(u8RowID)
		{
			case 0:udtReturnType=DIO_udtSetPinValue(KEYPAD_R0_PIN , DIO_LOW);break;
			case 1:udtReturnType=DIO_udtSetPinValue(KEYPAD_R1_PIN , DIO_LOW);break;
			case 2:udtReturnType=DIO_udtSetPinValue(KEYPAD_R2_PIN , DIO_LOW);break;
			case 3:udtReturnType=DIO_udtSetPinValue(KEYPAD_R3_PIN , DIO_LOW);break;
			default:udtReturnType=E_NOT_OK;break;
		}
		for(u8ColumID=0u;u8ColumID<COL_NUM;u8ColumID++)
		{
			switch(u8ColumID)
			{
				case 0:udtReturnType=DIO_udtGetPinValue(KEYPAD_C0_PIN,&u8PinState);break;
				case 1:udtReturnType=DIO_udtGetPinValue(KEYPAD_C1_PIN,&u8PinState);break;
				case 2:udtReturnType=DIO_udtGetPinValue(KEYPAD_C2_PIN,&u8PinState);break;
				case 3:udtReturnType=DIO_udtGetPinValue(KEYPAD_C3_PIN,&u8PinState);break;
				default:udtReturnType=E_NOT_OK;break;
			}
			if(u8PinState==0)
			{
				*pu8Value= u8KeypadMatrix[u8RowID][u8ColumID];
				break;
			}
			else
			{
				
			}
			
		}
		switch(u8RowID)
		{
			case 0:udtReturnType=DIO_udtSetPinValue(KEYPAD_R0_PIN , DIO_HIGH);break;
			case 1:udtReturnType=DIO_udtSetPinValue(KEYPAD_R1_PIN , DIO_HIGH);break;
			case 2:udtReturnType=DIO_udtSetPinValue(KEYPAD_R2_PIN , DIO_HIGH);break;
			case 3:udtReturnType=DIO_udtSetPinValue(KEYPAD_R3_PIN , DIO_HIGH);break;
			default:udtReturnType=E_NOT_OK;break;
		}
		if(*pu8Value!=KEYPAD_NOT_PRESSED)
		{
			break;
		}
		else
		{
			
		}
	}
	
	return udtReturnType;
	
}