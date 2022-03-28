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
    void show_info(){ cout << "[성명: " << name << "] [월급: " << salary << "] [회사주소: " << comAddr <<"]" << endl; }
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
            cout << "(Error :입력 공간 초과)  [ 저장 가능한 크기 : " << ary_size << ",  현재 저장된 크기 : " << sNum <<" ]"<< endl;
            return;
        }
        
        char tmpName[name_len] ,tmpAddr[addr_len];
        cin.ignore();
        for (i = sNum; i < ary_size; i++)
        {
            printf("성명 입력 [종료: end] >> : ");
            cin.getline(tmpName, 30);
            if (!strcmp(strlwr(tmpName), "end")) { break; }

            cout << ("월급(salary) >> ");
            cin >> tmpSal;
            cin.ignore();

            cout << ("회사주소(comAddr) >> ");
            cin.getline(tmpAddr, 50);

            empArr[i] = new Employee(tmpName, tmpSal, tmpAddr);
        }

        sNum = i;
    }

    void print_info(){
        if (!empArr[0])
            cout << "[ 현재 저장된 Employee Data가 없습니다. ]" << endl;
        for (int i = 0; i < sNum; i++)
            empArr[i]->show_info();
    }
    void find_info() {

        while (1) {
            cout << ("\n검색할 성명 입력 [종료 : end] >> ");
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
            cout << "[ EmpData.txt 열기 실패 ]" << endl;
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
            cout << "\n현재 load할 Data가 저장공간을 초과하였습니다. Data 손실을 방지하기 위해 ary_size를 확장해주세요." << endl;
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
            cout << "───현재 저장 안된 목록─── " << endl;
            for (i = eNum; i < sNum; i++) 
                empArr[i]->show_info();

            int isSave;
            cout << "\n[ 1:저장하고 종료 ] [ 2:저장하지 않고 종료 ] >> ";
            cin >> isSave;

            if (isSave == 1) { emp_save(); }
            cout << "\n[ 프로그램을 종료합니다. ]" << endl;
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
        cout << "\n──────────────────────────────────MENU────────────────────────────────────────────────────" << endl;
        cout << "[1:EMP추가]\t[2:EMP출력]\t[3:EMP검색]\t[4:EMP저장]\t[5:종료]\t 입력 >> ";
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