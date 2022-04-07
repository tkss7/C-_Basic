#include<iostream>
#include<cstring>
#include <iomanip>
#include<list>
#include<vld.h>
#include <sstream>
#include<fstream>
#include <regex>
using namespace std;

#define TIKET_SZ 20
#define PLANE_SZ 20
#define PHONE_SZ 20
class TicketList
{
private:
    char planeNum[PLANE_SZ]; //planeNum
    char destination[30];
    char time[20]; // 출발시간
    int count; // 좌석수

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
    char phone[PHONE_SZ];
    char planeNum2[PLANE_SZ] = ""; // 항공편명
    char reservNum[20]; // 예약번호
    int password = 0;

public:
    inline Passenger(const char* planeNum = "", const char* destination = "", const char* time = "", int _count = 0,
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
    void SetreservNum(int& _countNum)
    {
        _countNum++;
        char s1[20] = "INFINITE_00";
        std::string tmp = std::to_string(_countNum);
        char const* num_char = tmp.c_str();

        strcat(s1, num_char);
        strcpy(reservNum, s1);
    }
    void SetreservNum_c(char* _reservNum) { strcpy(reservNum, _reservNum); }
    void Setpassword(int _password) { password = _password; }

};

class PassHandler   //PassHandler
{
private:
    TicketList* ticketlist[TIKET_SZ]; // 티켓 정보를 갖는 포인터형 배열
    list<Passenger*> p; //승객 정보를 받을수 있는 포인터형 리스트
    int tkNum; // 티켓 갯수 저장 변수
    list<Passenger*>::iterator it;
    int _countNum = 0;  //  예약번호 생성할 때 쓰이는 변수
public:

    PassHandler() : tkNum(0) { it = p.begin(); } // tkNum을 0으로 초기화 , 이터레이터에 p의 시작지점을 반환함

    ~PassHandler()
    {
        for (int i = 0; i < tkNum; i++)
        {
            delete ticketlist[i]; //  ticketlist[i] 에 있는 동적할당 받은 메모리들 해제
        }
        for (it = p.begin(); it != p.end(); it++)
        {
            delete* it; //  list<Passenger*> p 에 있는 동적할당 받은 메모리들 해제
        }
    }

    string Showcount(TicketList* ticket) // 객체를 포인터형으로 받아옴 , 해당 객체의 count를 참조하여 string 값을 리턴함
    {
        string tmp;
        if (ticket->Getcount() == 0)
        {
            tmp = "매진";
            return tmp;
        }
        else
        {
            tmp = to_string(ticket->Getcount());
            return tmp;
        }
    }

    void Make_Ticket(TicketList* tmp)   //객체를 포인터형으로 받아 ticketlist에 순차적으로 저장
    {
        ticketlist[tkNum++] = tmp;
    }

    void ShowData()
    {
        cout << endl << endl;
        cout << "==============================================================================" << endl;
        cout << right << setw(10) << "편명" << setw(20) << "목적지" << setw(20) << "출발시간"
            << setw(20) << "잔여 좌석" << endl;
        cout << "==============================================================================" << endl;

        for (int i = 0; i < tkNum; i++) // 이쁘게 정렬하여 보여주며 좌석수가 0이면 "매진"으로 보이게끔 함
        {
            cout << right << setw(10) << ticketlist[i]->GetplaneNum() << setw(20) << ticketlist[i]->Getdestination()
                << setw(20) << ticketlist[i]->Gettime() << setw(20) << Showcount(ticketlist[i]) << endl;
        }
        cout << "==============================================================================" << endl;
        cout << endl << endl;
    }

    virtual void ShowData(Passenger* _passenger) // 승객정보 객체의 주소를 받아와 값을 참조하여 출력
    {

        cout << right << setw(10) << _passenger->GetreservNum() << setw(16) << _passenger->Getname()
            << setw(12) << _passenger->Getage() << setw(25) << _passenger->Getphone() << setw(12) <<
            _passenger->GetplaneNum() << setw(12) << _passenger->Getpassword() <<endl;
    }

