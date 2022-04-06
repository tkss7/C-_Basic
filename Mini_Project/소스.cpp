#include <iostream>
#include <fstream>
#include <vld.h>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define hptr_size 100
#define bookptr_size 30
#define bookname_len 100
#define authorName_len 100
#define bookNum_len 50 
#define publisher_len 50
#define genre_len 30

class Book
{
protected:
    char bookName[bookname_len];
    char authorName[authorName_len];
    char bookNum[bookNum_len];
    char publisher[publisher_len];
    char genre[genre_len];
    char rental[bookname_len];
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

        cout << "책 이름 : (입력 종료 : end)";
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

        return bookptr;

    }

    char* get_bookName() { return bookName; }
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

    const char* currentDateTime()
    {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

        return buf;
    }

    char* get_false_return(char* _return)
    {
        char* return2 = strcpy(_return, "가능");
        return return2;
    }

    void show_bookData()
    {
        cout << "도서명 : " << bookName << ", 저자명 : " << authorName << ", 도서 일련번호 : "
            << bookNum << ", 출판사 : " << publisher << ", 장르 : " << genre << ", 대여 가능 여부 : " << rental << endl;
    }
};

class BookHandler :public Book
{
private:
    Book* hptr[hptr_size];
    int count;

public:
    BookHandler() :count(0) {}
    ~BookHandler() {}

