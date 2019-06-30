#include<avr/io.h>
#include<avr/interrupt.h>


void enable_INT0(int i);//0-low level,1-any logic change,2-falling edge,3-rising egde

void enable_INT1(int i);//0-low level,1-any logic change,2-falling edge,3-rising egde

void enable_INT0(int i);//0-falling edge,1-rising egde

void disable_INT0();

void disable_INT1();

void disable_INT2();
