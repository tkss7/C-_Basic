#include "empIO.h"


void EmployeeHandler::addEmployee() {
    if (endNum == ary_size) {
        cout << "(Error :�Է� ���� �ʰ�)  [ ���� ������ ũ�� : " << ary_size << ",  ���� ����� ũ�� : " << endNum << " ]" << endl;
        return;
    }

    cin.ignore();
    for (i = endNum; i < ary_size; i++)
    {
        cout << ("���� �Է� [����: end] >> : ");
        cin.getline(tmpName, 30);
        if (!strcmp(strlwr(tmpName), "end")) { break; }

        cout << ("����(salary) >> ");
        cin >> tmpSal;
        cin.ignore();

        cout << ("ȸ���ּ�(comAddr) >> ");
        cin.getline(tmpAddr, 50);

        empAry[i] = new Employee(tmpName, tmpSal, tmpAddr);
    }

    endNum = i;
}

void EmployeeHandler::print_info() {
    if (!empAry[0])
        cout << "[ ���� ����� Employee Data�� �����ϴ�. ]" << endl;
    else {
        for (int i = 0; i < endNum; i++)
            show_info(i);
    }
}

void EmployeeHandler::show_info(int i) {
    cout << "[����: " << empAry[i]->getName() << "][����: " << empAry[i]->getSalary() << "] [ȸ���ּ�: " << empAry[i]->getComAddr() << "]" << endl;
}

void EmployeeHandler::find_info() {
    while (1) {
        cout << ("\n�˻��� ���� �Է� [���� : end] >> ");
        cin >> tmpName;
        if (!strcmp(tmpName, "end")) { break; }
        int found = 1;
        for (i = 0; i < endNum; i++) {
            if (!strcmp(empAry[i]->getName(), tmpName)) {
                found = 0;
                show_info(i);
            }
        }
        if (found == 1) {
            cout << "\n [ " << tmpName << " Not Found ]" << endl;
        }
    }
}

void EmployeeHandler::emp_save() {
    ofstream fout("EmpData.txt");

    if (!fout) {
        cout << "[ EmpData.txt ���� ���� ]" << endl;
        return;
    }

    fout << endNum << endl;

    for (i = 0; i < endNum; i++) {
        fout << empAry[i]->getName() << " ";
        fout << empAry[i]->getSalary() << " ";
        fout << empAry[i]->getComAddr() << endl;
    }
    startNum = endNum;
    fout.close();
    cout << "[ EmpData.txt Save. ]" << endl;
}

void EmployeeHandler::emp_load() {

    ifstream fin("EmpData.txt");

    if (!fin) {
        cout << "[ EmpData.txt load fail ]" << endl;
        return;
    }

    fin >> endNum;
    if (endNum > ary_size) {
        cout << "\n���� load�� Data�� ��������� �ʰ��Ͽ����ϴ�. Data �ս��� �����ϱ� ���� ary_size�� Ȯ�����ּ���." << endl;
        exit(1);
    }

    startNum = endNum;
    for (i = 0; i < endNum; i++) {
        fin >> tmpName;
        fin >> tmpSal;
        fin >> tmpAddr;
        empAry[i] = new Employee(tmpName, tmpSal, tmpAddr);
    }

    fin.close();
    cout << "[ EmpData.txt loaded ]" << endl;
}

void EmployeeHandler::exitProcess() {

    if (startNum != endNum) {
        cout << "���������� ���� �ȵ� ��Ϧ����� " << endl;
        for (i = startNum; i < endNum; i++)
            show_info(i);

        int isSave;
        cout << "\n[ 1:�����ϰ� ���� ] [ 2:�������� �ʰ� ���� ] >> ";
        cin >> isSave;

        if (isSave == 1) { emp_save(); }
        cout << "\n[ ���α׷��� �����մϴ�. ]" << endl;
        return;
    }
}