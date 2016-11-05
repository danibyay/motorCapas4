/*
 * StringUtilis.c
 *
 *  Created on: Oct 30, 2016
 *      Author: Jesus Martin, Daniela Becerra
 */
#include "types.h"

#define DECIMAL_TO_ASCII 0x30

bool StringUtils_Str2Num(u8 str[], u8 strSize, u8 decimal, u16* num)
{
	u8 i = 0;
	u8 tempNum;
	u16 accumulatedValue;
	bool validString = M_TRUE; 
	
	
	accumulatedValue = 0;
	
	while (validString && i<strSize)
	{
		if(decimal!=0)
		{
			if(i == (strSize-decimal-1) )
			{
				i++;
			}
		}


		tempNum = str[i] - DECIMAL_TO_ASCII;
		if (tempNum < 0 || tempNum >9)
		{
			return M_FALSE;
		}
		else
		{
			accumulatedValue *= 10;
			accumulatedValue += tempNum;
		}

		i++;
	}
	
	if (validString)
	{
		*num = accumulatedValue;
	}
	
	
	return validString; 
}


void StringUtils_Num2Str(u16 num, u8 string[])
{
	u16 localnum = num; 
	string[3]=0x2E;
	if(localnum<10)
	{
		string[0]=0x30;
		string[1]=0x30;
		string[2]=0x30;
		string[4]= (u8) localnum; //si falla, quitar el cast
	}
	else if(localnum<100)
	{
		string[4]=localnum%10+0x30;
		localnum/=10;
		string[2]=(u8) localnum; //si falla, quitar el cast
		string[1]=0x30;
		string[0]=0x30;
	}
	else if(localnum<1000)
	{
		string[4]=localnum%10+0x30;
		localnum/=10;
		string[2]=localnum%10+0x30;
		localnum/=10;
		string[1]=localnum+0x30;
		string[0]=0x30;
	}
	else
	{
		string[4]=localnum%10+0x30;
		localnum/=10;
		string[2]=localnum%10+0x30;
		localnum/=10;
		string[1]=localnum%10+0x30;
		localnum/=10;
		string[0]=localnum+0x30;
	}
	
}

bool StringUtils_strcmp(u8 * msg,  const u8 ref[], u8 size)
{
	bool isEqual = M_TRUE;
	u8 i;
	
		for(i=0; i<size; i++)
		{
			if(msg[i]==ref[i])
			{
				isEqual = M_TRUE;
			}
			else
			{
				return  M_FALSE;
			}
		}
		return isEqual;
	
}




