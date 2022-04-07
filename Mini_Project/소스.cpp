#include <iostream>
#include <fstream>
#include <vld.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <windows.h>
using namespace std;

#define Bhptr_size 100
#define Phptr_size 100
#define bookptr_size 30
#define bookname_len 100
#define authorName_len 100
#define bookNum_len 50 
#define publisher_len 50
#define genre_len 30
#define ID_len 20
#define PW_len 30
#define PASSWORD 1234

class Book
{
protected:
    char bookName[bookname_len];
    char authorName[authorName_len];
    char bookNum[bookNum_len];
    char publisher[publisher_len];
    char genre[genre_len];
    char rental[bookname_len];
    int bookcount = 0;
public:
    Book()
    {
        cout << "Book 빈괄호 생성자 호출" << endl;
        strcpy(bookName, "");
        strcpy(authorName, "");
        strcpy(bookNum, "");
        strcpy(publisher, "");
        strcpy(genre, "");
        strcpy(rental, "");
    }

    Book(const char* _bookName, const char* _authorName, const char* _bookNum, const char* _publisher, const char* _genre, const char* _rental)
    {
        cout << "Book 매개변수 생성자 호출" << endl;
        strcpy(bookName, _bookName);
        strcpy(authorName, _authorName);
        strcpy(bookNum, _bookNum);
        strcpy(publisher, _publisher);
        strcpy(genre, _genre);
        strcpy(rental, _rental);
    }

    ~Book()
    {
        cout << "Book 소멸자 호출" << endl;
    }

    Book* input_BookInfo()             //리턴 타입이 Book 포인터 형인 input 함수 선언
    {
        Book* bookptr = new Book;                 //힙에 자료형이 Book인 메모리 공간을 할당 후 Book포인터 형인 bookptr로 시작주소를 가리킴 

        cout << "도서 이름(입력 종료 : end) : ";
        cin.getline(bookptr->bookName, bookname_len);

        if (strcmp(bookptr->bookName, "end") == 0)   //종료조건
        {
            delete bookptr;
            return nullptr;
        }

        cout << "저자 이름 : ";
        cin.getline(bookptr->authorName, authorName_len);

        cout << "책 일련번호 : ";
        cin.getline(bookptr->bookNum, bookNum_len);

        cout << "출판사 : ";
        cin.getline(bookptr->publisher, publisher_len);

        cout << "장르 : ";
        cin.getline(bookptr->genre, genre_len);

        cout << "대여가능 여부 (가능/불가능) : ";
        cin.getline(bookptr->rental, bookname_len);

        bookcount++;
        while (1)
        {
            if (strcmp(bookptr->rental, "가능") == 0 || strcmp(bookptr->rental, "불가능") == 0)
                return bookptr;

            else
            {
                cout << "가능 또는 불가능 만 입력하세요";
                delete bookptr;
                return nullptr;
            }
        }

    }

    char* get_BookName() { return bookName; }
    char* get_authorName() { return authorName; }
    char* get_bookNum() { return bookNum; }
    char* get_publisher() { return publisher; }
    char* get_genre() { return genre; }
    char* get_rental() { return rental; }
    char* get_return() { return rental; }

    char* get_false_rental(char* _rental)
    {
        char* rental2 = strcpy(_rental, "불가능");
        return rental2;
    }


    char* get_false_return(char* _return)
    {
        char* return2 = strcpy(_return, "가능");
        return return2;
    }

    void show_BookData()
    {
        cout << "도서명 : " << bookName << ", 저자명 : " << authorName << ", 도서 일련번호 : "
            << bookNum << ", 출판사 : " << publisher << ", 장르 : " << genre << ", 대여 가능 여부 : " << rental << endl;
    }
};

class Person
{
protected:
    char ID[ID_len];
    char PW[PW_len];
    char Member_name[20];
    char Member_PhoneNum[30];
public:
    Person()
    {
        cout << "Person 빈괄호 생성자 호출" << endl;
        strcpy(ID, "");
        strcpy(PW, "");
        strcpy(Member_name, "");
        strcpy(Member_PhoneNum, "");
    }

