/*
 * LCD.h
 *
 *  Created on: Dec 25, 2020
 *      Author: Al Badr
 */

#ifndef LCD_H_
#define LCD_H_


extern void LCD_writeCommand(uint8 cmd);
extern void LCD_Init(void);

extern void LCD_WriteData(uint8 ASCII);
extern void LCD_writestring (uint8 *ptr);

extern void Gotoxy (uint8 Y,uint8 X);
//extern void LCD_ExtraChar (uint8 Y,uint8 X);
void LCD_WriteCharctr (uint8 Data);

extern void LCD_ExtraChar (uint8 Y,uint8 X);

#endif /* LCD_H_ */