    void TicketBuy()
    {
        int found;
        char _name[20];
        char _phone[PHONE_SZ];
        int _age = 1;

        char _ticket[PLANE_SZ];
        int password;

        while (1)
        {
            ShowData(); // 티켓리스트 출력
            found = 1;
            Passenger* pass = new Passenger;

            cout << "예약자 성명 : (종료시:end)";
            cin.getline(_name, 20);
            if (strcmp(_name, "end") == 0) // 매번 먼저 동적할당을 받고 데이터를 넣는 형식이기 때문에 end가 입력되어도 _name에 end가 들어 
            {                               // 있는 채로 동적할당 받은 객체가 존재한다
                delete pass;                // _name에 end만 있는 객체 메모리 해제
                break;
            }
            pass->Setname(_name);   

            while (_age != 0)   // 숫자를 입력받을 때 까지 무한루프
            {
                cout << "예약자 나이 : ";
                cin >> _age;
                if (!cin)
                {
                    cout << "입력 오류!!! 숫자만 입력하세요." << endl;
                    cin.clear();    //  cin의 오류값 초기화
                    cin.ignore(256, '\n');  //버퍼 초기화
                    _age = 1;
                }
                else
                {
                    cin.ignore(256, '\n');
                    break; // 숫자입력받으면 엔터값 지우고 break
                }
            }
            pass->Setage(_age);

            cout << "예약자 phone-number (-사용하여 입력) : ";
            cin.getline(_phone, PHONE_SZ);
            pass->Setphone(_phone);

            while (found)
            {
                cout << "예약 할 항공편 명 : ";
                cin.getline(_ticket, PLANE_SZ);


                for (int i = 0; i < tkNum; i++)
                {
                    if (strcmp(ticketlist[i]->GetplaneNum(), _ticket) == 0) // 티켓 리스트에 입력받은 편명이 있는지 확인
                    {
                        ticketlist[i]->Setcount(-1);    // 있으면 좌석수 -1
                        found = 0;
                        pass->SetplaneNum2(_ticket);
                        break;
                    }
                }
                if (found)  // 티켓 리스트에서 편명 못찾으면 출력
                {
                    cout << endl << endl;

                    cout << "*************************    일치하는 것이 없습니다.    **********************" << endl << endl;
                }

            }
            do {
                cout << "비밀번호 숫자 4자리를 입력하세요.";
                cin >> password;
                cin.clear();
                cin.ignore(256, '\n');
            } while (cin.fail()); // 숫자만 입력받게 함
            pass->Setpassword(password);

            pass->SetreservNum(_countNum); // 예약번호 생성



            cout << endl << "******************************************************************************" << endl;
            cout << "     예약자 성명 : " << pass->Getname() << ",  나이 : " << pass->Getage()
                << ",  Phone번호 : " << pass->Getphone() << ",   편명 : " << pass->GetplaneNum() << endl << endl;
            cout << "                        예약 번호는 : " << pass->GetreservNum() << "입니다.                          " << endl;
            cout << "******************************************************************************" << endl;
            p.push_back(pass);  // list에 추가


        }

    }

    void ShowPassenger_start()
    {
        cout << "==============================================================================" << endl;
        cout << right << setw(10) << "예약번호" << setw(20) << "예약자 성명" << setw(10) << "나이"
            << setw(25) << "예약자 Phone번호" << setw(12) << "편명" << endl;
        cout << "==============================================================================" << endl;
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

        cout << endl << "                                    <예약 검색>                             " << endl << endl;

        while (1)
        {
            cout << "\n검색할 예약 번호를 입력하세요 ? (검색종료:end) ";
            cin.getline(s_reservNum, 20);
            if (strcmp(s_reservNum, "end") == 0)
                break;

            found = 1;

            for (it = p.begin(); it != p.end(); it++)
            {
                getreservNum = (*it)->GetreservNum();
                if (strcmp(getreservNum, s_reservNum) == 0) // 검색할 예약번호와 일치하는게 있는지 확인 후 출력
                {
                    found = 0;
                    cout << endl << endl;
                    ShowPassenger_start();
                    ShowData(*it);
                    cout << endl;

                }
            };

            if (found) // 못찾으면 출력
                cout << s_reservNum << ", 찾을 수 없습니다 !!! " << endl;

        }//while (1) end

        ShowPassenger_end();
    }

