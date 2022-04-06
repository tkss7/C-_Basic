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
        cout << "Book ���ȣ ������ ȣ��" << endl;
        strcpy(bookName, "");
        strcpy(authorName, "");
        strcpy(bookNum, "");
        strcpy(publisher, "");
        strcpy(genre, "");
        strcpy(rental, "");
    }

    Book(const char* _bookName, const char* _authorName, const char* _bookNum, const char* _publisher, const char* _genre, const char* _rental)
    {
        cout << "Book �Ű����� ������ ȣ��" << endl;
        strcpy(bookName, _bookName);
        strcpy(authorName, _authorName);
        strcpy(bookNum, _bookNum);
        strcpy(publisher, _publisher);
        strcpy(genre, _genre);
        strcpy(rental, _rental);
    }

    ~Book()
    {
        cout << "Book �Ҹ��� ȣ��" << endl;
    }

    Book* input_BookInfo()             //���� Ÿ���� Book ������ ���� input �Լ� ����
    {
        Book* bookptr = new Book;                 //���� �ڷ����� Book�� �޸� ������ �Ҵ� �� Book������ ���� bookptr�� �����ּҸ� ����Ŵ 

        cout << "å �̸� : (�Է� ���� : end)";
        cin.getline(bookptr->bookName, bookname_len);

        if (strcmp(bookptr->bookName, "end") == 0)   //��������
        {
            delete bookptr;
            return nullptr;
        }

        cout << "���� �̸� : ";
        cin.getline(bookptr->authorName, authorName_len);

        cout << "å �Ϸù�ȣ : ";
        cin.getline(bookptr->bookNum, bookNum_len);

        cout << "���ǻ� : ";
        cin.getline(bookptr->publisher, publisher_len);

        cout << "�帣 : ";
        cin.getline(bookptr->genre, genre_len);

        cout << "�뿩���� ���� (����/�Ұ���) : ";
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
        char* rental2 = strcpy(_rental, "�Ұ���");
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
        char* return2 = strcpy(_return, "����");
        return return2;
    }

    void show_bookData()
    {
        cout << "������ : " << bookName << ", ���ڸ� : " << authorName << ", ���� �Ϸù�ȣ : "
            << bookNum << ", ���ǻ� : " << publisher << ", �帣 : " << genre << ", �뿩 ���� ���� : " << rental << endl;
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
        cout << "������ å �̸� : ";
        cin.getline(s_name, bookname_len);

        found = 1;
        for (i = 0; i < count; i++)
        {
            getname = hptr[i]->get_bookName();
            if (strcmp(getname, s_name) == 0)
            {
                found = 0;
                getrental = hptr[i]->get_rental();

                cout << "���� �뿩 ���� ���� : " << getrental << endl;
                if (strcmp(getrental, "����") == 0)
                {
                    int answer;
                    cout << " �뿩�Ͻðڽ��ϱ�? (1.��/2.�ƴϿ�) : " << endl;
                    cin >> answer;
                    if (answer == 1)
                    {
                        cout << "�뿩�� �Ϸ� �Ǿ����ϴ�. " << endl;
                        get_false_rental(getrental);
                        save_bookData();
                    }
                    else if (answer == 2)
                        break;
                }
                else
                    cout << "�뿩�� �Ұ��� �մϴ�." << endl;
            }
        }

        if (found)
            cout << s_name << ", Not found !!! " << endl;
    }

    void Return_Book()
    {
        int i, found;
        char s_name[bookname_len], * getname, * getreturn;
        cout << "�ݳ��� å �̸� : ";
        cin.getline(s_name, bookname_len);

        found = 1;
        for (i = 0; i < count; i++)
        {

            getname = hptr[i]->get_bookName();
            if (strcmp(getname, s_name) == 0)
            {
                found = 0;
                getreturn = hptr[i]->get_return();
                cout << "<�ݳ� ���� ����>" << endl;
                if (strcmp(getreturn, "�Ұ���") == 0)
                {
                    int answer;
                    cout << " �ݳ��� �����մϴ�. ���Ͻðڽ��ϱ�? (1.��/2.�ƴϿ�) : " << endl;
                    cin >> answer;
                    if (answer == 1)
                    {
                        cout << "�ݳ��� �Ϸ� �Ǿ����ϴ�. " << endl;
                        get_false_return(getreturn);
                        save_bookData();
                    }
                    else if (answer == 2)
                        break;
                }
                else
                    cout << "�ݳ��� �Ұ��� �մϴ�." << endl;

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
            hptr[i] = input_BookInfo();               //�����͸� ������ Book�� ��ü bookptr�� �����ּҸ� hptr�� i��° �迭�� ��ȯ
            if (hptr[i] == nullptr)                       //hptr->bookptr->���� �Ҵ�� Class�޸�(�����͸� ����)
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
            cout << "������ ���� �̸� (���� ���� : end) : ";
            cin.getline(s_name, bookname_len);

            if (strcmp(s_name, "end") == 0)
                break;

            found = 1;

            for (i = 0; i < count; i++)
            {
                getname = hptr[i]->get_bookName();           //count��°���� �Էµ� ��� bookName�� pntf�� ����

                if (strcmp(getname, s_name) == 0)
                {
                    found = 0;
                    hptr[i]->show_bookData();
                    index = i;
                }
            }

            if (found)
                cout << s_name << " ��� �̸��� å�� ����" << endl;

            for (int j = index; j < count; j++)
            {
                hptr[j] = hptr[j + 1];
            }
            count--;
        }
        /*cout << "������ ������ �Ϸú�ȣ �Է� : ";
        cin.getline(delNum, bookNum_len);

        for (int i = 0; i < count; i++)
        {
           if (strcmp(delNum, hptr[i]->get_bookNum()) == 0)
           {
              hptr[i] = NULL;
              cout << "������ �Ϸ��߽��ϴ�.";
           }
        }
        */
    }

    void Management_mode()
    {
        int choice, stop = 1;
        while (�׸�)
        {
            cout << "\n1. �Ű� ���� �߰� \n";
            cout << "2. ���� ���� \n";
            cout << "3. ���� ������� ���� \n";
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
        cout << "���� �ִ� å ���� : " << count << endl;
        cout << "===============å ���================ " << endl;

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
            cout << "�˻��� å �̸� (�˻� ���� : end) : ";
            cin.getline(s_name, bookname_len);

            if (strcmp(s_name, "end") == 0)
                break;

            found = 1;

            for (i = 0; i < count; i++)
            {
                getname = hptr[i]->get_bookName();           //count��°���� �Էµ� ��� bookName�� pntf�� ����

                if (strcmp(getname, s_name) == 0)
                {
                    found = 0;
                    hptr[i]->show_bookData();
                }
            }
            if (found)
                cout << s_name << " ��� �̸��� å�� ����" << endl;
        }
    }

    void save_bookData()
    {
        const char* file = "Library.txt";
        ofstream fout(file, ios::out);

        if (!fout)
        {
            cout << "Library.txt ������ �� �� ����";
            return;
        }

        fout << count << endl;                      //���Ͽ� count �� ����
        for (int i = 0; i < count; i++)                   //0���� count��°��ŭ (�� �Էµ� ��ȿ�ݺ�Ƚ����ŭ) ���Ͽ� ������ ������ ����
        {
            fout << hptr[i]->get_bookName() << " ";
            fout << hptr[i]->get_authorName() << " ";
            fout << hptr[i]->get_bookNum() << " ";
            fout << hptr[i]->get_publisher() << " ";
            fout << hptr[i]->get_genre() << " ";
            fout << hptr[i]->get_rental() << endl;

        }
        fout.close();
        cout << "[ Library.txt�� ���� �Ϸ� ]" << endl;
    }

    void load_bookData()
    {
        const char* file = "Library.txt";
        ifstream fin(file, ios::in);

        if (!fin)
        {
            cout << "Library.txt ������ �� �� ����";
            return;
        }

        fin >> count;                 //���Ͽ� ����� count���� �ҷ���

        for (int i = 0; i < count; i++)       //���Ͽ� ����� �� �����͵��� �ҷ���
        {
            fin >> bookName;
            fin >> authorName;
            fin >> bookNum;
            fin >> publisher;
            fin >> genre;
            fin >> rental;
            hptr[i] = new Book(bookName, authorName, bookNum, publisher, genre, rental);
            //Book class�� �Ű����� ������ ȣ�� �� fin���� �Է¹��� ������ �ѱ�
        }

        fin.close();
        cout << "[ Library.txt load �Ϸ� ]" << endl;
    }

};

int main()
{
    int choice, stop = 1;

    BookHandler lib;

    lib.load_bookData();

    while (�׸�)
    {
        cout << "\n1. ��ü ���� ��� \n";
        cout << "2. ���� �˻� \n";
        cout << "3. ���� �뿩 \n";
        cout << "4. ���� �ݳ� \n";
        cout << "5. ������ ��� \n";
        cout << "6. ���α׷� ���� \n";
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

    } //while(�׸�) end

    printf("End. \n");

    return 0;
}