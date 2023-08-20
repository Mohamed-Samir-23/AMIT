#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

#define Clear_display	0x01
#define Return_Home		0x02
#define Display_off		0x08
#define Shift_Right		0x1C
#define Shift_left		0x18

typedef enum
{
	LCD_DecimalBase=10,
	LCD_HexaBase=16,
	LCD_OctaBase=8,
	LCD_BinaryBase=2,
}NumberBase;
	
Std_ReturnType LCD_udtInitialized(void);
Std_ReturnType LCD_udtSendData (unit8 u8Data);
Std_ReturnType LCD_udtClear(void);
Std_ReturnType LCD_udtGoTo(unit8 u8X, unit8 u8Y);
Std_ReturnType LCD_udtPrintString(unit8 *str);
Std_ReturnType LCD_udtShiftRight(void);
Std_ReturnType LCD_udtShiftLeft(void);
Std_ReturnType LCD_udtPrintStringAtXY(unit8 *u8str,unit8 u8X, unit8 u8Y);
Std_ReturnType LCD_udtAddSpecialChar(unit8 *u8str, unit8 u8CGRAM_index);
Std_ReturnType LCD_udtPrintSpecialChar(unit8 u8CGRAM_index,unit8 u8X, unit8 u8Y);
Std_ReturnType LCD_DisplayNumber(f64 data,NumberBase Base);
#endif
