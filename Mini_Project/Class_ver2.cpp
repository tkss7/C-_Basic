#include<iostream>
#include<cstring>
#include <iomanip>
#include<vector>
#include<map>
#include<list>
#include<vld.h>
#include <sstream>
using namespace std;

//IA001 0408 18:00 pm  0409 18:00 pm   London
#define TIKET_SZ 5
class TicketList
{
private:
    char planeNum[6]; //planeNum
    char destination[30];
    char time[20];
    int count;

public:
    TicketList(const char* planeNum, const char* destination, const char* time, int _count)
    {
        strcpy(this->planeNum, planeNum);
        strcpy(this->destination, destination);
        strcpy(this->time, time);
        count = _count;

    }

    char* GetplaneNum() { return planeNum; }
    char* Getdestination() { return destination; }
    char* Gettime() { return time; }
    int Getcount() { return count; }
    void Setcount(int num) { count = count + num; }

};

class Passenger :public TicketList
{
private:
    char name[10];
    int age;
    char phone[14];
    char planeNum2[6] = "";
    char reservNum[5];
public:
    Passenger(const char* planeNum = "", const char* destination = "", const char* time = "", int _count = 0,
        const char* name = "", int age = 0, const char* phone = "") : TicketList(planeNum, destination, time, _count)
    {
        strcpy(this->name, name);
        strcpy(this->phone, phone);
        this->age = age;
    }
    char* Getname() { return name; }
    int Getage() { return age; }
    char* Getphone() { return phone; }
    char* GetplaneNum() { return planeNum2; }
    char* GetreservNum() { return reservNum; }

    void Setname(const char* _name) { strcpy(name, _name); }
    void Setphone(const char* _phone) { strcpy(phone, _phone); }
    void Setage(int _age) { age = _age; }
    void SetplaneNum2(const char* _plane) { strcpy(planeNum2, _plane); }
    void SetreservNum(const char* _reservNum) { strcpy(reservNum, _reservNum); }

    friend void ReservationCheck();


    void Setname(int age)
    {
        this->age = age;
    }
};

class PassHandler   //PassHandler
{
private:
    TicketList* ticketlist[TIKET_SZ];
    list<Passenger*> p;
    int tkNum;
    list<Passenger*>::iterator it;
    int _countNum = 0;
public:

    PassHandler() : tkNum(0) { it = p.begin(); }

    ~PassHandler()
    {
        for (int i = 0; i < tkNum; i++)
        {
            delete ticketlist[i];
        }
        for (it = p.begin(); it != p.end(); it++)
        {
            delete* it;
        }
    }

    void Make_Ticket(TicketList* tmp)
    {
        ticketlist[tkNum++] = tmp;
    }

    void ShowData()
    {
        cout << endl << endl;
        cout << "==============================================================================" << endl;
        cout << right << setw(10) << "편명" << setw(20) << "목적지" << setw(20) << "출발시간"
            << setw(20) << "잔여 좌석" << endl;

        for (int i = 0; i < TIKET_SZ; i++)
        {
            cout << right << setw(10) << ticketlist[i]->GetplaneNum() << setw(20) << ticketlist[i]->Getdestination()
                << setw(20) << ticketlist[i]->Gettime() << setw(20) << ticketlist[i]->Getcount() << endl;
        }
        cout << "==============================================================================" << endl;
        cout << endl << endl;
    }
    virtual void ShowData(Passenger* _passenger)
    {
        //cout << "성명 : " << _passenger->Getname() << "나이 : " << _passenger->Getage() 
            //<< "연락처 : " << _passenger->Getphone() << "예약번호 : " << _passenger->GetreservNum() << endl;

        cout << right << setw(10) << _passenger->GetreservNum() << setw(15) << _passenger->Getname()
            << setw(15) << _passenger->Getage() << setw(15) << _passenger->Getphone() << setw(15) << _passenger->GetplaneNum() << endl;
    }

