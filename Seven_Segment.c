/*
 * Seven_Segment.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Al Badr
 */

#include "STD_Types.h"
#include "DIO_reg.h"
#include "DIO.h"
#include "Seven_Segment.h"
#include "DIO_config.h"



void SEG_Display(uint8 seg_number)
{
	switch(seg_number)
	{
	case 0:DIO_WritePort(PORT_A,ZERO); break;
	case 1:DIO_WritePort(PORT_A,ONE);  break;
	case 2:DIO_WritePort(PORT_A,TWO);  break;
	case 3:DIO_WritePort(PORT_A,THREE);break;
	case 4:DIO_WritePort(PORT_A,FOUR); break;
	case 5:DIO_WritePort(PORT_A,FIVE); break;
	case 6:DIO_WritePort(PORT_A,SIX);  break;
	case 7:DIO_WritePort(PORT_A,SEVEN);break;
	case 8:DIO_WritePort(PORT_A,EIGHT);break;
	case 9:DIO_WritePort(PORT_A,NINE) ;break;
	default:break;

	}
}


