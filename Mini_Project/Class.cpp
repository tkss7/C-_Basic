#include<iostream>
#include<cstring>
#include <iomanip>
#include<vector>
#include<map>
#include<list>
#include<vld.h>
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
public:
	Passenger(const char* planeNum="", const char* destination="", const char* time="", int _count=0,
		const char* name="", int age=0, const char* phone="") : TicketList(planeNum, destination, time, _count)
	{
		strcpy(this->name, name);
		strcpy(this->phone, phone);
		this->age = age;
	}
	char* Getname() { return name; }
	void Setname(const char* _name) { strcpy(name, _name); }
	void Setphone(const char* _phone) { strcpy(phone, _phone); }
	void Setage(int _age) { age = _age; }
	void SetplaneNum2(const char* _plane) { strcpy(planeNum2, _plane); }
	//virtual ShowData;

	void Setname(int age)
	{
		this->age=age;
	}
};

class PassHandler   //PassHandler
{
private:
	TicketList* ticketlist[TIKET_SZ];
	list<Passenger*> p;
	int tkNum;
	list<Passenger*>::iterator it;
public:

	PassHandler() : tkNum(0) { it = p.begin(); }

	~PassHandler()
	{
		for (int i = 0; i < tkNum; i++)
		{
			delete ticketlist[i];
		}
		for (it=p.begin();it!=p.end();it++)
		{
			delete *it;
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

		for (int i = 0; i < TIKET_SZ; i++)
		{
			cout << right << setw(10) <<  ticketlist[i]->GetplaneNum() << setw(20) << ticketlist[i]->Getdestination()
				<< setw(20) << ticketlist[i]->Gettime() << setw(20) << ticketlist[i]->Getcount() << endl;
		}
		cout << "==============================================================================" << endl;
		cout << endl << endl;
	}

	void TicketBuy()
	{	
		int found;
		char _name[10];
		char _phone[14];
		int _age;
		char _ticket[6];
		
		while (1)
		{
			ShowData();
			found = 1;
			Passenger* pass = new Passenger;
			
			cout << "������ ���� : (�����:end)";
			cin.getline(_name, 10);
			if (strcmp(_name, "end") == 0)
			{
				delete pass;
				break;
			}
			pass->Setname(_name);
			
			
			cout << "������ ���� : ";
			cin >> _age;
			cin.ignore(2, '\n');
			
			
			pass->Setage(_age);
			
			
			cout << "������ phone-number (-����Ͽ� �Է�) : ";
			cin.getline(_phone, 14);
			pass->Setphone(_phone);
			
			while (found)
			{
				cout << "���� �� �װ��� �� : ";
				cin.getline(_ticket, 6);
				
				for (int i = 0; i < tkNum; i++)
				{
					if (strcmp(ticketlist[i]->GetplaneNum(), _ticket) == 0)
					{
						ticketlist[i]->Setcount(-1);
						found = 0;
						break;
					}		
				}		
				if (found)
					cout << "��ġ�ϴ� ���� �����ϴ�." << endl;
			}		
			pass->SetplaneNum2(_ticket);
			p.push_back(pass);
		}

	}

	//ReservationCheck(); // find

	//virtual ShowData; // output
	 //ReservationChange();

	  //Revise();
};
// �����ȣ ����� �����ȣ�� ã�� �� �ְ� ã��
//
int main()
{

	//map<string, *Passenger>;

	PassHandler handler;

	handler.Make_Ticket(new TicketList("AI001", "������DC", "PM 17:00", 5));
	handler.Make_Ticket(new TicketList("AI002", "����", "PM 1:00", 4));
	handler.Make_Ticket(new TicketList("CI015", "������DC", "PM 12:00", 3));
	handler.Make_Ticket(new TicketList("FI001", "�ν���������", "PM 11:00", 2));
	handler.Make_Ticket(new TicketList("FI021", "�����", "PM 6:00", 1));


	int choice, stop = 1;

	while (stop)
	{

		cout << "\n\n1. ǥ ����" << endl;
		cout << "2. ������� ���" << endl;
		cout << "3. ������� �˻�" << endl;
		cout << "4. ����" << endl;
		cout << "Select ? (1~4) ";
		cin >> choice;
		cin.ignore(2, '\n');
		switch (choice)
		{
		case 1: handler.TicketBuy();
			break;
		case 2: //handler.Output_Emp();
			break;
		case 3: //handler.Find_Emp();
			break;
		case 4: stop = 0;
			break;
		}
	}	//while(1) end

	cout << "End." << endl;

	return 0;

}