    void Rental_Book()
    {
        int i, found;
        char s_name[bookname_len], * getname, * getrental;
        cout << "대출할 책 이름 : ";
        cin.getline(s_name, bookname_len);

        found = 1;
        for (i = 0; i < count; i++)
        {
            getname = hptr[i]->get_bookName();
            if (strcmp(getname, s_name) == 0)
            {
                found = 0;
                getrental = hptr[i]->get_rental();

                cout << "현재 대여 가능 여부 : " << getrental << endl;
                if (strcmp(getrental, "가능") == 0)
                {
                    int answer;
                    cout << " 대여하시겠습니까? (1.예/2.아니오) : " << endl;
                    cin >> answer;
                    if (answer == 1)
                    {
                        cout << "대여가 완료 되었습니다. " << endl;
                        get_false_rental(getrental);
                        save_bookData();
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
        cout << "반납할 책 이름 : ";
        cin.getline(s_name, bookname_len);

        found = 1;
        for (i = 0; i < count; i++)
        {

            getname = hptr[i]->get_bookName();
            if (strcmp(getname, s_name) == 0)
            {
                found = 0;
                getreturn = hptr[i]->get_return();
                cout << "<반납 가능 여부>" << endl;
                if (strcmp(getreturn, "불가능") == 0)
                {
                    int answer;
                    cout << " 반납이 가능합니다. 빈납하시겠습니까? (1.예/2.아니오) : " << endl;
                    cin >> answer;
                    if (answer == 1)
                    {
                        cout << "반납이 완료 되었습니다. " << endl;
                        get_false_return(getreturn);
                        save_bookData();
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
        for (i = count; i < hptr_size; i++)
        {
            hptr[i] = input_BookInfo();               //데이터를 삽입한 Book의 객체 bookptr의 시작주소를 hptr의 i번째 배열에 반환
            if (hptr[i] == nullptr)                       //hptr->bookptr->힙에 할당된 Class메모리(데이터를 가진)
                break;
        }
        count = i;
    }

    void delete_book()
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

            for (i = 0; i < count; i++)
            {
                getname = hptr[i]->get_bookName();           //count번째까지 입력된 모든 bookName을 pntf에 저장

                if (strcmp(getname, s_name) == 0)
                {
                    found = 0;
                    hptr[i]->show_bookData();
                    index = i;
                }
            }

            if (found)
                cout << s_name << " 라는 이름의 책은 없음" << endl;

            for (int j = index; j < count; j++)
            {
                hptr[j] = hptr[j + 1];
            }
            count--;
        }
        /*cout << "삭제할 도서의 일련변호 입력 : ";
        cin.getline(delNum, bookNum_len);

        for (int i = 0; i < count; i++)
        {
           if (strcmp(delNum, hptr[i]->get_bookNum()) == 0)
           {
              hptr[i] = NULL;
              cout << "삭제를 완료했습니다.";
           }
        }
        */
    }

    void Management_mode()
    {
        int choice, stop = 1;
        while (그만)
        {
            cout << "\n1. 신간 도서 추가 \n";
            cout << "2. 도서 삭제 \n";
            cout << "3. 도서 변경사항 저장 \n";
            cout << "4. end \n";
            cin >> choice;  //1, 2, 3, 7, 1, 4
            cin.ignore(1, '\n');

            switch (choice)
            {
            case 1: add_Book();
                break;
            case 2: delete_book();
                break;
            case 3: save_bookData();
                break;
            case 4: stop = 0;
                break;
            }
        }
    }

    void Output()
    {
        cout << "현재 있는 책 개수 : " << count << endl;
        cout << "===============책 목록================ " << endl;

        for (int i = 0; i < count; i++)
        {
            hptr[i]->show_bookData();
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

            for (i = 0; i < count; i++)
            {
                getname = hptr[i]->get_bookName();           //count번째까지 입력된 모든 bookName을 pntf에 저장

                if (strcmp(getname, s_name) == 0)
                {
                    found = 0;
                    hptr[i]->show_bookData();
                }
            }
            if (found)
                cout << s_name << " 라는 이름의 책은 없음" << endl;
        }
    }

    void save_bookData()
    {
        const char* file = "Library.txt";
        ofstream fout(file, ios::out);

        if (!fout)
        {
            cout << "Library.txt 파일을 열 수 없음";
            return;
        }

        fout << count << endl;                      //파일에 count 값 저장
        for (int i = 0; i < count; i++)                   //0부터 count번째만큼 (즉 입력된 유효반복횟수만큼) 파일에 각각의 데이터 저장
        {
            fout << hptr[i]->get_bookName() << " ";
            fout << hptr[i]->get_authorName() << " ";
            fout << hptr[i]->get_bookNum() << " ";
            fout << hptr[i]->get_publisher() << " ";
            fout << hptr[i]->get_genre() << " ";
            fout << hptr[i]->get_rental() << endl;

        }
        fout.close();
        cout << "[ Library.txt에 저장 완료 ]" << endl;
    }

    void load_bookData()
    {
        const char* file = "Library.txt";
        ifstream fin(file, ios::in);

        if (!fin)
        {
            cout << "Library.txt 파일을 열 수 없음";
            return;
        }

        fin >> count;                 //파일에 저장된 count값을 불러옴

        for (int i = 0; i < count; i++)       //파일에 저장된 각 데이터들을 불러옴
        {
            fin >> bookName;
            fin >> authorName;
            fin >> bookNum;
            fin >> publisher;
            fin >> genre;
            fin >> rental;
            hptr[i] = new Book(bookName, authorName, bookNum, publisher, genre, rental);
            //Book class의 매개변수 생성자 호출 후 fin으로 입력받은 변수들 넘김
        }

        fin.close();
        cout << "[ Library.txt load 완료 ]" << endl;
    }

};

int main()
{
    int choice, stop = 1;

    BookHandler lib;

    lib.load_bookData();

    while (그만)
    {
        cout << "\n1. 전체 도서 목록 \n";
        cout << "2. 도서 검색 \n";
        cout << "3. 도서 대여 \n";
        cout << "4. 도서 반납 \n";
        cout << "5. 관리자 모드 \n";
        cout << "6. 프로그램 종료 \n";
        cout << "Select ? (1~5) ";
        cin >> choice;  //1, 2, 3, 7, 1, 4
        cin.ignore(1);

        switch (choice)
        {

        case 1: lib.Output();
            break;
        case 2: lib.Find_Book();
            break;
        case 3: lib.Rental_Book();
            break;
        case 4: lib.Return_Book();
            break;
        case 5: lib.Management_mode();
            break;
        case 6: stop = 0;
            break;
        }

    } //while(그만) end

    printf("End. \n");

    return 0;
}