    void showReservation()
    {
        cout << endl;
        cout << "예약정보 출력" << endl;
        cout << endl << "                                  <예약 정보 출력>                           " << endl << endl;
        
        cout << "============================================================================================" << endl;
        cout << right << setw(10) << "예약번호" << setw(20) << "예약자 성명" << setw(10) << "나이"
            << setw(25) << "예약자 Phone번호" << setw(12) << "편명" << setw(12) << "비밀번호" << endl;
        cout << "============================================================================================" << endl;

        for (it = p.begin(); it != p.end(); it++)
        {
            ShowData(*it); // 리스트에 존재하는 값들 출력
        }
        cout << "============================================================================================" << endl;
        cout << endl << endl;
    }

    void ReservationCancel()
    {
        Passenger* pass; // ㄷ
        int found, choice = 0, stop = 1, password = 1;
        char s_reservNum[20], * getreservNum;
        char* c_planeNum;
        int getpassword;


        cout << endl << "                                    <예약 취소>                             " << endl << endl;

        while (1)
        {
            it = p.begin();
            cout << "\n취소할 예약 번호를 입력하세요. (검색종료:end) ";
            cin.getline(s_reservNum, 20);

            if (strcmp(s_reservNum, "end") == 0)
                break;
            found = 1;

            while (password != 0)
            {
                cout << "비밀번호 숫자 4자리를 입력하세요.";
                cin >> password;
                if (!cin) // 숫자만 입력받음
                {
                    cout << "입력 오류!!! 숫자만 입력하세요." << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    password = 1;
                }
                else
                {
                    cin.ignore(256, '\n');
                    break;
                }
            }

            while (it != p.end())   // list의 갯수만큼 반복
            {
                getreservNum = (*it)->GetreservNum();
                getpassword = (*it)->Getpassword();
                pass = *it;
                if (getpassword == password && !strcmp(getreservNum, s_reservNum)) // 입력받은 예약번호와 비밀번호가 동시에 일치하는지 확인
                {

                    found = 0; //찾음
                    c_planeNum = (*it)->GetplaneNum();  // 취소할 편명 대입
                    for (int i = 0; i < tkNum; i++)
                    {
                        if (strcmp(c_planeNum, ticketlist[i]->GetplaneNum()) == 0)  // 취소할 편명이 티켓 리스트 명단에 있는지 확인
                            ticketlist[i]->Setcount(+1);    // 있으면 좌석수 다시 1 더해줌
                    }
                    delete pass;    // 해당 리스트 열을 지우기 전 먼저 동적할당된 메모리 해제
                    it = p.erase(it);   // 해당 리스트 열 삭제 후 다음 열의 주소를 가리킴(이어줌 = link )
                    cout << "*********************************   취소 완료   ******************************" << endl << endl;


                    break;
                }
                else
                {
                    it++; // 입력받은 예약번호와 비밀번호가 동시에 일치할때까지 위치 ++
                    if (getpassword != password && !strcmp(getreservNum, s_reservNum)) // 편명은 있는데 비밀번호가 다른지 확인
                    {
                        found = -1; // 찾기 오류
                        cout << "비밀번호 오류!!!" << endl;
                    }
                }
            }
            if (found == 1) // 못찾음
                cout << s_reservNum << ", 찾을 수 없습니다 !!! " << endl;
        }
    }


