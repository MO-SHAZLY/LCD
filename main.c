/*
 * main.c
 *
 *  Created on: Dec 12, 2020
 *      Author: Al Badr
 */

#include <util/delay.h>
#include "STD_Types.h"
#include "DIO.h"
#include "DIO_reg.h"
#include "BIT_MATH.h"


#include "Seven_Segment.h"
#include "KeyPad.h"
#include "LCD.h"


#define F_CPU 8000000


int main(void)
{
	DIO_Init();
	LCD_Init();

 //uint8 x;

	//LCD_ExtraChar(0,6);
	Gotoxy(1,8);
	//LCD_WriteData('MO');
	LCD_writestring("MO SALAH");
	//LCD_ExtraChar(1,4);

	while(1)
	{
		/* x=DIO_ReadChannel(PORTD1);
		
		if(x==0)
		{
			DIO_WritePort(PORT_A,255);
			_delay_ms(500);
		}
		if (x==1){
			DIO_WritePort(PORT_A,0);

		}
		*/
 /* x=KeyPad_GetPressedKey();
  if(x !=0xFF)
  {
  SEG_Display(x);
  _delay_ms(3000);

  }
  */

 /* SEG_Display(6);
  _delay_ms(5000);
  SEG_Display(5);
  _delay_ms(5000);
*/

	//	LCD_WriteData('B');
//		_delay_ms(800);
		//LCD_writestring("mm ");
		//_delay_ms(300);
	}
	return 0;

}
