//Data.h
 //클래스가 구체화 될 때 템플릿 클래스는 메소드들을 반드시 헤더파일 안에 두어야 한다.
#ifndef _DATA_ // 이런 헤더파일이 처음이면 한번실행 후 다시는 중복구현이 안된다.
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

template <typename T>	// 아래의 T가 템플릿임을 알린다.
Data<T>::Data(T n) // T타입이템플릿으로 정의된 Data 클래스임을 알린다.
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