    void ReservationChange()
    {
        Passenger* pass;
        int found, choice = 1, changeAge, stop = 1, password = 1;
        char s_reservNum[20], * getreservNum, changePhone[PHONE_SZ], changePlaneNum[PLANE_SZ];
        char* c_planeNum, changeName[20];
        int getpassword, i;
        it = p.begin();
        cout << endl << "                                    <예약 변경>                             " << endl << endl;

        while (1)
        {
            it = p.begin();
            cout << "\n변경할 예약 번호를 입력하세요. (검색종료:end) ";
            cin.getline(s_reservNum, 20);
            cout << endl;

            if (strcmp(s_reservNum, "end") == 0)
                break;
            found = 1;

            while (password != 0)
            {
                cout << "비밀번호 숫자 4자리를 입력하세요.";
                cin >> password;
                cout << endl;
                if (!cin)
                {
                    cout << "입력 오류!!! 숫자만 입력하세요." << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << endl;
                    password = 1;
                }
                else
                {
                    cin.ignore(256, '\n');
                    cout << endl;
                    break;
                }
            }

            for (it = p.begin(); it != p.end(); it++) // p 리스트의 처음부터 끝까지 ++하며 반복
            {
                getreservNum = (*it)->GetreservNum();
                getpassword = (*it)->Getpassword();
                pass = *it;

                if (getpassword == password && !strcmp(getreservNum, s_reservNum)) // 입력받은 예약번호와 비밀번호가 동시에 일치하는지 확인
                {

                    found = 0;
                    c_planeNum = (*it)->GetplaneNum();  // 취소할 편명 대입
                    for ( i = 0; i < tkNum; i++) // 저장되어 있는 티켓리스트 갯수만큼 반복
                    {
                        if (strcmp(c_planeNum, ticketlist[i]->GetplaneNum()) == 0) // 취소할 편명이 티켓명단에 있는지 확인
                        {
                            ticketlist[i]->Setcount(+1); // 항공편명 변경을 위한 큰그림 ( 미리 취소할 항공편명의 좌석수 +1)
                            break;
                        }

                    }

                    while (choice != 0)
                    {

                        cout << "==============================================================================" << endl;
                        cout << "변경 할 정보를 선택해 주세요." << endl;
                        cout << endl;
                        cout << "      1.성명      2.나이      3. 연락처      4. 항공편      5. 나가기" << endl;
                        cout << "==============================================================================" << endl;
                        cin >> choice;
                        if (!cin) // 숫자만 입력
                        {
                            cout << "입력 오류!!! 숫자만 입력하세요." << endl << endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                           
                            choice = 1;
                        }
                        else
                        {
                            cin.ignore(256, '\n');
                            break;
                        }
                    }

                    switch (choice)
                    {
                    case 1:
                    {
                        cout << "변경 할 이름을 입력하세요.";
                        cin.getline(changeName, 20);
                        (*it)->Setname(changeName);
                        ticketlist[i]->Setcount(-1); // 아까 큰그림으로 +1 했던거 원상복귀
                        cout << endl;
                    }
                    break;
                    case 2:
                    {
                        cout << "변경 할 나이을 입력하세요.";
                        cin >> changeAge;
                        (*it)->Setage(changeAge);
                        ticketlist[i]->Setcount(-1);  // 아까 큰그림으로 +1 했던거 원상복귀
                        cout << endl;
                    }
                    break;
                    case 3:
                    {
                        cout << "변경 할 연락처을 입력하세요.";
                        cin.getline(changePhone, 15);
                        (*it)->Setphone(changePhone);
                        ticketlist[i]->Setcount(-1);  // 아까 큰그림으로 +1 했던거 원상복귀
                        cout << endl;
                    }
                    break;
                    case 4:
                    {
                        cout << "변경 할 항공편을 입력하세요.";
                        cin.getline(changePlaneNum, PLANE_SZ);
                        (*it)->SetplaneNum2(changePlaneNum);
                        for (int j = 0; j < tkNum; j++)
                        {
                            if (strcmp(changePlaneNum, ticketlist[j]->GetplaneNum()) == 0) // 변경할 항공편명이 티켓명단에 있는지 확인
                            {
                                ticketlist[j]->Setcount(-1); // 변경할 위치의 좌석수를 -1
                                break;
                            }
                        }
                        cout << endl;
                    }
                    break;
                    case 5: stop = 0;
                        break;
                    }

                    cout << "*******************************   변경 완료   ********************************" << endl << endl;
                    cout << "   예약자 성명 : " << (*it)->Getname() << ",  나이 : " << (*it)->Getage()
                        << ",  Phone번호 : " << (*it)->Getphone() << ",   편명 : " << (*it)->GetplaneNum() << endl << endl;
                    cout << "                        예약 번호는 : " << (*it)->GetreservNum() << "입니다.                          " << endl;
                    cout << "******************************************************************************" << endl;

                }
                else // 입력받은 예약번호와 비밀번호가 동시에 일치하지 않으면
                {

                    if (getpassword != password && !strcmp(getreservNum, s_reservNum)) // 편명은 같고 비밀번호가 다른경우
                    {
                        found = -1; // 찾기 오류
                        cout << "비밀번호 오류!!!" << endl;
                    }
                }

            }
            if (found == 1) // 못찾으면
                cout << s_reservNum << ", 찾을 수 없습니다 !!! " << endl;

        }

    }

