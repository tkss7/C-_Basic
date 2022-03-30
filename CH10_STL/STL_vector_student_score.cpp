//STL_vector_student_score_문제.cpp 03/30
// 바꾸기 : ctrl + h
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
/*
 vecStudent 초기 값
kim, 80, 65, 99, 244
lee, 90, 65, 74, 229
han, 63, 88, 55, 206
park, 63, 88, 55, 206

성적 내림차순
kim, 80, 65, 99, 244
lee, 90, 65, 74, 229
han, 63, 88, 55, 206
park, 63, 88, 55, 206

최고 점수 획득자는 kim : 244
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

    printf("\n최고 점수 획득자는 %s : %d", vaStu[index].name, vaStu[index].sum);
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

    cout << " vecStudent 초기 값" << endl;
    for (int i = 0; i < vecStudent.size(); i++)
    {
         vecStudent[i].sum =  vecStudent[i].kor +  vecStudent[i].eng +  vecStudent[i].math; //합 구함

        cout <<  vecStudent[i].name << ", " <<  vecStudent[i].kor << ", " <<  vecStudent[i].eng // 출력
             << ", " <<  vecStudent[i].math << ", " <<  vecStudent[i].sum << endl;
    }


    sort( vecStudent.begin(),  vecStudent.end(), compare);
    cout << "\n성적 내림차순 \n"; // sum 기준으로
    for (int i = 0; i <  vecStudent.size(); i++)
        cout <<  vecStudent[i].name << ", " <<  vecStudent[i].kor << ", " <<  vecStudent[i].eng
                    << ", " <<  vecStudent[i].math << ", " <<  vecStudent[i].sum <<endl;
 

    printMax(vecStudent);  //최고성적 index 를 확인하여 출력
}