    void TicketBuy()
    {
        int found;
        char _name[10];
        char _phone[14];
        int _age;
        char _ticket[6];
        char _reservNum[10];

        while (1)
        {
            ShowData();
            found = 1;
            Passenger* pass = new Passenger;

            cout << "예약자 성명 : (종료시:end)";
            cin.getline(_name, 10);
            if (strcmp(_name, "end") == 0)
            {
                delete pass;
                break;
            }


            pass->Setname(_name);


            cout << "예약자 나이 : ";
            cin >> _age;
            cin.ignore(2, '\n');
            pass->Setage(_age);


            cout << "예약자 phone-number (-사용하여 입력) : ";
            cin.getline(_phone, 14);
            pass->Setphone(_phone);

            while (found)
            {
                cout << "예약 할 항공편 명 : ";
                cin.getline(_ticket, 6);
                cout << "==============================================================================" << endl;

                for (int i = 0; i < tkNum; i++)
                {
                    if (strcmp(ticketlist[i]->GetplaneNum(), _ticket) == 0)
                    {
                        ticketlist[i]->Setcount(-1);
                        found = 0;
                        pass->SetplaneNum2(_ticket);
                        break;
                    }
                }
                if (found)
                    cout << "일치하는 것이 없습니다." << endl;
            }
            //pass->SetplaneNum2(_ticket);

            _countNum++;
            char s1[10] = "IA00";
            std::string tmp = std::to_string(_countNum);
            char const* num_char = tmp.c_str();

            strcat(s1, num_char);
            strcpy(_reservNum, s1);
            cout << "======================================" << endl;
            cout << "예약 번호는 : " << _reservNum << "입니다." << endl;
            cout << "======================================" << endl;

            pass->SetreservNum(_reservNum);
            p.push_back(pass);


        }

    }

    void ReservationCheck()// find
    {
        int i, found;
        char s_reservNum[20], * getreservNum;

        cout << "예약 확인" << endl;

        while (1)
        {
            cout << "\n검색할 예약 번호 ? (검색종료:end) ";
            cin.getline(s_reservNum, 20);   //lee, kim, sun, ... end
            if (strcmp(s_reservNum, "end") == 0)
                break;

            found = 1;

            for (it = p.begin(); it != p.end(); it++)
            {
                getreservNum = (*it)->GetreservNum();
                if (strcmp(getreservNum, s_reservNum) == 0)
                {
                    found = 0;
                    //cout << (*it)->Getname() << (*it)->Getage() << (*it)->Getphone() << (*it)->GetplaneNum();
                    ShowData(*it);
                }
            };

            if (found)
                cout << s_reservNum << ", Not found !!! " << endl;

        }//while (1) end




    }
    void showReservation()
    {
        for (it = p.begin(); it != p.end(); it++)
        {

            ShowData(*it);

        };
    }
    //virtual ShowData; // output
     //ReservationChange();

      //Revise();
};
// 예약번호 만들고 예약번호로 찾을 수 있게 찾기
//
int main()
{

    //map<string, *Passenger>;

    PassHandler handler;

    handler.Make_Ticket(new TicketList("AI001", "워싱턴DC", "PM 17:00", 5));
    handler.Make_Ticket(new TicketList("AI002", "뉴욕", "PM 1:00", 4));
    handler.Make_Ticket(new TicketList("CI015", "워싱턴DC", "PM 12:00", 3));
    handler.Make_Ticket(new TicketList("FI001", "로스엔젤레스", "PM 11:00", 2));
    handler.Make_Ticket(new TicketList("FI021", "가즈아", "PM 6:00", 1));


    int choice, stop = 1;

    while (stop)
    {


        cout << "\n\n1. 항공편 구입" << endl;
        cout << "2. 예약정보 출력" << endl;
        cout << "3. 예약정보 검색" << endl;
        cout << "4. 종료" << endl;
        cout << "Select ? (1~4) ";
        cin >> choice;
        cin.ignore(2, '\n');
        switch (choice)
        {
        case 1: handler.TicketBuy();
            break;
        case 2: handler.showReservation();
            break;
        case 3: handler.ReservationCheck();
            break;
        case 4: stop = 0;
            break;
        }
    }   //while(1) end

    cout << "End." << endl;

    return 0;

}