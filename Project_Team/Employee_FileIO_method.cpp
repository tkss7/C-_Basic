#include "empIO.h"


void EmployeeHandler::addEmployee() {
    if (endNum == ary_size) {
        cout << "(Error :입력 공간 초과)  [ 저장 가능한 크기 : " << ary_size << ",  현재 저장된 크기 : " << endNum << " ]" << endl;
        return;
    }

    cin.ignore();
    for (i = endNum; i < ary_size; i++)
    {
        cout << ("성명 입력 [종료: end] >> : ");
        cin.getline(tmpName, 30);
        if (!strcmp(strlwr(tmpName), "end")) { break; }

        cout << ("월급(salary) >> ");
        cin >> tmpSal;
        cin.ignore();

        cout << ("회사주소(comAddr) >> ");
        cin.getline(tmpAddr, 50);

        empAry[i] = new Employee(tmpName, tmpSal, tmpAddr);
    }

    endNum = i;
}

void EmployeeHandler::print_info() {
    if (!empAry[0])
        cout << "[ 현재 저장된 Employee Data가 없습니다. ]" << endl;
    else {
        for (int i = 0; i < endNum; i++)
            show_info(i);
    }
}

void EmployeeHandler::show_info(int i) {
    cout << "[성명: " << empAry[i]->getName() << "][월급: " << empAry[i]->getSalary() << "] [회사주소: " << empAry[i]->getComAddr() << "]" << endl;
}

void EmployeeHandler::find_info() {
    while (1) {
        cout << ("\n검색할 성명 입력 [종료 : end] >> ");
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
        cout << "[ EmpData.txt 열기 실패 ]" << endl;
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
        cout << "\n현재 load할 Data가 저장공간을 초과하였습니다. Data 손실을 방지하기 위해 ary_size를 확장해주세요." << endl;
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
        cout << "───현재 저장 안된 목록─── " << endl;
        for (i = startNum; i < endNum; i++)
            show_info(i);

        int isSave;
        cout << "\n[ 1:저장하고 종료 ] [ 2:저장하지 않고 종료 ] >> ";
        cin >> isSave;

        if (isSave == 1) { emp_save(); }
        cout << "\n[ 프로그램을 종료합니다. ]" << endl;
        return;
    }
}