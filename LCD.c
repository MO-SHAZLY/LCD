/*
 * LCD.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Al Badr
 */

#include <util/delay.h>
#define F_CPU 8000000

#include "STD_Types.h"
#include "DIO.h"
#include "DIO_config.h"
#include "LCD_config.h"
#include "LCD.h"


#define ClearDisplay     0x01
#define ReturnHome       0x02
#define EntryModeSet     0x04
#define DisplayOn_OFF    0x0F
#define cursor_shift     0x0A
#define function_set     0x30
#define lcd_DisplayOn    0x0C
#define lcd_FunctionSet8bit 0x38
#define lcd_SetCursor       0x80

#define Enable_Channel         PORTB0
#define RS                     PORTB1
#define ReadWrite              PORTB2

extern const uint8  ExtraChar[];

void LCD_writeCommand(uint8 cmd)
{
	DIO_WriteChannel(Enable_Channel,1);
	DIO_WriteChannel(RS,0);
	DIO_WriteChannel(ReadWrite,0);
	DIO_WritePort(PORT_A,cmd);
	DIO_WriteChannel(Enable_Channel,0);
	_delay_ms(2);
	DIO_WriteChannel(Enable_Channel,1);

}

void LCD_Init(void)
{
	_delay_ms(30);
	LCD_writeCommand(function_set);
	_delay_us(39);
	LCD_writeCommand(DisplayOn_OFF);
	_delay_us(39);
	LCD_writeCommand(ClearDisplay);
	_delay_ms(1.53);
	LCD_writeCommand(EntryModeSet);

}



void LCD_WriteData(uint8 ASCII)
{
	DIO_WriteChannel(Enable_Channel,1);
	DIO_WriteChannel(RS,1);
	DIO_WriteChannel(ReadWrite,0);
	DIO_WritePort(PORT_A,ASCII);
	DIO_WriteChannel(Enable_Channel,0);
	_delay_ms(2);
	DIO_WriteChannel(Enable_Channel,1);
}


void LCD_writestring (uint8 *ptr)
{
	while (*ptr != '\0')
	{
		LCD_WriteData(*ptr);
		ptr++;

	}
}
void Gotoxy (uint8 Y,uint8 X)
{
	if (X>0 && X<=16)
	{
		switch(Y)
		{
		case 1:LCD_writeCommand(X+127);break; // x=col, 0x80=127

		case 2:	LCD_writeCommand(X+191); break; // 191=0xc0
		default:
			break;
		}
	}
}

void LCD_ExtraChar (uint8 Y,uint8 X)
{
	uint8 i,j;


	LCD_writeCommand(64); // 0x40
	for(i=0 ; i<64 ; i++)
	{
		//x = ExtraChar[i];
		LCD_WriteData(ExtraChar[i]);
	}

	LCD_writeCommand(128);
	Gotoxy(Y,X);
	//LCD_WriteData('9');

	for (j=0; j<=7 ; j++) // row =j as 8 row
	{

		LCD_WriteData(j);

		_delay_ms(5);
	}

}


