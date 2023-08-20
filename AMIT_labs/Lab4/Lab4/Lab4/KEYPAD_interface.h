#ifndef _KEYPAD_INTERFACE_H_
#define _KEYPAD_INTERFACE_H_

Std_ReturnType KEYPAD_udtInit(void);
Std_ReturnType KEYPAD_udtGetPressedKey(unit8 * pu8Value);
Std_ReturnType KEYPAD_udtConvertStrToNum(unit8 * pu8Str,unit8 * pu32Value);
#endif