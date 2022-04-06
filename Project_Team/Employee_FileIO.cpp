#include "empIO.h"

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