    Person(const char* _ID, const char* _PW, const char* _Member_name, const char* _Member_PhoneNum)
    {
        cout << "Person 매개변수 생성자 호출" << endl;
        strcpy(ID, _ID);
        strcpy(PW, _PW);
        strcpy(Member_name, _Member_name);
        strcpy(Member_PhoneNum, _Member_PhoneNum);
    }

    Person* Input_PersonInfo()
    {
        Person* personptr = new Person;

        cout << "ID : ";
        cin.getline(personptr->ID, ID_len);

        cout << "PASSWARD : ";
        cin.getline(personptr->PW, PW_len);

        cout << "이름 : ";
        cin.getline(personptr->Member_name, 20);

        cout << "전화번호 : ";
        cin.getline(personptr->Member_PhoneNum, 30);

        cout << "회원가입 완료 !" << endl;

        return personptr;
    }

    char* get_ID() { return ID; }
    char* get_PW() { return PW; }
    char* get_MemberName() { return Member_name; }
    char* get_MemberPhoneNum() { return Member_PhoneNum; }

    void Show_MemberData()
    {
        cout << "회원 이름 : " << Member_name << ", 전화번호 : " << Member_PhoneNum << ", ID : "
            << ID << ", PASSWARD : " << Member_PhoneNum << endl;
    }
};


class Handler :public Book, public Person
{
private:
    Book* BHptr[Bhptr_size];
    int Bcount;
    int Pcount;
    Person* PHptr[Phptr_size];

public:
    Handler() :Bcount(0), Pcount(0) { }
    ~Handler()
    {
        for (int i = 0; i < Bcount; i++)
        {
            delete BHptr[i];
            delete PHptr[i];
        }
    }

    void Print_Return_Day()
    {
        SYSTEMTIME systemTime;
        GetLocalTime(&systemTime);

        int y = 0, m = 0, d = 0;
        static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

        y = systemTime.wYear;
        m = systemTime.wMonth;
        d = systemTime.wDay;

        if (y % 4 == 0 && y % 100 != 0)
        {
            days[2] = 29;
        }
        else if (y % 400 == 0)
        {
            days[2] = 29;
        }

        d += 7;
        if (d > days[m])
        {
            d -= days[m];

            m++;
            if (m == 13)
            {
                m = 1;
                y++;
            }
        }
        cout << y << "년, " << m << "월, " << d << "일까지 반납해 주세요." << endl;

        if (days[2] == 29)
        {
            days[2] = 28;
        }

    }

    void Rental_Book()
    {
        int i, found;
        char s_name[bookname_len], * getname, * getrental;
        SYSTEMTIME systemTime;
        GetLocalTime(&systemTime);

        cout << "대출할 책 이름 : ";
        cin.getline(s_name, bookname_len);

        found = 1;
        for (i = 0; i < Bcount; i++)
        {
            getname = BHptr[i]->get_BookName();
            if (strcmp(getname, s_name) == 0)
            {
                found = 0;
                getrental = BHptr[i]->get_rental();

                cout << "현재 대여 가능 여부 : " << getrental << endl;
                if (strcmp(getrental, "가능") == 0)
                {
                    int answer;
                    cout << " 대여하시겠습니까? (1.예/2.아니오) : " << endl;
                    cin >> answer;
                    if (answer == 1)
                    {
                        cout << "대여일시: " << systemTime.wYear << "년, " << systemTime.wMonth << "월, " << systemTime.wDay << "일" << endl;
                        cout << "대여가 완료 되었습니다. " << endl;

                        Print_Return_Day();

                        get_false_rental(getrental);
                        save_bookData();
                        Save_bookTxt();
                    }
                    else if (answer == 2)
                        break;
                }
                else
                    cout << "대여가 불가능 합니다." << endl;
            }
        }

        if (found)
            cout << s_name << ", Not found !!! " << endl;
    }



