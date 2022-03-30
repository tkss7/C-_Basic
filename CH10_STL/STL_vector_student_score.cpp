//STL_vector_student_score_����.cpp 03/30
// �ٲٱ� : ctrl + h
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
/*
 vecStudent �ʱ� ��
kim, 80, 65, 99, 244
lee, 90, 65, 74, 229
han, 63, 88, 55, 206
park, 63, 88, 55, 206

���� ��������
kim, 80, 65, 99, 244
lee, 90, 65, 74, 229
han, 63, 88, 55, 206
park, 63, 88, 55, 206

�ְ� ���� ȹ���ڴ� kim : 244
*/
using namespace std;

typedef struct Student
{
    char name[12];
    int  math;
    int  kor;
    int  eng;
    int  sum;
} Stu;

void printMax(vector<Student> vaStu)
{
    int i, index;
    index = 0;
    for (i = 0; i < vaStu.size(); i++)
    {
        if (vaStu[i].sum > vaStu[index].sum)
        {
            index = i;
        }
    }

    printf("\n�ְ� ���� ȹ���ڴ� %s : %d", vaStu[index].name, vaStu[index].sum);
}

bool compare(Student s1, Student s2)
{
    return s1.sum > s2.sum;
}

int main()
{
    Student myinfo;
    vector<Student> vecStudent;

    myinfo.kor = 80;
    myinfo.eng = 65;
    myinfo.math = 90;
    strcpy(myinfo.name, "kim");
    vecStudent.push_back(myinfo);

    myinfo.kor = 90;
    myinfo.eng = 65;
    myinfo.math = 64;
    strcpy(myinfo.name, "lee");
    vecStudent.push_back(myinfo);

    myinfo.kor = 63;
    myinfo.eng = 88;
    myinfo.math = 45;
    strcpy(myinfo.name, "han");
    vecStudent.push_back(myinfo);

    myinfo.kor = 63;
    myinfo.eng = 88;
    myinfo.math = 54;
    strcpy(myinfo.name, "park");
    vecStudent.push_back(myinfo);

    cout << " vecStudent �ʱ� ��" << endl;
    for (int i = 0; i < vecStudent.size(); i++)
    {
         vecStudent[i].sum =  vecStudent[i].kor +  vecStudent[i].eng +  vecStudent[i].math; //�� ����

        cout <<  vecStudent[i].name << ", " <<  vecStudent[i].kor << ", " <<  vecStudent[i].eng // ���
             << ", " <<  vecStudent[i].math << ", " <<  vecStudent[i].sum << endl;
    }


    sort( vecStudent.begin(),  vecStudent.end(), compare);
    cout << "\n���� �������� \n"; // sum ��������
    for (int i = 0; i <  vecStudent.size(); i++)
        cout <<  vecStudent[i].name << ", " <<  vecStudent[i].kor << ", " <<  vecStudent[i].eng
                    << ", " <<  vecStudent[i].math << ", " <<  vecStudent[i].sum <<endl;
 

    printMax(vecStudent);  //�ְ��� index �� Ȯ���Ͽ� ���
}

