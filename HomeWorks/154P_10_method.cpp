#include<iostream>
#include"154P_10.h"

void Add::setValue(int x, int y)
{
	a = x;
	b = y;
}
int Add::calculate()
{
	return a + b;
} //Add end.

void Sub::setValue(int x, int y)
{
	a = x;
	b = y;
}
int Sub::calculate()
{
	return a - b;
}// Sub end.

void Mul::setValue(int x, int y)
{
	a = x;
	b = y;
}
int Mul::calculate()
{
	return a * b;
} // Mul end.

void Div::setValue(int x, int y)
{
	a = x;
	b = y;
}
int Div::calculate()
{
	return a / b;
} //Div end.