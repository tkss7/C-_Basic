#include <iostream>
#include <fstream>
#include <vld.h>


#define ary_size 10
#define name_len 30
#define addr_len 50


using namespace std;

class Employee
{
private:
    char* name;
    int salary;
    char* comAddr;
public:
    Employee(const char* _name, int _salary, const char* _comAddr){
        name = new char[strlen(_name) + 1];
        comAddr = new char[strlen(_comAddr) + 1];
        strcpy(name, _name);
        strcpy(comAddr, _comAddr);
        salary = _salary;
    }
    void show_info(){ cout << "[����: " << name << "] [����: " << salary << "] [ȸ���ּ�: " << comAddr <<"]" << endl; }
    char* getName() { return name; }
    int getSalary() { return salary; }
    char* getComAddr() { return comAddr; }

    ~Employee() 
    {
        delete name;
        delete comAddr;
    }


};

class EmployeeHandler
{
private:
    Employee* empArr[ary_size];
    char tmpName[name_len];
    char tmpAddr[addr_len];
    unsigned int tmpSal, sNum, eNum, i;
public:

    EmployeeHandler() : empArr{}, sNum(0), eNum(0) { }

    void addEmployee() {
        if (sNum == ary_size) {
            cout << "(Error :�Է� ���� �ʰ�)  [ ���� ������ ũ�� : " << ary_size << ",  ���� ����� ũ�� : " << sNum <<" ]"<< endl;
            return;
        }
        
        char tmpName[name_len] ,tmpAddr[addr_len];
        cin.ignore();
        for (i = sNum; i < ary_size; i++)
        {
            printf("���� �Է� [����: end] >> : ");
            cin.getline(tmpName, 30);
            if (!strcmp(strlwr(tmpName), "end")) { break; }

            cout << ("����(salary) >> ");
            cin >> tmpSal;
            cin.ignore();

            cout << ("ȸ���ּ�(comAddr) >> ");
            cin.getline(tmpAddr, 50);

            empArr[i] = new Employee(tmpName, tmpSal, tmpAddr);
        }

        sNum = i;
    }

    void print_info(){
        if (!empArr[0])
            cout << "[ ���� ����� Employee Data�� �����ϴ�. ]" << endl;
        for (int i = 0; i < sNum; i++)
            empArr[i]->show_info();
    }
    void find_info() {

        while (1) {
            cout << ("\n�˻��� ���� �Է� [���� : end] >> ");
            cin >> tmpName;
            if (!strcmp(tmpName, "end")) {
                break;
            }
            int found = 1;
            for (i = 0; i < sNum; i++) {
                if (strcmp(empArr[i]->getName(), tmpName) == 0) {
                    found = 0;
                    empArr[i]->show_info();
                }
            }
            if (found == 1) {
                cout << "\n [ " << tmpName << " Not Found ]" << endl;
            }
        }
    }

    void emp_save() {

        ofstream fout("EmpData.txt");

        if (!fout) {
            cout << "[ EmpData.txt ���� ���� ]" << endl;
            return;
        }

        fout << sNum << endl;

        for (i = 0; i < sNum; i++) {
            fout << empArr[i]->getName() << " ";
            fout << empArr[i]->getSalary() << " ";
            fout << empArr[i]->getComAddr() << endl;
        }      
        eNum = sNum;
        fout.close();
        cout << "[ EmpData.txt Save. ]" << endl;
    }

    void emp_load() {

        ifstream fin("EmpData.txt");

        if (!fin) {
            cout << "[ EmpData.txt load fail ]" << endl;
            return;
        }

        fin >> sNum;
        if (sNum > ary_size) {
            cout << "\n���� load�� Data�� ��������� �ʰ��Ͽ����ϴ�. Data �ս��� �����ϱ� ���� ary_size�� Ȯ�����ּ���." << endl;
            exit(1);
        }

        eNum = sNum;
        for (i = 0; i < sNum; i++) {
            fin >> tmpName; 
            fin >> tmpSal;
            fin >> tmpAddr;
            empArr[i] = new Employee(tmpName, tmpSal, tmpAddr);
        }

        fin.close();
        cout << "[ EmpData.txt loaded ]" << endl;
    }

    void exitProcess() {

        if (sNum != eNum) {
            cout << "���������� ���� �ȵ� ��Ϧ����� " << endl;
            for (i = eNum; i < sNum; i++) 
                empArr[i]->show_info();

            int isSave;
            cout << "\n[ 1:�����ϰ� ���� ] [ 2:�������� �ʰ� ���� ] >> ";
            cin >> isSave;

            if (isSave == 1) { emp_save(); }
            cout << "\n[ ���α׷��� �����մϴ�. ]" << endl;
            return;
        }
    }

    ~EmployeeHandler() { 
        for (i = 0; i < sNum; i++) 
            delete empArr[i]; 
    }
};

int main()
{
    EmployeeHandler empHd;

    empHd.emp_load();

    int choice = 0;
    while (choice!=5) {
        cout << "\n��������������������������������������������������������������������MENU��������������������������������������������������������������������������������������������������������" << endl;
        cout << "[1:EMP�߰�]\t[2:EMP���]\t[3:EMP�˻�]\t[4:EMP����]\t[5:����]\t �Է� >> ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            empHd.addEmployee();
            break;
        case 2:
            empHd.print_info();
            break;
        case 3:
            empHd.find_info();
            break;
        case 4:
            empHd.emp_save();
            break;
        case 5:
            empHd.exitProcess();
            break;
        }
    }
    return 0;
}