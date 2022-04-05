#ifndef _emp_header

#include <iostream>
#include <fstream>
#include <vld.h>

#define _emp_header
#define ary_size 10 // line50 : Employee* empAry[ary_size] 객체 포인터 배열의 사이즈 

#define name_len 30 // line52 : char tmpName[name_len] - 가끔 생각지도 못한 긴 이름을 입력받을 수 있기 때문에 접근하기 쉽게 매크로 상수로 선언
#define addr_len 50 // line53 : char tmpAddr[addr_len] 임시로 입력받을 문자열의 사이즈

using namespace std;

class Employee // Employee class ( 이름, 월급, 회사주소를 갖는 객체를 생성하기 위한 class)
{
private:
    char* name;
    unsigned int salary;
    char* comAddr;
public:
    // 이름(문자열 상수), 월급(음수없는 정수), 회사주소(문자열 상수) 3개의 매개변수 갖는 Employee 생성자 함수 

    Employee(const char* _name, unsigned int _salary, const char* _comAddr) {
        name = new char[strlen(_name) + 1];  
        comAddr = new char[strlen(_comAddr) + 1]; 

        strcpy(name, _name); 
        strcpy(comAddr, _comAddr); 
        salary = _salary;
    }

    // 이후에 쓸 function에 필요한 get method 들
    char* getName() { return name; } 
    int getSalary() { return salary; }
    char* getComAddr() { return comAddr; }

    // 객체 소멸시 호출되는 Employee 소멸자함수  메모리 해제
    ~Employee() {
        delete name;
        delete comAddr;
    }
};

// Employee class 객체에 대해 생성, 출력, File I/O, 종료 등 접근성을 높이기 위해 기능들을 모아놓은 class
class EmployeeHandler 
{
private:
    Employee* empAry[ary_size]; // Employee 객체들의 주소를 저장할 수 있는 객체 포인터 배열

    char tmpName[name_len]; 
    char tmpAddr[addr_len]; 
    unsigned int tmpSal, endNum, startNum, i; // endNum : 현재까지 입력받은 Employee 객체들의 수 / startNum : 종료 시 저장하지 않은 데이터들을 출력하기 위한 변수
public:
    EmployeeHandler() : empAry{}, endNum(0), startNum(0) { } // EmployeeHandler 생성자 함수 private 멤버 변수 초기화

    void addEmployee(); // 입력function : Employee 객체 생성을 위한 입력과 초기화된 객체를 empAry[ary_size]에 넣어줌

    void print_info(); // 출력function

    void show_info(int i); // 출력function에서 쓰이는 method : empAry[i]로 저장되어 있는 Employee 객체의 데이터들에 접근

    void find_info(); // 검색function : 이름을 입력해 해당 이름을 가진 Employee 객체 데이터 print

    void emp_save(); // 저장function : 현재 저장된 객체들의 데이터들을 텍스트 형식으로 저장  ( txtname : EmpData.txt )

    void emp_load(); // load_function : EmpData.txt에 저장되어 있는 문자열들을 읽어와 동일한 구조로 만들어 줌

    void exitProcess(); // 종료function : 종료하기 전 입력된 데이터 중 저장하지 않은 데이터들을 보여주고 저장유무를 묻고 종료

    //객체 소멸시 호출되는 EmployeeHandler 소멸자함수 
    ~EmployeeHandler() {
        for (i = 0; i < endNum; i++)
            delete empAry[i];
    }
};

#endif