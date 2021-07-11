/*
 * KeyPad.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Al Badr
 */


#include "STD_Types.h"
#include "DIO_reg.h"
#include "DIO_config.h"
#include "DIO.h"


#define Coloums_Start  0
#define Coloums_End    3
#define Rows_Start     4
#define Rows_End       7



uint8 arr_num[4][4]={{0,4,8,0},{1,5,9,0},{2,6,0,0},{3,7,0,0}};
uint8 arr_Pins[8]={PORTD0,PORTD1,PORTD2,PORTD3,PORTD4,PORTD5,PORTD6,PORTD7};
int i,j;


uint8 KeyPad_GetPressedKey(void)
{
    uint8 check;
    uint8 result = 0xFF;

	DIO_WritePort(PORT_D,255);

	for(i=Coloums_Start;i<=Coloums_End;i++)
	{
		DIO_WriteChannel(arr_Pins[i],0);

        for(j=Rows_Start;j<=Rows_End;j++)
        {
        	check=DIO_ReadChannel(arr_Pins[j]);
        	if(check==0)
        	{
        		result=arr_num[i][j-4];
        	}

        	//while(!(DIO_ReadChannel(arr_Pins[j])));
        }

		DIO_WriteChannel(arr_Pins[i],1);
	}
	return result;
}
