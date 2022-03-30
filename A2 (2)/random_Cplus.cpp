#include <iostream>
#include <random>

using namespace std;

int main() 
{
    // �õ尪�� ��� ���� random_device ����.(�ü�� �ܿ��� ����)
    random_device rd;

    // random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
    mt19937 gen(rd());  //C++ ���� ���̺귯��(�޸��� Ʈ������ �˰���)

    // 0 ���� 10 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
    uniform_int_distribution<int> dist(0, 10);

    for (int i = 0; i < 10; i++) 
        cout << dist(gen) << ", ";  //�յ��ȣ�� �������� ����(�����߻�)
    cout << endl;
}