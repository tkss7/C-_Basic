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

        cout << "���� �̸�(�Է� ���� : end) : ";
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

        bookcount++;
        while (1)
        {
            if (strcmp(bookptr->rental, "����") == 0 || strcmp(bookptr->rental, "�Ұ���") == 0)
                return bookptr;

            else
            {
                cout << "���� �Ǵ� �Ұ��� �� �Է��ϼ���";
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
        char* rental2 = strcpy(_rental, "�Ұ���");
        return rental2;
    }


    char* get_false_return(char* _return)
    {
        char* return2 = strcpy(_return, "����");
        return return2;
    }

    void show_BookData()
    {
        cout << "������ : " << bookName << ", ���ڸ� : " << authorName << ", ���� �Ϸù�ȣ : "
            << bookNum << ", ���ǻ� : " << publisher << ", �帣 : " << genre << ", �뿩 ���� ���� : " << rental << endl;
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
        cout << "Person ���ȣ ������ ȣ��" << endl;
        strcpy(ID, "");
        strcpy(PW, "");
        strcpy(Member_name, "");
        strcpy(Member_PhoneNum, "");
    }

    Person(const char* _ID, const char* _PW, const char* _Member_name, const char* _Member_PhoneNum)
    {
        cout << "Person �Ű����� ������ ȣ��" << endl;
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

        cout << "�̸� : ";
        cin.getline(personptr->Member_name, 20);

        cout << "��ȭ��ȣ : ";
        cin.getline(personptr->Member_PhoneNum, 30);

        cout << "ȸ������ �Ϸ� !" << endl;

        return personptr;
    }

    char* get_ID() { return ID; }
    char* get_PW() { return PW; }
    char* get_MemberName() { return Member_name; }
    char* get_MemberPhoneNum() { return Member_PhoneNum; }

    void Show_MemberData()
    {
        cout << "ȸ�� �̸� : " << Member_name << ", ��ȭ��ȣ : " << Member_PhoneNum << ", ID : "
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
        cout << y << "��, " << m << "��, " << d << "�ϱ��� �ݳ��� �ּ���." << endl;

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

        cout << "������ å �̸� : ";
        cin.getline(s_name, bookname_len);

        found = 1;
        for (i = 0; i < Bcount; i++)
        {
            getname = BHptr[i]->get_BookName();
            if (strcmp(getname, s_name) == 0)
            {
                found = 0;
                getrental = BHptr[i]->get_rental();

                cout << "���� �뿩 ���� ���� : " << getrental << endl;
                if (strcmp(getrental, "����") == 0)
                {
                    int answer;
                    cout << " �뿩�Ͻðڽ��ϱ�? (1.��/2.�ƴϿ�) : " << endl;
                    cin >> answer;
                    if (answer == 1)
                    {
                        cout << "�뿩�Ͻ�: " << systemTime.wYear << "��, " << systemTime.wMonth << "��, " << systemTime.wDay << "��" << endl;
                        cout << "�뿩�� �Ϸ� �Ǿ����ϴ�. " << endl;

                        Print_Return_Day();

                        get_false_rental(getrental);
                        save_bookData();
                        Save_bookTxt();
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
        SYSTEMTIME systemTime;
        GetLocalTime(&systemTime);

        cout << "�ݳ��� å �̸� : ";
        cin.getline(s_name, bookname_len);

        found = 1;
        for (i = 0; i < Bcount; i++)
        {

            getname = BHptr[i]->get_BookName();
            if (strcmp(getname, s_name) == 0)
            {
                found = 0;
                getreturn = BHptr[i]->get_return();
                cout << "<�ݳ� ���� ����>" << endl;
                if (strcmp(getreturn, "�Ұ���") == 0)
                {
                    int answer;
                    cout << " �ݳ��� �����մϴ�. ���Ͻðڽ��ϱ�? (1.��/2.�ƴϿ�) : " << endl;
                    cin >> answer;
                    if (answer == 1)
                    {
                        cout << "�ݳ��� �Ϸ� �Ǿ����ϴ�. " << endl;


                        cout << "�ݳ��Ͻ�: " << systemTime.wYear << "��, " << systemTime.wMonth << "��, " << systemTime.wDay << "��" << endl;

                        get_false_return(getreturn);
                        save_bookData();
                        Save_bookTxt();
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
        for (i = Bcount; i < Bhptr_size; i++)
        {
            BHptr[i] = input_BookInfo();               //�����͸� ������ Book�� ��ü bookptr�� �����ּҸ� hptr�� i��° �迭�� ��ȯ
            if (BHptr[i] == nullptr)                       //hptr->bookptr->���� �Ҵ�� Class�޸�(�����͸� ����)
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
            cout << "������ ���� �̸� (���� ���� : end) : ";
            cin.getline(s_name, bookname_len);

            if (strcmp(s_name, "end") == 0)
                break;

            found = 1;

            for (i = 0; i < Bcount; i++)
            {
                getname = BHptr[i]->get_BookName();           //count��°���� �Էµ� ��� bookName�� pntf�� ����

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
                cout << s_name << " ��� �̸��� å�� ����" << endl;
                break;
            }
            Bcount--;
        }

    }

    void Check_Management()
    {
        int password = 0;
        cout << "������ ��й�ȣ�� �Է��ϼ��� >>";
        cin >> password;

        if (password == PASSWORD)
            Management_mode();
        else
            cout << "Ʋ�Ƚ��ϴ�. �����ڸ�忡 ������ �� �����ϴ�. " << endl;
    }

    void Management_mode()
    {
        int choice, stop = 1;
        while (stop)
        {
            cout << "\n1. �Ű� ���� �߰� \n";
            cout << "2. ���� ���� \n";
            cout << "3. ���� ���� ������� ���� \n";
            cout << "4. ȸ�� ��� ���\n";
            cout << "5. ȸ�� ���� �˻�\n";
            cout << "6. ȸ�� ���� ����\n";
            cout << "7. ȸ�� ���� ������� ���� \n";
            cout << "8. ����ȭ������ ���ư���\n ";
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
        cout << "���� �ִ� å ���� : " << Bcount << endl;
        cout << "===============å ���================ " << endl;

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
            cout << "�˻��� å �̸� (�˻� ���� : end) : ";
            cin.getline(s_name, bookname_len);

            if (strcmp(s_name, "end") == 0)
                break;

            found = 1;

            for (i = 0; i < Bcount; i++)
            {
                getname = BHptr[i]->get_BookName();           //count��°���� �Էµ� ��� bookName�� pntf�� ����

                if (strcmp(getname, s_name) == 0)
                {
                    found = 0;
                    BHptr[i]->show_BookData();
                }
            }
            if (found)
                cout << s_name << " ��� �̸��� å�� ����" << endl;
        }
    }

    void Save_bookTxt()
    {
        const char* file = "Library.txt";
        ofstream fout(file, ios::out);

        if (!fout)
        {
            cout << "Library.txt ������ �� �� ����";
            return;
        }

        fout << Bcount << endl;                      //���Ͽ� count �� ����
        for (int i = 0; i < Bcount; i++)                   //0���� count��°��ŭ (�� �Էµ� ��ȿ�ݺ�Ƚ����ŭ) ���Ͽ� ������ ������ ����
        {
            fout << BHptr[i]->get_BookName() << " ";
            fout << BHptr[i]->get_authorName() << " ";
            fout << BHptr[i]->get_bookNum() << " ";
            fout << BHptr[i]->get_publisher() << " ";
            fout << BHptr[i]->get_genre() << " ";
            fout << BHptr[i]->get_rental() << endl;

        }
        fout.close();
        cout << "[ Library.txt�� ���� �Ϸ� ]" << endl;
    }

    void save_bookData() //�������Ϸ�
    {
        const char* file = "book.dat";

        ofstream fout;
        fout.open(file, ios::out | ios::binary);

        if (!fout)
        {
            cout << "book.dat ���� ���� ����";
            return;
        }

        fout.write((char*)&Bcount, sizeof(Bcount));
        for (int i = 0; i < Bcount; i++)
            fout.write((char*)(BHptr[i]), sizeof(Book));

        fout.close();

        printf("[ book.dat�� ���� �Ϸ� ] !!! \n");
    }

    void load_bookData()
    {

        const char* file = "book.dat";
        Book* ptr;

        ifstream fin;
        fin.open(file, ios::in | ios::binary);


        if (!fin)
        {
            cout << "loadBook() ���� ���� ����";
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
            cout << "\n1. ��ü ���� ��� \n";
            cout << "2. ���� �˻� \n";
            cout << "3. ���� �뿩 \n";
            cout << "4. ���� �ݳ� \n";
            cout << "5. ������ ��� \n";
            cout << "6. ���α׷� ���� \n";
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

        } //while(�׸�) end
    }

    void Output_MemberData()
    {
        cout << "������ �� ȸ�� �� : " << Pcount << endl;
        cout << "===============ȸ�� ���================ " << endl;

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
            cout << "ȸ�� �̸� (�˻� ���� : end) : ";
            cin.getline(s_name, 20);

            if (strcmp(s_name, "end") == 0)
                break;

            found = 1;

            for (i = 0; i < Pcount; i++)
            {
                getname = PHptr[i]->get_MemberName();           //count��°���� �Էµ� ��� bookName�� pntf�� ����

                if (strcmp(getname, s_name) == 0)
                {
                    found = 0;
                    PHptr[i]->Show_MemberData();
                }
            }
            if (found)
            {
                cout << "[" << s_name << "]" << " ȸ���� �����ϴ�" << endl;
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
            cout << "======================= ȸ�������� �Է��ϼ���. ======================= " << endl;
            cout << "                    iD >> ";
            cin.getline(s_id, ID_len);

            cout << "                    PASSWARD >> ";
            cin.getline(s_pw, PW_len);


            if (strcmp(s_id, "end") == 0)
                break;

            found = 1;

            for (i = 0; i < Pcount; i++)
            {
                getid = PHptr[i]->get_ID();           //count2��°���� �Էµ� ��� ID�� getid�� ����
                getpw = PHptr[i]->get_PW();

                if (strcmp(getid, s_id) == 0)
                {
                    if (strcmp(getpw, s_pw) == 0)
                        MainMenu();
                    else
                    {
                        cout << "��й�ȣ�� Ʋ���ϴ�. �ٽ� �Է��ϼ���." << endl;
                        break;
                    }
                    found = 0;
                }
            }
            if (found)
            {
                cout << s_id << "�������� �ʴ� ID�Դϴ�. ���� �޴��� ���ư� ȸ�������� �ϼ���" << endl;
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
            cout << "������ ȸ�� �̸� (���� ���� : end) : ";
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
                cout << "[" << s_name << "]" << " ȸ���� �����ϴ�" << endl;
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
            cout << "Member.txt ������ �� �� ����";
            return;
        }

        fout << Bcount << endl;                      //���Ͽ� count �� ����
        for (int i = 0; i < Pcount; i++)                   //0���� count��°��ŭ (�� �Էµ� ��ȿ�ݺ�Ƚ����ŭ) ���Ͽ� ������ ������ ����
        {
            fout << PHptr[i]->get_ID() << " ";
            fout << PHptr[i]->get_PW() << " ";


        }
        fout.close();
        cout << "[ Member.txt�� ���� �Ϸ� ]" << endl;
    }

    void Save_MemberData() //�������Ϸ�
    {
        const char* file = "Member.dat";

        ofstream fout;
        fout.open(file, ios::out | ios::binary);

        if (!fout)
        {
            cout << "Member.dat ���� ���� ����";
            return;
        }

        fout.write((char*)&Bcount, sizeof(Bcount));
        for (int i = 0; i < Pcount; i++)
            fout.write((char*)(PHptr[i]), sizeof(Person));

        fout.close();

        printf("[ Member.dat�� ���� �Ϸ� ] !!! \n");
    }

    void load_MemberData()
    {

        const char* file = "Member.dat";
        Person* ptr;

        ifstream fin;
        fin.open(file, ios::in | ios::binary);


        if (!fin)
        {
            cout << "load_MemberData() ���� ���� ����";
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
        cout << "===================== ���� �������� ���Ű��� ȯ���մϴ�. ===================== " << endl;
        cout << "\n1. �α��� \n";
        cout << "2. ȸ������ \n";
        cout << "3. ���α׷� ����\n";
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