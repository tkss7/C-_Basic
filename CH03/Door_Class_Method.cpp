//Door_Class_Method.cpp 03/18
#include <iostream> 
#include"Door.h"
#include"Door.h"
using namespace std;


void Door::Close()
{
    state = CLOSE;
}
void Door::ShowState()
{
    cout << "현재 문의 상태 : ";
    cout << ((state == OPEN) ? "OPEN" : "CLOSE") << endl;
}