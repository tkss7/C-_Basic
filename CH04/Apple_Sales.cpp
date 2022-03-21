////Apple_Sales.cpp
#include<iostream>
using namespace std;
// 상수는 콜론초기화 해야 한다.

class AppSeller //판매자 클래스
{
private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	AppSeller(int price, int num, int money) : APPLE_PRICE(price)// 상수는 콜론초기화 해야 한다.
	{
		numOfApples = num;
		myMoney = money;
	}

	void  ShowSellerResult()const
	{
		cout << "판매할 사과 수량 : " << numOfApples << endl;
		cout << "판매수익 : " << myMoney << endl;
	}

	int SaleApples(int money)
	{
		int n = money / APPLE_PRICE;

		if (n > numOfApples)
		{
			cout << "남아있는 사과 수량은: " << numOfApples << endl;
			cout << "구매할 최대금액 : " << numOfApples * APPLE_PRICE;

			return 0;
		}

		numOfApples -= n;
		myMoney += money;
		return n;
	}
};

class AppBuyer //구매자 클래스
{
private:
	int numOfApples;
	int myMoney;
public:

	AppBuyer(int money)
	{
		numOfApples = 0;
		myMoney = money;
	}
	//객체간의 통신 (메시지 전달)
	void BuyApples(AppSeller& _seller, int money)
	{
		if (money <= 0)
		{
			cout << "구매금액은 0원 이상 !!!" << endl;
			return;
		}
		if (money > myMoney) {
			cout << "남아있는 금액은 :" << myMoney << endl;
			cout << "이 금액 이하로 구입하세요" << endl;
			return;
		}
		//numOfApples += _seller.SaleApples(money);//판매할 사과개수
		//myMoney -= money;

		int ret = _seller.SaleApples(money);
		if (ret!= 0)
		{
			numOfApples+=ret;
			myMoney -= money;
		}
	}

	void ShowSellerResult() const
	{
		cout << "구입한 사과 개수 : " << numOfApples << endl;
		cout << "현재 잔액 : " << myMoney << endl;
	}
};

int main()
{
	AppSeller seller(1000, 20, 0);
	AppBuyer buyer(50000);

	seller.ShowSellerResult();
	buyer.ShowSellerResult();
	cout << "=====================\n";
	buyer.BuyApples(seller, 2000);

	seller.ShowSellerResult();
	buyer.ShowSellerResult();
	cout << "=====================\n";
	buyer.BuyApples(seller, 300000);
	seller.ShowSellerResult();
	buyer.ShowSellerResult();

	buyer.BuyApples(seller, -3000);
    buyer.BuyApples(seller, 70000);
    cout << "===========================" << endl;

    buyer.BuyApples(seller, 30000);

	return 0;
}

//#include<iostream>
//using namespace std;
//
//class AppSeller    //판매자 클래스
//{
//private:
//    const int APPLE_PRICE;
//    int numOfApples;
//    int myMoney;
//
//public:
//    void ShowSellerResult() const
//    {
//        cout << "판매할 사과 수량 : " << numOfApples << endl;
//        cout << "판매할 수익 : " << myMoney << endl;
//
//    }
//
//    AppSeller(int price, int num, int money) :APPLE_PRICE(price)          //상수는 반드시 콜론초기화
//    {
//        numOfApples = num;
//        myMoney = money;
//    }
//
//    int SaleApples(int money)
//    {
//        int n = money / APPLE_PRICE;
//
//        if (n > numOfApples)
//        {
//            cout << "남아있는 사과 수량은 : " << numOfApples << endl;
//            cout << "구매할 최대 금액은 : " << numOfApples * APPLE_PRICE;
//
//            return 0;
//        }
//
//        numOfApples -= n;
//        myMoney += money;
//
//        return n;
//    }
//
//};
//
//class AppBuyer  //구매자 클래스
//{
//private:
//    int numOfApples;
//    int myMoney;
//
//public:
//    void ShowBuyerResult() const
//    {
//        cout << "구입한 사과 개수 : " << numOfApples << endl;
//        cout << "현재 잔액 : " << myMoney << endl;
//    }
//
//    AppBuyer(int money)
//    {
//        numOfApples = 0;
//        myMoney = money;
//    }
//
//    //메세지 전달 : 객체간의 통신은 메세지에 의해서 의사전달을하는데,
//    //이러한 메세지는 그 객체에 있는 메서드를 호출하는 것이다
//    void BuyApples(AppSeller& _seller, int money)
//    {
//        if (money <= 0)
//        {
//            cout << "구매금액은 0원 이상이여야 함" << endl;
//            return;
//        }
//
//        if (money > myMoney)
//        {
//            cout << "남아있는 금액 : " << myMoney << endl;
//            cout << "이 금액 이하로 구입하세요" << endl;
//            return;
//        }
//
//        int ret = _seller.SaleApples(돈);
//
//        if (ret != 0)
//        {
//            numOfApples += ret;
//            myMoney -= money;
//        }
//
//        //numOfApples += _seller.SaleApples(돈);
//        //myMoney -= money;
//    }
//
//};
//
//int main()
//{
//    AppSeller seller(1000, 20, 0);
//    AppBuyer buyer(50000);
//
//    seller.ShowSellerResult();
//    buyer.ShowBuyerResult();
//    cout << "===========================" << endl;
//
//    buyer.BuyApples(seller, 2000);
//    seller.ShowSellerResult();
//    buyer.ShowBuyerResult();
//    cout << "===========================" << endl;
//
//    buyer.BuyApples(seller, -3000);
//    buyer.BuyApples(seller, 70000);
//    cout << "===========================" << endl;
//
//    buyer.BuyApples(seller, 30000);
//
//    return 0;
//}