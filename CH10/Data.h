//Data.h
 //Ŭ������ ��üȭ �� �� ���ø� Ŭ������ �޼ҵ���� �ݵ�� ������� �ȿ� �ξ�� �Ѵ�.
#ifndef _DATA_ // �̷� ��������� ó���̸� �ѹ����� �� �ٽô� �ߺ������� �ȵȴ�.
#define _DATA_

template <typename T>
class Data
{
private:
	T data;
public:
	Data(T n);


	void setData(T n);

	T getData();

};

template <typename T>	// �Ʒ��� T�� ���ø����� �˸���.
Data<T>::Data(T n) // TŸ�������ø����� ���ǵ� Data Ŭ�������� �˸���.
{
	data = n;
}

template <typename T>
void Data<T>::setData(T n)
{
	data = n;
}

template <typename T>
T Data<T>::getData()
{
	return data;
}

#endif