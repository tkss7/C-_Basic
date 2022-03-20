//Door_Class.cpp  03/18
#include <iostream> 
using namespace std;
/*
    매크로 대치
    #define Sum(x,y) x+y

    N=Sum(100, 200) // N= x+y; 매크로함수는  전처리과정에서 <-- 이런식으로 대치해버림 : 함수 호출이 아니라 바로 계산이므로 속도가 빠름

    //클래스안에 정의된 메소드 함수들은 모두 인라인 함수로 처리된다!!!!
    긴 코드는 인라인 함수로 선언하면 긴 코드들이 매 인라인 함수마다 들어가므로 실행코드가 매우 길어진다 -> 이때는 함수 호출방식이 더 빠름
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
inline void Door::Open() //인라인 함수 선언
{
    state = OPEN;
}
void Door::Close()
{
    state = CLOSE;
}
void Door::ShowState()
{
    cout << "현재 문의 상태 : ";
    cout << ((state == OPEN) ? "OPEN" : "CLOSE") << endl;
}
int main()
{
    Door d1;
    d1.ShowState();
    d1.Open(); // state = OPEN; 으로 대체가 일어남
    d1.ShowState();

    d1.Close();
    d1.ShowState();

    return 0;
}