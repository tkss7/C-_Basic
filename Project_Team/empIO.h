#ifndef _emp_header

#include <iostream>
#include <fstream>
#include <vld.h>

#define _emp_header
#define ary_size 10 // line50 : Employee* empAry[ary_size] ��ü ������ �迭�� ������ 

#define name_len 30 // line52 : char tmpName[name_len] - ���� �������� ���� �� �̸��� �Է¹��� �� �ֱ� ������ �����ϱ� ���� ��ũ�� ����� ����
#define addr_len 50 // line53 : char tmpAddr[addr_len] �ӽ÷� �Է¹��� ���ڿ��� ������

using namespace std;

class Employee // Employee class ( �̸�, ����, ȸ���ּҸ� ���� ��ü�� �����ϱ� ���� class)
{
private:
    char* name;
    unsigned int salary;
    char* comAddr;
public:
    // �̸�(���ڿ� ���), ����(�������� ����), ȸ���ּ�(���ڿ� ���) 3���� �Ű����� ���� Employee ������ �Լ� 

    Employee(const char* _name, unsigned int _salary, const char* _comAddr) {
        name = new char[strlen(_name) + 1];  
        comAddr = new char[strlen(_comAddr) + 1]; 

        strcpy(name, _name); 
        strcpy(comAddr, _comAddr); 
        salary = _salary;
    }

    // ���Ŀ� �� function�� �ʿ��� get method ��
    char* getName() { return name; } 
    int getSalary() { return salary; }
    char* getComAddr() { return comAddr; }

    // ��ü �Ҹ�� ȣ��Ǵ� Employee �Ҹ����Լ�  �޸� ����
    ~Employee() {
        delete name;
        delete comAddr;
    }
};

// Employee class ��ü�� ���� ����, ���, File I/O, ���� �� ���ټ��� ���̱� ���� ��ɵ��� ��Ƴ��� class
class EmployeeHandler 
{
private:
    Employee* empAry[ary_size]; // Employee ��ü���� �ּҸ� ������ �� �ִ� ��ü ������ �迭

    char tmpName[name_len]; 
    char tmpAddr[addr_len]; 
    unsigned int tmpSal, endNum, startNum, i; // endNum : ������� �Է¹��� Employee ��ü���� �� / startNum : ���� �� �������� ���� �����͵��� ����ϱ� ���� ����
public:
    EmployeeHandler() : empAry{}, endNum(0), startNum(0) { } // EmployeeHandler ������ �Լ� private ��� ���� �ʱ�ȭ

    void addEmployee(); // �Է�function : Employee ��ü ������ ���� �Է°� �ʱ�ȭ�� ��ü�� empAry[ary_size]�� �־���

    void print_info(); // ���function

    void show_info(int i); // ���function���� ���̴� method : empAry[i]�� ����Ǿ� �ִ� Employee ��ü�� �����͵鿡 ����

    void find_info(); // �˻�function : �̸��� �Է��� �ش� �̸��� ���� Employee ��ü ������ print

    void emp_save(); // ����function : ���� ����� ��ü���� �����͵��� �ؽ�Ʈ �������� ����  ( txtname : EmpData.txt )

    void emp_load(); // load_function : EmpData.txt�� ����Ǿ� �ִ� ���ڿ����� �о�� ������ ������ ����� ��

    void exitProcess(); // ����function : �����ϱ� �� �Էµ� ������ �� �������� ���� �����͵��� �����ְ� ���������� ���� ����

    //��ü �Ҹ�� ȣ��Ǵ� EmployeeHandler �Ҹ����Լ� 
    ~EmployeeHandler() {
        for (i = 0; i < endNum; i++)
            delete empAry[i];
    }
};

#endif