    void Add_TicketList()
    {
        char _planeNum[PLANE_SZ]; //planeNum
        char _destination[30];
        char _time[20];
        int _count = 1;


        while (1)
        {
            cout << "추가할 항공편의 이름을 입력하세요. : (종료시:end)";
            cin.getline(_planeNum, 20);
            if (strcmp(_planeNum, "end") == 0) // 종료시 변경된 티켓 좌석수 저장 후 바로 불러오기(업데이트)
            {
                Save_TicketData();
                Load_TIcketData();
                break;
            }

            cout << "추가할 항공편의 목적지를 입력하세요. : ";
            cin.getline(_destination, 30);

            cout << "추가할 항공편의 출발 시간을 입력하세요. : ";
            cin.getline(_time, 20);

            while (_count != 0) // 숫자만 입력
            {
                cout << "추가할 항공편의 좌석 수를 입력하세요. : ";
                cin >> _count;
                if (!cin)
                {
                    cout << "입력 오류!!! 숫자만 입력하세요." << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    _count = 1;
                }
                else
                {
                    cin.ignore(256, '\n');
                    break;
                }
            }
            Make_Ticket(new TicketList(_planeNum, _destination, _time, _count)); // 임시 변수에 입력받아 티켓리스트 동적할당 후 배열에 추가

            cout << endl << endl << "******************************************************************************" << endl;
            cout << "  편명 : " << _planeNum << ",    목적지 : " << _destination
                << ",    출발시간 : " << _time << ",    잔여 좌석 : " << _count << endl << endl;
            cout << "                             항공편이 생성되었습니다.                                  " << endl;
            cout << "******************************************************************************" << endl << endl << endl;
        }

    }


    void Admin()
    {
        int adminPW;

        cout << endl << "관리자 비밀번호를 입력해주세요.";
        cin >> adminPW;

        if (adminPW != 111111)
            cout << endl << "비밀번호가 다릅니다!! " << endl;

        else
        {
            int choice, stop = 1;

            while (stop)
            {
                do {
                    cout << endl;
                    cout << "==============================================================================" << endl;
                    cout << "                                   <관리자모드>                                " << endl;
                    cout << "==============================================================================" << endl;
                    cout << endl << "1. 예약정보 저장" << endl << endl;
                    cout << "2. 예약정보 출력" << endl << endl;
                    cout << "3. 항공편 추가" << endl << endl;
                    cout << "4. 종료" << endl << endl;
                    cout << "Select (1~4) ?";
                    cin >> choice;
                    cin.clear();
                    cin.ignore(256, '\n');
                } while (cin.fail()); // 숫자만 입력

                switch (choice)
                {
                case 1: Save_PassengerData();
                    break;
                case 2: showReservation();
                    break;
                case 3: Add_TicketList();
                    break;
                case 4: stop = 0;
                    break;
                }
            }
        }

    }
    void Save_TicketData()
    {

        const char* file_Ticket = "Ticket.txt";
        string input_name, output_name;
        ofstream fout_Ticket(file_Ticket, ios::out); // 쓰기모드로 열기
        if (!fout_Ticket)
        {
            cout << "Ticket.txt 파일을 열 수 없음";
            return;
        }

        fout_Ticket << tkNum << endl; // 저장되어있는 비행기 명단의 갯수를 저장
        for (int i = 0; i < tkNum; i++)
        {
            fout_Ticket << ticketlist[i]->GetplaneNum() << " ";
            fout_Ticket << ticketlist[i]->Getdestination() << " ";
            input_name = ticketlist[i]->Gettime();
            output_name = regex_replace(input_name, regex(" "), "　"); // 일반 공백을 특수문자 공백으로 바꾸는 과정
            fout_Ticket << output_name << " ";
            fout_Ticket << ticketlist[i]->Getcount() << endl;

        }
        fout_Ticket.close();
        cout << "[ Ticket.txt에 저장 완료 ]" << endl;
    }