    void Return_Book()
    {
        int i, found;
        char s_name[bookname_len], * getname, * getreturn;
        SYSTEMTIME systemTime;
        GetLocalTime(&systemTime);

        cout << "반납할 책 이름 : ";
        cin.getline(s_name, bookname_len);

        found = 1;
        for (i = 0; i < Bcount; i++)
        {

            getname = BHptr[i]->get_BookName();
            if (strcmp(getname, s_name) == 0)
            {
                found = 0;
                getreturn = BHptr[i]->get_return();
                cout << "<반납 가능 여부>" << endl;
                if (strcmp(getreturn, "불가능") == 0)
                {
                    int answer;
                    cout << " 반납이 가능합니다. 빈납하시겠습니까? (1.예/2.아니오) : " << endl;
                    cin >> answer;
                    if (answer == 1)
                    {
                        cout << "반납이 완료 되었습니다. " << endl;


                        cout << "반납일시: " << systemTime.wYear << "년, " << systemTime.wMonth << "월, " << systemTime.wDay << "일" << endl;

                        get_false_return(getreturn);
                        save_bookData();
                        Save_bookTxt();
                    }
                    else if (answer == 2)
                        break;
                }
                else
                    cout << "반납이 불가능 합니다." << endl;

            }
        }
        if (found)
            cout << s_name << ", Not found !!! " << endl;
    }

    void add_Book()
    {
        int i;
        for (i = Bcount; i < Bhptr_size; i++)
        {
            BHptr[i] = input_BookInfo();               //데이터를 삽입한 Book의 객체 bookptr의 시작주소를 hptr의 i번째 배열에 반환
            if (BHptr[i] == nullptr)                       //hptr->bookptr->힙에 할당된 Class메모리(데이터를 가진)
                break;
        }
        Bcount = i;
    }

    void Delete_Book()
    {
        char s_name[bookname_len], * getname;
        int i, found, index = 0;
        while (1)
        {
            cout << "삭제할 도서 이름 (삭제 종료 : end) : ";
            cin.getline(s_name, bookname_len);

            if (strcmp(s_name, "end") == 0)
                break;

            found = 1;

            for (i = 0; i < Bcount; i++)
            {
                getname = BHptr[i]->get_BookName();           //count번째까지 입력된 모든 bookName을 pntf에 저장

                if (strcmp(getname, s_name) == 0)
                {
                    found = 0;
                    BHptr[i]->show_BookData();
                    index = i;

                    BHptr[index] = BHptr[index + 1];

                }
            }

            if (found)
            {
                cout << s_name << " 라는 이름의 책은 없음" << endl;
                break;
            }
            Bcount--;
        }

    }

    void Check_Management()
    {
        int password = 0;
        cout << "관리자 비밀번호를 입력하세요 >>";
        cin >> password;

        if (password == PASSWORD)
            Management_mode();
        else
            cout << "틀렸습니다. 관리자모드에 접근할 수 없습니다. " << endl;
    }

    void Management_mode()
    {
        int choice, stop = 1;
        while (stop)
        {
            cout << "\n1. 신간 도서 추가 \n";
            cout << "2. 도서 삭제 \n";
            cout << "3. 도서 정보 변경사항 저장 \n";
            cout << "4. 회원 명단 출력\n";
            cout << "5. 회원 정보 검색\n";
            cout << "6. 회원 정보 삭제\n";
            cout << "7. 회원 정보 변경사항 저장 \n";
            cout << "8. 메인화면으로 돌아가기\n ";
            cout << "Select ? (1~8) ";
            cin >> choice;
            cin.ignore(1, '\n');

            switch (choice)
            {
            case 1: add_Book();
                break;
            case 2: Delete_Book();
                break;
            case 3: save_bookData();
                Save_bookTxt();
                break;
            case 4: Output_MemberData();
            case 5: Find_Member();
                break;
            case 6: Delete_Member();
                break;
            case 7: Save_MemberData();
                Save_bookTxt();
                break;
            case 8: stop = 0;
                break;
            }
        }
    }

    void Output_BookData()
    {
        cout << "현재 있는 책 개수 : " << Bcount << endl;
        cout << "===============책 목록================ " << endl;

        for (int i = 0; i < Bcount; i++)
        {
            BHptr[i]->show_BookData();
        }
    }

    void Find_Book()
    {
        char s_name[bookname_len], * getname;
        int i, found;
        while (1)
        {
            cout << "검색할 책 이름 (검색 종료 : end) : ";
            cin.getline(s_name, bookname_len);

            if (strcmp(s_name, "end") == 0)
                break;

            found = 1;

            for (i = 0; i < Bcount; i++)
            {
                getname = BHptr[i]->get_BookName();           //count번째까지 입력된 모든 bookName을 pntf에 저장

                if (strcmp(getname, s_name) == 0)
                {
                    found = 0;
                    BHptr[i]->show_BookData();
                }
            }
            if (found)
                cout << s_name << " 라는 이름의 책은 없음" << endl;
        }
    }

