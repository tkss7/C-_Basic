//Door.h
// 인라인 함수는 헤더파일에 줘야한다!!!!
// ========== 헤더파일 중복문제 해걸================= > 중복되었는데 이렇게 안하면 컴파일 에러뜸
#ifndef _DOOR_H_ // _DOOR_H_ 매크로명이 없으면 참임, 참이면 endif까지, 거짓이면 그냥 나감
// 한번만 일을 시킨다. == 헤더파일이 중복호출되더라도 한번만 실행되게끔 한다.
#define _DOOR_H_
const int OPEN = 1;
const int CLOSE = 2;

class Door
{
private:
    int state;

public:

    Door() {}
    inline void Open();
    //void Open();
    void Close();

    void ShowState();

};
inline void Door::Open() //인라인 함수 선언
//void Door::Open()
{
    state = OPEN;
}
#endif