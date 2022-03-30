//STL_deque.cpp 03/30
#include <iostream>
#include <deque>

using namespace std;
/*
�� �ڷᱸ���� Queue�� �ٸ� ������ ���԰� ������ ������ �ƴ� ��, �� ���ʿ��� �� �� �ִ�. 
���� Deque�� Stack�� Queue�� ������ ���� ������ FIFO ��İ� LIFO ��� �� �� ����� �� �ִ�.

insert( )�� �����ε��Ǿ� ���� ������ ���� (���� 2���� ���� �ּ�, ��), (���� 3���� ���� �ּ�, Ƚ��, ���� ��)
*/
int main() 
{
	deque<int> deque1, deque2;
	deque<int> ::iterator itr; // ������ �����ѰͰ� ���� : �̷����̷�

	deque1.push_front(100);
	deque1.push_back(200);
	deque1.push_back(300);
	deque1.push_front(400);    // 400 100 200 300

	cout << "< push_front & push_back >" << '\n';
	for (int i = 0; i < deque1.size(); i++)  
		cout << deque1[i] << " ";
	cout << '\n';

	cout << "< front % back >" << '\n';
	cout << deque1.front() << '\n';  //400 , ���� ��ȯ
	cout << deque1.back() << '\n';   //300

	cout << "==============================\n";

	cout << "< pop_front & pop_back >" << '\n';
	deque1.pop_front();  //front ��ġ ���һ���
	deque1.pop_back();   //������ ��ġ ���һ���
	for (int i = 0; i < deque1.size(); i++)   //100, 200
		cout << deque1[i] << " ";
	cout << '\n';

	cout << "< �ݺ��ڷ� ���� >" << '\n';
	itr = deque1.begin(); 
	cout << *itr << '\n';  //100
	++itr;
	cout << *itr << '\n';  //200
	
	cout << '\n' << "< insert >" << '\n';
	itr = deque1.begin();
	deque1.insert(itr, 500);   //500, 100, 200
	// insert( )�� �����ε��Ǿ� ���� ������ ���� (���� 2���� ���� �ּ�, ��), (���� 3���� ���� �ּ�, Ƚ��, ���� ��)
	itr = deque1.begin();  // !!!�߿� : insert()�Ǿ �ٽ� itr �����ϱ�!!!
	++itr;
	deque1.insert(itr, 3, 700);  //500, 700, 700, 700, 100, 200 //itr ��ġ���� 700�� 3�� �߰��Ѵ�.
	for (int i = 0; i < deque1.size(); i++) 
		cout << deque1[i] << " ";
	cout << "\n==================\n\n";
	//STL �����̳� begin, end���� begin���� end���� for�������� �ִ°Ͱ� ����.
	deque2.push_back(20);
	deque2.push_back(30);
	deque2.push_back(40);
	itr = deque1.begin();
	deque1.insert(++itr, deque2.begin(), deque2.end()); //itr�� ��ġ���� deque2�� ���ۺ��� ������ �߰��Ѵ�.
	for (int i = 0; i < deque1.size(); i++) 
		cout << deque1[i] << " ";
	cout << '\n';

	cout << '\n' << "< erase >" << '\n';
	deque1.erase(deque1.begin(), deque1.begin() + 4); //700,700, 700, 100, 200 // deque1.bigin ���� 4���� �����.
	for (int i = 0; i < deque1.size(); i++) 
		cout << deque1[i] << " ";
	cout << '\n';

	cout << "< clear >" << '\n';
	deque1.clear(); //�� �� �����.

	cout << "< empty >" << '\n';
	cout << (deque1.empty() ? "true" : "false") << '\n';
}