    void Save_bookTxt()
    {
        const char* file = "Library.txt";
        ofstream fout(file, ios::out);

        if (!fout)
        {
            cout << "Library.txt 파일을 열 수 없음";
            return;
        }

        fout << Bcount << endl;                      //파일에 count 값 저장
        for (int i = 0; i < Bcount; i++)                   //0부터 count번째만큼 (즉 입력된 유효반복횟수만큼) 파일에 각각의 데이터 저장
        {
            fout << BHptr[i]->get_BookName() << " ";
            fout << BHptr[i]->get_authorName() << " ";
            fout << BHptr[i]->get_bookNum() << " ";
            fout << BHptr[i]->get_publisher() << " ";
            fout << BHptr[i]->get_genre() << " ";
            fout << BHptr[i]->get_rental() << endl;

        }
        fout.close();
        cout << "[ Library.txt에 저장 완료 ]" << endl;
    }

    void save_bookData() //이진파일로
    {
        const char* file = "book.dat";

        ofstream fout;
        fout.open(file, ios::out | ios::binary);

        if (!fout)
        {
            cout << "book.dat 파일 열기 오류";
            return;
        }

        fout.write((char*)&Bcount, sizeof(Bcount));
        for (int i = 0; i < Bcount; i++)
            fout.write((char*)(BHptr[i]), sizeof(Book));

        fout.close();

        printf("[ book.dat에 저장 완료 ] !!! \n");
    }

    void load_bookData()
    {

        const char* file = "book.dat";
        Book* ptr;

        ifstream fin;
        fin.open(file, ios::in | ios::binary);


        if (!fin)
        {
            cout << "loadBook() 파일 열기 오류";
            return;
        }

        fin.read((char*)&Bcount, sizeof(Bcount));

        for (int i = 0; i < Bcount; i++)
        {
            BHptr[i] = new Book;
            fin.read((char*)BHptr[i], sizeof(Book));
        }

        fin.close();

        cout << "book.dat Load \n";

    }

    void MainMenu()
    {
        int choice, stop = 1;
        while (stop)
        {
            cout << "\n1. 전체 도서 목록 \n";
            cout << "2. 도서 검색 \n";
            cout << "3. 도서 대여 \n";
            cout << "4. 도서 반납 \n";
            cout << "5. 관리자 모드 \n";
            cout << "6. 프로그램 종료 \n";
            cout << "Select ? (1~6) ";
            cin >> choice;
            cin.ignore(1);

            switch (choice)
            {
            case 1: Output_BookData();
                break;
            case 2: Find_Book();
                break;
            case 3: Rental_Book();
                break;
            case 4: Return_Book();
                break;
            case 5: Check_Management();
                break;
            case 6: exit(1);
                break;
            }

        } //while(그만) end
    }

    void Output_MemberData()
    {
        cout << "도서관 총 회원 수 : " << Pcount << endl;
        cout << "===============회원 명단================ " << endl;

        for (int i = 0; i < Pcount; i++)
        {
            PHptr[i]->Show_MemberData();
        }
    }

    void Find_Member()
    {
        char s_name[20], * getname;
        int i, found;
        while (1)
        {
            cout << "회원 이름 (검색 종료 : end) : ";
            cin.getline(s_name, 20);

            if (strcmp(s_name, "end") == 0)
                break;

            found = 1;

            for (i = 0; i < Pcount; i++)
            {
                getname = PHptr[i]->get_MemberName();           //count번째까지 입력된 모든 bookName을 pntf에 저장

                if (strcmp(getname, s_name) == 0)
                {
                    found = 0;
                    PHptr[i]->Show_MemberData();
                }
            }
            if (found)
            {
                cout << "[" << s_name << "]" << " 회원은 없습니다" << endl;
                break;
            }
        }
    }



