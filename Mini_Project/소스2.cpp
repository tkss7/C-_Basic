#include<iostream>
#include<cstring>
#include <iomanip>
#include<vector>
#include<map>
#include<list>
#include<vld.h>
#include <sstream>
#include<algorithm>
#include<fstream>
#include <regex>
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
    char name[20];
    int age;
    char phone[14];
    char planeNum2[6] = "";
    char reservNum[5];
    int password = 0;

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
    int Getpassword() { return password; }


    void Setname(const char* _name) { strcpy(name, _name); }
    void Setphone(const char* _phone) { strcpy(phone, _phone); }
    void Setage(int _age) { age = _age; }
    void SetplaneNum2(const char* _plane) { strcpy(planeNum2, _plane); }
    void SetreservNum(int _countNum) 
    {
        _countNum++;
        char s1[10] = "IA00";
        std::string tmp = std::to_string(_countNum);
        char const* num_char = tmp.c_str();

        strcat(s1, num_char);
        strcpy(reservNum, s1); 
    }
    void SetreservNum_c(char* _reservNum) { strcpy(reservNum, _reservNum); }
    void Setpassword(int _password) { password = _password; }


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


        cout << right << setw(10) << _passenger->GetreservNum() << setw(20) << _passenger->Getname()
            << setw(10) << _passenger->Getage() << setw(25) << _passenger->Getphone() << setw(12) << _passenger->GetplaneNum() << endl;
    }

    void TicketBuy()
    {
        int found;
        char _name[20];
        char _phone[14];
        int _age;
        char _ticket[6];
        char _reservNum[10];
        int password;

        while (1)
        {
            ShowData();
            found = 1;
            Passenger* pass = new Passenger;

            cout << "예약자 성명 : (종료시:end)";
            cin.getline(_name, 20);
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

            do {
                cout << "비밀번호 숫자 4자리를 입력하세요." << endl;
                cin >> password;
                cin.clear();
                cin.ignore(256, '\n');
            } while (cin.fail());
            pass->Setpassword(password);

            //pass->SetplaneNum2(_ticket);


            cout << "======================================" << endl;
            cout << "예약 번호는 : " << _reservNum << "입니다." << endl;
            cout << "======================================" << endl;

            pass->SetreservNum(_countNum);
            p.push_back(pass);


        }

    }

    void ShowPassenger_start()
    {
        cout << "==============================================================================" << endl;
        cout << right << setw(10) << "예약번호" << setw(20) << "예약자 성명" << setw(10) << "나이"
            << setw(25) << "예약자 Phone번호" << setw(12) << "편명" << endl;
    }

    void ShowPassenger_end()
    {
        cout << "==============================================================================" << endl;
        cout << endl << endl;
    }


    void ReservationCheck()// find
    {
        int found;
        char s_reservNum[20], * getreservNum;


        cout << endl << "예약 확인" << endl;


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

        ShowPassenger_end();


    }
    void showReservation()
    {
        cout << endl;
        cout << "예약정보 출력" << endl;
        ShowPassenger_start();

        for (it = p.begin(); it != p.end(); it++)
        {

            ShowData(*it);

        }
        ShowPassenger_end();
    }

    //virtual ShowData; // output

    void ReservationCancel()
    {
        Passenger* pass;
        int found, choice = 0, changeAge, stop = 1, password;
        char s_reservNum[20], * getreservNum, changePhone[14], changePlaneNum[6];
        char* c_planeNum, changeName[20];
        it = p.begin();
        cout << "예약 취소" << endl;

        while (1)
        {
            cout << "\n취소할 예약 번호 ? (검색종료:end) ";
            cin.getline(s_reservNum, 20);   //lee, kim, sun, ... end
            //cin.ignore(256, '\n');
            if (strcmp(s_reservNum, "end") == 0)
                break;
            found = 1;



            while (it != p.end())
            {

                cout << "비밀번호 숫자 4자리를 입력하세요." << endl;
                cin >> password;
                cin.ignore(256, '\n');
                if (cin.fail() == 1)
                {

                    break;
                }
                cin.clear();



                cin.clear();


                getreservNum = (*it)->GetreservNum();
                pass = *it;
                if ((*it)->Getpassword() == password)
                {
                    if (strcmp(getreservNum, s_reservNum) == 0)
                    {

                        found = 0;
                        c_planeNum = (*it)->GetplaneNum();
                        for (int i = 0; i < TIKET_SZ; i++)
                        {
                            if (strcmp(c_planeNum, ticketlist[i]->GetplaneNum()) == 0)
                                ticketlist[i]->Setcount(+1);
                        }
                        delete pass;
                        it = p.erase(it);
                        cout << "취소 완료." << endl;
                        break;
                    }
                    else
                        it++;

                }
                else
                {
                    cout << "잘못된 접근입니다." << endl;

                }
            }
            if (found)
                cout << s_reservNum << ", Not found !!! " << endl;
        }
    }






    void ReservationChange()
    {
        Passenger* pass;
        int found, choice = 0, changeAge, stop = 1, password;
        char s_reservNum[20], * getreservNum, changePhone[14], changePlaneNum[6];
        char* c_planeNum, changeName[20];
        it = p.begin();
        cout << "예약 변경" << endl;

        while (1)
        {
            cout << "\n변경할 예약 번호 ? (검색종료:end) ";
            cin.getline(s_reservNum, 20);   //lee, kim, sun, ... end
            //cin.ignore(256, '\n');
            if (strcmp(s_reservNum, "end") == 0)
                break;
            found = 1;



            while (it != p.end())
            {
                do {
                    cout << "비밀번호 숫자 4자리를 입력하세요." << endl;
                    cin >> password;
                    cin.clear();
                    cin.ignore(256, '\n');
                } while (cin.fail());

                getreservNum = (*it)->GetreservNum();
                pass = *it;
                if ((*it)->Getpassword() == password)
                {
                    if (strcmp(getreservNum, s_reservNum) == 0)
                    {

                        found = 0;
                        c_planeNum = (*it)->GetplaneNum();
                        for (int i = 0; i < TIKET_SZ; i++)
                        {
                            if (strcmp(c_planeNum, ticketlist[i]->GetplaneNum()) == 0)
                                ticketlist[i]->Setcount(+1);
                        }


                        cout << "==============================================================================" << endl;
                        cout << "변경 할 정보를 선택해 주세요." << endl;
                        cout << endl;
                        cout << "1.성명   2.나이   3. 연락처  4. 항공편  5. 나가기" << endl;
                        cout << "==============================================================================" << endl;
                        //TicketBuy();

                        cin >> choice;
                        cin.ignore(2, '\n');
                        switch (choice)
                        {
                        case 1:
                        {
                            cout << "변경 할 이름을 입력하세요." << endl;
                            cin.getline(changeName, 20);
                            (*it)->Setname(changeName);
                        }
                        break;
                        case 2:
                        {
                            cout << "변경 할 나이을 입력하세요." << endl;
                            cin >> changeAge;
                            (*it)->Setname(changeAge);
                        }
                        break;
                        case 3:
                        {
                            cout << "변경 할 연락처을 입력하세요." << endl;
                            cin.getline(changePhone, 15);
                            (*it)->Setname(changePhone);
                        }
                        break;
                        case 4:
                        {
                            cout << "변경 할 항공편을 입력하세요." << endl;
                            cin.getline(changePlaneNum, 2);
                            (*it)->Setname(changePlaneNum);
                        }
                        break;
                        case 5: stop = 0;
                            break;
                        }


                        cout << "예약 번호는 : " << (*it)->GetreservNum() << "입니다." << endl;


                        delete pass;
                        it = p.erase(it);

                        cout << "변경 완료." << endl;
                    }
                    else
                        it++;
                }
                else
                {
                    cout << "잘못된 접근입니다." << endl;
                    return;
                }
            }


            if (found)
                cout << s_reservNum << ", Not found !!! " << endl;

        }

    }

    //void TicketSave()

