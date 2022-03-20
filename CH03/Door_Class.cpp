//Door_Class.cpp  03/18
#include <iostream> 
using namespace std;
/*
    ��ũ�� ��ġ
    #define Sum(x,y) x+y

    N=Sum(100, 200) // N= x+y; ��ũ���Լ���  ��ó���������� <-- �̷������� ��ġ�ع��� : �Լ� ȣ���� �ƴ϶� �ٷ� ����̹Ƿ� �ӵ��� ����

    //Ŭ�����ȿ� ���ǵ� �޼ҵ� �Լ����� ��� �ζ��� �Լ��� ó���ȴ�!!!!
    �� �ڵ�� �ζ��� �Լ��� �����ϸ� �� �ڵ���� �� �ζ��� �Լ����� ���Ƿ� �����ڵ尡 �ſ� ������� -> �̶��� �Լ� ȣ������ �� ����
*/
const int OPEN = 1;
const int CLOSE = 2;

class Door
{
private:
    int state;

public:

    Door() {}
    inline void Open();

    void Close();

    void ShowState();

};
inline void Door::Open() //�ζ��� �Լ� ����
{
    state = OPEN;
}
void Door::Close()
{
    state = CLOSE;
}
void Door::ShowState()
{
    cout << "���� ���� ���� : ";
    cout << ((state == OPEN) ? "OPEN" : "CLOSE") << endl;
}
int main()
{
    Door d1;
    d1.ShowState();
    d1.Open(); // state = OPEN; ���� ��ü�� �Ͼ
    d1.ShowState();

    d1.Close();
    d1.ShowState();

    return 0;
}