    void Login()
    {
        char s_id[ID_len], s_pw[PW_len], * getid, * getpw;
        int i, found;
        while (1)
        {
            cout << "======================= 회원정보를 입력하세요. ======================= " << endl;
            cout << "                    iD >> ";
            cin.getline(s_id, ID_len);

            cout << "                    PASSWARD >> ";
            cin.getline(s_pw, PW_len);


            if (strcmp(s_id, "end") == 0)
                break;

            found = 1;

            for (i = 0; i < Pcount; i++)
            {
                getid = PHptr[i]->get_ID();           //count2번째까지 입력된 모든 ID를 getid에 저장
                getpw = PHptr[i]->get_PW();

                if (strcmp(getid, s_id) == 0)
                {
                    if (strcmp(getpw, s_pw) == 0)
                        MainMenu();
                    else
                    {
                        cout << "비밀번호가 틀립니다. 다시 입력하세요." << endl;
                        break;
                    }
                    found = 0;
                }
            }
            if (found)
            {
                cout << s_id << "존재하지 않는 ID입니다. 메인 메뉴로 돌아가 회원가입을 하세요" << endl;
                break;
            }
        }
    }

    void Sign_Up()
    {
        int i;
        for (i = Pcount; i < Pcount + 1; i++)
        {
            PHptr[i] = Input_PersonInfo();

            if (PHptr[i] == nullptr)
                break;
        }
        Pcount = i;
    }

    void Delete_Member()
    {
        char s_name[20], * getname;
        int i, found, index = 0;
        while (1)
        {
            cout << "삭제할 회원 이름 (삭제 종료 : end) : ";
            cin.getline(s_name, 20);

            if (strcmp(s_name, "end") == 0)
                break;

            found = 1;

            for (i = 0; i < Pcount; i++)
            {
                getname = PHptr[i]->get_MemberName();

                if (strcmp(getname, s_name) == 0)
                {
                    found = 0;
                    PHptr[i]->Show_MemberData();
                    index = i;

                    PHptr[index] = PHptr[index + 1];

                }
            }

            if (found)
            {
                cout << "[" << s_name << "]" << " 회원은 없습니다" << endl;
                break;
            }
            Pcount--;
        }

    }

    void Save_MemberTxt()
    {
        const char* file = "Member.txt";
        ofstream fout(file, ios::out);

        if (!fout)
        {
            cout << "Member.txt 파일을 열 수 없음";
            return;
        }

        fout << Bcount << endl;                      //파일에 count 값 저장
        for (int i = 0; i < Pcount; i++)                   //0부터 count번째만큼 (즉 입력된 유효반복횟수만큼) 파일에 각각의 데이터 저장
        {
            fout << PHptr[i]->get_ID() << " ";
            fout << PHptr[i]->get_PW() << " ";


        }
        fout.close();
        cout << "[ Member.txt에 저장 완료 ]" << endl;
    }

    void Save_MemberData() //이진파일로
    {
        const char* file = "Member.dat";

        ofstream fout;
        fout.open(file, ios::out | ios::binary);

        if (!fout)
        {
            cout << "Member.dat 파일 열기 오류";
            return;
        }

        fout.write((char*)&Bcount, sizeof(Bcount));
        for (int i = 0; i < Pcount; i++)
            fout.write((char*)(PHptr[i]), sizeof(Person));

        fout.close();

        printf("[ Member.dat에 저장 완료 ] !!! \n");
    }

    void load_MemberData()
    {

        const char* file = "Member.dat";
        Person* ptr;

        ifstream fin;
        fin.open(file, ios::in | ios::binary);


        if (!fin)
        {
            cout << "load_MemberData() 파일 열기 오류";
            return;
        }

        fin.read((char*)&Bcount, sizeof(Bcount));

        for (int i = 0; i < Pcount; i++)
        {
            PHptr[i] = new Person;
            fin.read((char*)PHptr[i], sizeof(Person));
        }

        fin.close();

        cout << "book.dat Load \n";

    }


};

int main()
{
    Handler lib;

    lib.load_bookData();

    int choice, stop = 1;
    while (stop)
    {
        cout << "===================== ㅁㅁ 도서관에 오신것을 환영합니다. ===================== " << endl;
        cout << "\n1. 로그인 \n";
        cout << "2. 회원가입 \n";
        cout << "3. 프로그램 종료\n";
        cin >> choice;
        cin.ignore(1, '\n');

        switch (choice)
        {
        case 1: lib.Login();
            break;
        case 2: lib.Sign_Up();
            break;
        case 3: stop = 0;
            break;
        }
    }
    printf("End. \n");

    return 0;
}