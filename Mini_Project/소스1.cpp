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
#define TIKET_SZ 20
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
    char reservNum[6];
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
    void SetreservNum(int& _countNum)
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
        cout << right << setw(10) << "���" << setw(20) << "������" << setw(20) << "��߽ð�"
            << setw(20) << "�ܿ� �¼�" << endl;

        for (int i = 0; i < tkNum; i++)
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
        int _age = 1;

        char _ticket[6];
        int password;

        while (1)
        {
            ShowData();
            found = 1;
            Passenger* pass = new Passenger;

            cout << "������ ���� : (�����:end)";
            cin.getline(_name, 20);
            if (strcmp(_name, "end") == 0)
            {
                delete pass;
                break;
            }
            pass->Setname(_name);

            while (_age != 0)
            {
                cout << "������ ���� : ";
                cin >> _age;
                if (!cin)
                {
                    cout << "�Է� ����!!! ���ڸ� �Է��ϼ���." << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    _age = 1;
                }
                else
                {
                    cin.ignore(256, '\n');
                    break;
                }
            }
            pass->Setage(_age);


            cout << "������ phone-number (-����Ͽ� �Է�) : ";
            cin.getline(_phone, 14);
            pass->Setphone(_phone);

            while (found)
            {
                cout << "���� �� �װ��� �� : ";
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
                    cout << "��ġ�ϴ� ���� �����ϴ�." << endl;
            }

            do {
                cout << "��й�ȣ ���� 4�ڸ��� �Է��ϼ���." << endl;
                cin >> password;
                cin.clear();
                cin.ignore(256, '\n');
            } while (cin.fail());
            pass->Setpassword(password);

            //pass->SetplaneNum2(_ticket);

            pass->SetreservNum(_countNum);

            cout << "======================================" << endl;
            cout << "���� ��ȣ�� : " << pass->GetreservNum() << "�Դϴ�." << endl;
            cout << "======================================" << endl;
            p.push_back(pass);


        }

    }

    void ShowPassenger_start()
    {
        cout << "==============================================================================" << endl;
        cout << right << setw(10) << "�����ȣ" << setw(20) << "������ ����" << setw(10) << "����"
            << setw(25) << "������ Phone��ȣ" << setw(12) << "���" << endl;
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

        cout << endl << "���� Ȯ��" << endl << endl;


        while (1)
        {
            cout << "\n�˻��� ���� ��ȣ�� �Է��ϼ��� ? (�˻�����:end) ";
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
        cout << "�������� ���" << endl;
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
        int found, choice = 0, stop = 1, password = 1;
        char s_reservNum[20], * getreservNum;
        char* c_planeNum;
        int getpassword;

        cout << "���� ���" << endl;

        while (1)
        {
            it = p.begin();
            cout << "\n����� ���� ��ȣ�� �Է��ϼ���. (�˻�����:end) ";
            cin.getline(s_reservNum, 20);   //lee, kim, sun, ... end

            if (strcmp(s_reservNum, "end") == 0)
                break;
            found = 1;

            while (password != 0)
            {
                cout << "��й�ȣ ���� 4�ڸ��� �Է��ϼ���.";
                cin >> password;
                if (!cin)
                {
                    cout << "�Է� ����!!! ���ڸ� �Է��ϼ���." << endl;
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

            while (it != p.end())
            {
                //cin.clear();
                getreservNum = (*it)->GetreservNum();
                getpassword = (*it)->Getpassword();
                pass = *it;
                if (getpassword == password && !strcmp(getreservNum, s_reservNum))
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
                    cout << "***********************   ��� �Ϸ�   ***********************" << endl << endl;

                    break;
                }
                else
                {
                    it++;
                    if (getpassword != password && !strcmp(getreservNum, s_reservNum))
                    {
                        found = -1;
                        cout << "��й�ȣ ����!!!" << endl;
                    }
                }
            }
            if (found == 1)
                cout << s_reservNum << ", Not found !!! " << endl;
        }
    }






    void ReservationChange()
    {
        Passenger* pass;
        int found, choice = 1, changeAge, stop = 1, password = 1;
        char s_reservNum[20], * getreservNum, changePhone[14], changePlaneNum[6];
        char* c_planeNum, changeName[20];
        int getpassword;
        it = p.begin();
        cout << "\n���� ����" << endl << endl;

        while (1)
        {
            it = p.begin();
            cout << "\n������ ���� ��ȣ�� �Է��ϼ���. (�˻�����:end) ";
            cin.getline(s_reservNum, 20);   //lee, kim, sun, ... end

            if (strcmp(s_reservNum, "end") == 0)
                break;
            found = 1;

            while (password != 0)
            {
                cout << "��й�ȣ ���� 4�ڸ��� �Է��ϼ���.";
                cin >> password;
                if (!cin)
                {
                    cout << "�Է� ����!!! ���ڸ� �Է��ϼ���." << endl;
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



            for (it = p.begin(); it != p.end(); it++)
            {

                getreservNum = (*it)->GetreservNum();
                getpassword = (*it)->Getpassword();
                pass = *it;

                if (getpassword == password && !strcmp(getreservNum, s_reservNum))
                {

                    found = 0;
                    c_planeNum = (*it)->GetplaneNum();
                    for (int i = 0; i < TIKET_SZ; i++)
                    {
                        if (strcmp(c_planeNum, ticketlist[i]->GetplaneNum()) == 0)
                            ticketlist[i]->Setcount(+1);
                    }

                    //do {
                    //    cout << "=============================================================" << endl;
                    //    cout << "  ���� �� ������ ������ �ּ���." << endl;
                    //    cout << endl;
                    //    cout << "   1.����    2.����    3. ����ó    4. �װ���    5. ������" << endl;
                    //    cout << "=============================================================" << endl;
                    //    //TicketBuy();

                    //    cin >> choice;
                    //    cin.clear();
                    //    cin.ignore(256, '\n');
                    //} while (cin.fail());

                    while (choice != 0)
                    {
                        cout << "=============================================================" << endl;
                        cout << "  ���� �� ������ ������ �ּ���." << endl;
                        cout << endl;
                        cout << "   1.����    2.����    3. ����ó    4. �װ���    5. ������" << endl;
                        cout << "=============================================================" << endl;
                        cin >> choice;
                        if (!cin)
                        {
                            cout << "�Է� ����!!! ���ڸ� �Է��ϼ���." << endl << endl;
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
                        cout << "  ���� �� �̸��� �Է��ϼ���." << endl;
                        cin.getline(changeName, 20);
                        (*it)->Setname(changeName);
                    }
                    break;
                    case 2:
                    {
                        cout << "  ���� �� ������ �Է��ϼ���." << endl;
                        cin >> changeAge;
                        (*it)->Setage(changeAge);
                    }
                    break;
                    case 3:
                    {
                        cout << "  ���� �� ����ó�� �Է��ϼ���." << endl;
                        cin.getline(changePhone, 15);
                        (*it)->Setphone(changePhone);
                    }
                    break;
                    case 4:
                    {
                        cout << "  ���� �� �װ����� �Է��ϼ���." << endl;
                        cin.getline(changePlaneNum, 2);
                        (*it)->SetplaneNum2(changePlaneNum);
                    }
                    break;
                    case 5: stop = 0;
                        break;
                    }
                    cout << "***********************   ���� �Ϸ�   ***********************" << endl << endl;


                    cout << "  ���� ��ȣ�� : " << (*it)->GetreservNum() << "�Դϴ�." << endl;

                    cout << "=============================================================" << endl;

                }
                else
                {

                    if (getpassword != password && !strcmp(getreservNum, s_reservNum))
                    {
                        found = -1;
                        cout << "��й�ȣ ����!!!" << endl;
                    }
                }

            }
            if (found == 1)
                cout << s_reservNum << ", Not found !!! " << endl;

        }

    }

    //void TicketSave()

//while (1) end


    void Add_TicketList()
    {
        char _planeNum[6]; //planeNum
        char _destination[30];
        char _time[20];
        int _count = 1;


        while (1)
        {
            cout << "�߰��� �װ����� �̸��� �Է��ϼ���. : (�����:end)";
            cin.getline(_planeNum, 20);
            if (strcmp(_planeNum, "end") == 0)
            {
                Save_TicketData();
                Load_TIcketData();
                break;
            }

            cout << "�߰��� �װ����� �������� �Է��ϼ���. : ";
            cin.getline(_destination, 30);

            cout << "�߰��� �װ����� ��� �ð��� �Է��ϼ���. : ";
            cin.getline(_time, 20);



            while (_count != 0)
            {
                cout << "�߰��� �װ����� �¼� ���� �Է��ϼ���. : ";
                cin >> _count;
                if (!cin)
                {
                    cout << "�Է� ����!!! ���ڸ� �Է��ϼ���." << endl;
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

            Make_Ticket(new TicketList(_planeNum, _destination, _time, _count));

        }

    }


    void Admin()
    {
        int adminPW;

        cout << "������ ��й�ȣ�� �Է����ּ���." << endl;
        cin >> adminPW;

        if (adminPW != 111111)
            cout << "��й�ȣ�� �ٸ��ϴ�!! " << endl;

        else
        {
            int choice, stop = 1;

            while (stop)
            {
                do {
                    cout << "1. �������� ����" << endl;
                    cout << "2. �������� ���" << endl;
                    cout << "3. �װ��� �߰�." << endl;
                    cout << "4. ����." << endl;
                    cout << "Select (1~4) ?" << endl;
                    cin >> choice;
                    cin.clear();
                    cin.ignore(256, '\n');
                } while (cin.fail());

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
        ofstream fout_Ticket(file_Ticket, ios::out);
        if (!fout_Ticket)
        {
            cout << "Ticket.txt ������ �� �� ����";
            return;
        }

        fout_Ticket << tkNum << endl;                      //���Ͽ� count �� ����
        for (int i = 0; i < tkNum; i++)                   //0���� count��°��ŭ (�� �Էµ� ��ȿ�ݺ�Ƚ����ŭ) ���Ͽ� ������ ������ ����
        {
            fout_Ticket << ticketlist[i]->GetplaneNum() << " ";
            fout_Ticket << ticketlist[i]->Getdestination() << " ";
            input_name = ticketlist[i]->Gettime();
            output_name = regex_replace(input_name, regex(" "), "��");
            fout_Ticket << output_name << " ";
            fout_Ticket << ticketlist[i]->Getcount() << endl;

        }
        fout_Ticket.close();
        cout << "[ Ticket.txt�� ���� �Ϸ� ]" << endl;
    }

    void Load_TIcketData()
    {
        char planeNum[6]; //planeNum
        char destination[30];
        char time[20];
        int ticketcount;


        const char* file_Ticket = "Ticket.txt";

        ifstream fin_Ticket(file_Ticket, ios::in);

        if (!fin_Ticket)
        {
            cout << "Ticket.txt ������ �� �� ����";
            return;

        }

        fin_Ticket >> tkNum;                 //���Ͽ� ����� count���� �ҷ���

        for (int i = 0; i < tkNum; i++)       //���Ͽ� ����� �� �����͵��� �ҷ���
        {
            fin_Ticket >> planeNum;
            fin_Ticket >> destination;
            fin_Ticket >> time;
            fin_Ticket >> ticketcount;
            ticketlist[i] = new TicketList(planeNum, destination, time, ticketcount);
            //Book class�� �Ű����� ������ ȣ�� �� fin���� �Է¹��� ������ �ѱ�
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
            cout << "Passenger.txt ������ �� �� ����";
            return;
        }
        fout << p.size() << endl;                      //���Ͽ� count �� ����
        for (it = p.begin(); it != p.end(); it++)                   //0���� count��°��ŭ (�� �Էµ� ��ȿ�ݺ�Ƚ����ŭ) ���Ͽ� ������ ������ ����
        {
            input_name = (*it)->Getname();
            output_name = regex_replace(input_name, regex(" "), "��");
            fout << output_name << " ";
            fout << (*it)->Getage() << " ";
            fout << (*it)->Getphone() << " ";
            fout << (*it)->GetplaneNum() << " ";
            fout << (*it)->GetreservNum() << " ";
            fout << (*it)->Getpassword() << endl;

        }
        fout.close();
        cout << "[ Passenger.txt�� ���� �Ϸ� ]" << endl;


    }

    void Load_PassengerData()
    {
        char name[20];
        int age;
        char phone[14];
        char planeNum2[6] = "";
        char reservNum[6];
        int password = 0;

        Load_TIcketData();

        const char* file_Pass = "Passenger.txt";

        ifstream fin_Pass(file_Pass, ios::in);

        if (!fin_Pass)
        {
            cout << "Passenger.txt ������ �� �� ����";
            return;

        }

        fin_Pass >> _countNum;                 //���Ͽ� ����� count���� �ҷ���

        for (int i = 0; i < _countNum; i++)       //���Ͽ� ����� �� �����͵��� �ҷ���
        {
            Passenger* pass = new Passenger;
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

            p.push_back(pass);
            //ticketlist[i] = new TicketList(planeNum, destination, time, ticketcount);
            //Book class�� �Ű����� ������ ȣ�� �� fin���� �Է¹��� ������ �ѱ�
        }

        fin_Pass.close();
        cout << "                               INFINITE AIRLINE                               " << endl;
    }

    //Revise();
};
// �����ȣ ����� �����ȣ�� ã�� �� �ְ� ã��
//
int main()
{

    PassHandler handler;

    /* handler.Make_Ticket(new TicketList("AI001", "������DC", "PM 17:00", 5));
     handler.Make_Ticket(new TicketList("AI002", "����", "PM 1:00", 4));
     handler.Make_Ticket(new TicketList("CI015", "������DC", "PM 12:00", 3));
     handler.Make_Ticket(new TicketList("FI001", "�ν���������", "PM 11:00", 2));
     handler.Make_Ticket(new TicketList("FI021", "�����", "PM 6:00", 1));*/
     //handler.Load_TIcketData();
    handler.Load_PassengerData();

    int choice, stop = 1;

    //cout << "==============================================================================" << endl;
    //cout << "                               INFINITE AIRLINE                               " << endl;
    cout << "------------------------------------------------------------------------------" << endl << endl;
    cout << "                ���Ǵ�Ʈ ��������� ã���ֽ� ������ ȯ���մϴ�.                 " << endl;
    cout << "        �������� ������ ������ ������� �Բ��ϱ� ���� �ּ��� ���ϰڽ��ϴ�.       " << endl << endl;
    cout << "==============================================================================" << endl;


    while (stop)
    {

        do {
            cout << "\n1. �װ��� ����" << endl;
            cout << "2. �������� �˻�" << endl;
            cout << "3. �������� ����" << endl;
            cout << "4. �������� ���" << endl;
            cout << "5. �����ڸ��" << endl;
            cout << "6. ����" << endl << endl;
            cout << "���Ͻô� �޴��� ������ �ּ���. (1~6) ";
            cin >> choice;
            cin.clear();
            cin.ignore(256, '\n');
        } while (cin.fail());
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