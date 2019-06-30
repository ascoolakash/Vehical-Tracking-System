/*
 * vts.c
 *
 *  Created on: Dec 6, 2014
 *      Author: AKASH SAURABH
 */

#include <avr/interrupt.h>
#include <util/delay.h>

char status = 0,index = 0,lat[10] = " ",lon[10] = " ";
char sat[2] = "**",dop[4] = "****",tim[6] = "******";

ISR(USART_RXC_vect)
{
	unsigned char c;
	c = UDR;
	if (c=='$'){status = 1;index = 0;}
	else if((index == 3)&(c != 'G')) status=0;
	else if((index == 4)&(c != 'G')) status=0;
	//else if(index> 6 & index< 13)tim[(index- 7)]=c;
	else if(index>17 & index< 27)lat[(index-18)]=c;
	else if(index>30 & index< 40)lon[(index-31)]=c;
	//else if(index>44 & index< 47)sat[(index-45)]=c;
	//else if(index>46 & index< 51)dop[(index-47)]=c;
	if(status==1)
		index++;
}
int main(void)
{

	//char a[]="",b[]="";
	set_uartbaud(9600);
	enable_uart_rxcint();
	LCDinit();
	LCDclr();
	sei();
	while (1)
	{
		_delay_ms(200);
		LCDGotoXY(0,0);
		LCDstring(lat,10);
		//strcpy_P(a,lat);
		_delay_ms(1000);
		//LCDstring(sat,2);
		//LCDstring(dop,4);
		LCDGotoXY(0,1);
		LCDstring(lon,10);
		//strcpy_P(b,lon);
		_delay_ms(1000);
		//LCDstring(tim,6);
		sendstring_uart("AT+CMGS=\"09641000372\"\r\n");
		_delay_ms(1000);
		sendstring_uart(lat);
		_delay_ms(1000);
		sendstring_uart(lon);
		_delay_ms(1000);
		sendstring_uart(0x1A);
		_delay_ms(1000);
	}
}