    void Load_TIcketData()
    {
        char planeNum[PLANE_SZ]; //planeNum
        char destination[30];
        char time[20];
        int ticketcount;

        for (int i = 0; i < tkNum; i++) // 이전에 할당되어 있던 메모리들 해제
            delete ticketlist[i];   // 파일 시작시에는 핸들러 객체 생성시 tknum이 0으로 초기화되어 반복문이 일어나지 않음
                                    // 파일 실행도중 업데이트때는 기존의 할당된 메모리들 해제

        const char* file_Ticket = "Ticket.txt";

        ifstream fin_Ticket(file_Ticket, ios::in);

        if (!fin_Ticket)
        {
            cout << "Ticket.txt 파일을 열 수 없음";
            return;
        }

        fin_Ticket >> tkNum;                 //파일에 저장된 비행기 명단의 갯수를 불러옴

        for (int i = 0; i < tkNum; i++)       //파일에 저장된 각 데이터들을 불러옴
        {
            fin_Ticket >> planeNum;
            fin_Ticket >> destination;
            fin_Ticket >> time;
            fin_Ticket >> ticketcount;
            ticketlist[i] = new TicketList(planeNum, destination, time, ticketcount); // 이전에 메모리를 다 해제했으므로 처음부터 다시 할당
        }
        fin_Ticket.close();
        cout << endl << endl << "==============================================================================" << endl;
    }

    void Save_PassengerData()
    {

        Save_TicketData();

        string input_name, output_name;
        const char* file_Pass = "Passenger.txt";

        ofstream fout(file_Pass, ios::out);
        if (!fout)
        {
            cout << "Passenger.txt 파일을 열 수 없음";
            return;
        }
        fout << p.size() << endl;                      //파일에 리스트  사이즈 저장
        for (it = p.begin(); it != p.end(); it++)      // 파일에 리스트 데이터 순차적으로 저장
        {
            input_name = (*it)->Getname();
            output_name = regex_replace(input_name, regex(" "), "　"); // 일반 공백을 특수문자 공백으로 바꾸는 과정
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
        char phone[PHONE_SZ];
        char planeNum2[PLANE_SZ] = "";
        char reservNum[20];
        int password = 0;

        Load_TIcketData();

        const char* file_Pass = "Passenger.txt";

        ifstream fin_Pass(file_Pass, ios::in);

        if (!fin_Pass)
        {
            cout << "Passenger.txt 파일을 열 수 없음";
            return;
        }

        fin_Pass >> _countNum;                 //파일에 저장된 count값을 불러옴 = 예약번호 생성시 이 값부터 ++하며 생성

        for (int i = 0; i < _countNum; i++)       //파일에 저장된 각 데이터들을 불러와서 대입
        {
            Passenger* pass = new Passenger; // 동적할당
            fin_Pass >> name;
            fin_Pass >> age;
            fin_Pass >> phone;
            fin_Pass >> planeNum2;
            fin_Pass >> reservNum;
            fin_Pass >> password;
            pass->Setname(name);
            pass->Setage(age);
            pass->Setphone(phone);
            pass->SetplaneNum2(planeNum2);
            pass->SetreservNum_c(reservNum);
            pass->Setpassword(password);

            p.push_back(pass); // list에 동적할당된 객체의 데이터들 추가
        }
        fin_Pass.close();
        cout << "                               INFINITE AIRLINE                               " << endl;
    }

    //Revise();
};
// 예약번호 만들고 예약번호로 찾을 수 있게 찾기
//
int main()
{

    PassHandler handler;

   
    handler.Load_PassengerData(); // 예약리스트 불러오면서 비행기 명단도 불러옴

    int choice, stop = 1;

    //cout << "==============================================================================" << endl;
    //cout << "                               INFINITE AIRLINE                               " << endl;
    cout << "------------------------------------------------------------------------------" << endl << endl;
    cout << "                인피니트 에어라인을 찾아주신 여러분 환영합니다.                 " << endl;
    cout << "        여러분의 여정에 무한한 편안함을 함께하기 위해 최선을 다하겠습니다.       " << endl << endl;
    cout << "==============================================================================" << endl;


    while (stop)
    {

        do {
            cout << "\n1. 항공편 구입" << endl << endl;
            cout << "2. 예약정보 검색" << endl << endl;
            cout << "3. 예약정보 변경" << endl << endl;
            cout << "4. 예약정보 취소" << endl << endl;
            cout << "5. 관리자모드" << endl << endl;
            cout << "6. 종료" << endl << endl;
            cout << "원하시는 메뉴를 선택해 주세요. (1~6) ";
            cin >> choice;
            cin.clear();
            cin.ignore(256, '\n');
        } while (cin.fail()); // 숫자만 입력
        switch (choice)
        {
        case 1: handler.TicketBuy();
            break;
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