//while (1) end


    //}


    void Admin()
    {
        int adminPW;

        cout << "관리자 비밀번호를 입력해주세요." << endl;
        cin >> adminPW;

        if (adminPW != 111111)
            cout << "비밀번호가 다릅니다!! " << endl;

        else
        {
            int choice, stop = 1;

            while (stop)
            {
                cout << "1. 예약정보 저장" << endl;
                cout << "2. 예약정보 출력" << endl;
                cout << "3. 종료." << endl;
                cout << "Select (1~3) ?" << endl;
                cin >> choice;
                cin.ignore(2, '\n');

                switch (choice)
                {
                    case 1: Save_PassengerData();
                        break;
                case 2: showReservation();
                    break;
                case 3: stop = 0;
                    break;
                }
            }
        }

    }
    void Save_TicketData()
    {

        const char* file = "Ticket.txt";

        ofstream fout(file, ios::out);
        if (!fout)
        {
            cout << "Library.txt 파일을 열 수 없음";
            return;
        }

        fout << tkNum << endl;                      //파일에 count 값 저장
        for (int i = 0; i < tkNum; i++)                   //0부터 count번째만큼 (즉 입력된 유효반복횟수만큼) 파일에 각각의 데이터 저장
        {
            fout << ticketlist[i]->GetplaneNum() << " ";
            fout << ticketlist[i]->Getdestination() << " ";
            fout << ticketlist[i]->Gettime() << " ";
            fout << ticketlist[i]->Getcount() << endl;

        }
        fout.close();
        cout << "[ Ticket.txt에 저장 완료 ]" << endl;
    }

    void Load_TIcketData()
    {
        char planeNum[6]; //planeNum
        char destination[30];
        char time[20];
        int ticketcount;


        const char* file = "Ticket.txt";

        ifstream fin(file, ios::in);

        if (!fin)
        {
            cout << "Ticket.txt 파일을 열 수 없음";
            return;

        }

        fin >> tkNum;                 //파일에 저장된 count값을 불러옴

        for (int i = 0; i < tkNum; i++)       //파일에 저장된 각 데이터들을 불러옴
        {
            fin >> planeNum;
            fin >> destination;
            fin >> time;
            fin >> ticketcount;
            ticketlist[i] = new TicketList(planeNum, destination, time, ticketcount);
            //Book class의 매개변수 생성자 호출 후 fin으로 입력받은 변수들 넘김
        }

        fin.close();
        cout << "[ Ticket.txt load 완료 ]" << endl;
    }

    void Save_PassengerData()
    {
        string input_name, output_name;
        const char* file = "Pessenger.txt";

        ofstream fout(file, ios::out);
        if (!fout)
        {
            cout << "Pessenger.dat 파일을 열 수 없음";
            return;
        }
        fout << p.size() << endl;                      //파일에 count 값 저장
        for (it = p.begin(); it != p.end(); it++)                   //0부터 count번째만큼 (즉 입력된 유효반복횟수만큼) 파일에 각각의 데이터 저장
        {
            input_name = (*it)->Getname();
            output_name= regex_replace(input_name, regex(" "), "　");
            fout << output_name << " ";
            fout << (*it)->Getage() << " ";
            fout << (*it)->Getphone() << " ";
            fout << (*it)->GetplaneNum() << " ";
            fout << (*it)->GetreservNum() << " ";
            fout << (*it)->Getpassword() << endl;

        }
        fout.close();
        cout << "[ Passenger.txt에 저장 완료 ]" << endl;


    }

    void Load_PassengerData()
    {
        char name[20];
        int age;
        char phone[14];
        char planeNum2[6] = "";
        char reservNum[5];
        int password = 0;


        const char* file = "Passenger.txt";

        ifstream fin(file, ios::in);

        if (!fin)
        {
            cout << "Ticket.txt 파일을 열 수 없음";
            return;

        }

        fin >> _countNum;                 //파일에 저장된 count값을 불러옴

        for (it = p.begin(); it != p.end(); it++)       //파일에 저장된 각 데이터들을 불러옴
        {
            Passenger* pass = *it;
            fin >> name;
            fin >> age;
            fin >> phone;
            fin >> planeNum2;
            fin >> reservNum;
            fin >> password;
            (*it)->Setname(name);
            (*it)->Setage(age);
            (*it)->Setphone(phone);
            (*it)->SetplaneNum2(planeNum2);
            (*it)->SetreservNum_c(reservNum);
            (*it)->Setpassword(password);

            p.push_back(pass);
            //ticketlist[i] = new TicketList(planeNum, destination, time, ticketcount);
            //Book class의 매개변수 생성자 호출 후 fin으로 입력받은 변수들 넘김
        }

        fin.close();
        cout << "[ Ticket.txt load 완료 ]" << endl;
    }

    //Revise();
};
// 예약번호 만들고 예약번호로 찾을 수 있게 찾기
//
int main()
{
    
    PassHandler handler;

    handler.Make_Ticket(new TicketList("AI001", "워싱턴DC", "PM 17:00", 5));
    handler.Make_Ticket(new TicketList("AI002", "뉴욕", "PM 1:00", 4));
    handler.Make_Ticket(new TicketList("CI015", "워싱턴DC", "PM 12:00", 3));
    handler.Make_Ticket(new TicketList("FI001", "로스엔젤레스", "PM 11:00", 2));
    handler.Make_Ticket(new TicketList("FI021", "가즈아", "PM 6:00", 1));

    handler.Load_PassengerData();

    int choice, stop = 1;

    while (stop)
    {


        cout << "\n\n1. 항공편 구입" << endl;
        cout << "2. 예약정보 검색" << endl;
        cout << "3. 예약정보 변경" << endl;
        cout << "4. 예약정보 취소" << endl;
        cout << "5. 관리자모드" << endl;
        cout << "6. 종료" << endl;
        cout << "Select ? (1~6) ";
        cin >> choice;
        cin.ignore(2, '\n');
        switch (choice)
        {
        case 1: handler.TicketBuy();
            break;
            //case 2: handler.showReservation();
                //break;
        case 2: handler.ReservationCheck();
            break;
        case 3: handler.ReservationChange();
            break;
        case 4: handler.ReservationCancel();
            break;
        case 5: handler.Admin();
            break;
        case 6: stop = 0;
            break;
        }
    }   //while(1) end

    cout << "End." << endl;

    return 0;

}