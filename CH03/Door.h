//Door.h
// �ζ��� �Լ��� ������Ͽ� ����Ѵ�!!!!
// ========== ������� �ߺ����� �ذ�================= > �ߺ��Ǿ��µ� �̷��� ���ϸ� ������ ������
#ifndef _DOOR_H_ // _DOOR_H_ ��ũ�θ��� ������ ����, ���̸� endif����, �����̸� �׳� ����
// �ѹ��� ���� ��Ų��. == ��������� �ߺ�ȣ��Ǵ��� �ѹ��� ����ǰԲ� �Ѵ�.
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
inline void Door::Open() //�ζ��� �Լ� ����
//void Door::Open()
{
    state = OPEN;
}
#endif