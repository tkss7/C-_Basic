////Apple_Sales.cpp
#include<iostream>
using namespace std;
// ����� �ݷ��ʱ�ȭ �ؾ� �Ѵ�.

class AppSeller //�Ǹ��� Ŭ����
{
private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	AppSeller(int price, int num, int money) : APPLE_PRICE(price)// ����� �ݷ��ʱ�ȭ �ؾ� �Ѵ�.
	{
		numOfApples = num;
		myMoney = money;
	}

	void  ShowSellerResult()const
	{
		cout << "�Ǹ��� ��� ���� : " << numOfApples << endl;
		cout << "�Ǹż��� : " << myMoney << endl;
	}

	int SaleApples(int money)
	{
		int n = money / APPLE_PRICE;

		if (n > numOfApples)
		{
			cout << "�����ִ� ��� ������: " << numOfApples << endl;
			cout << "������ �ִ�ݾ� : " << numOfApples * APPLE_PRICE;

			return 0;
		}

		numOfApples -= n;
		myMoney += money;
		return n;
	}
};

class AppBuyer //������ Ŭ����
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
	//��ü���� ��� (�޽��� ����)
	void BuyApples(AppSeller& _seller, int money)
	{
		if (money <= 0)
		{
			cout << "���űݾ��� 0�� �̻� !!!" << endl;
			return;
		}
		if (money > myMoney) {
			cout << "�����ִ� �ݾ��� :" << myMoney << endl;
			cout << "�� �ݾ� ���Ϸ� �����ϼ���" << endl;
			return;
		}
		//numOfApples += _seller.SaleApples(money);//�Ǹ��� �������
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
		cout << "������ ��� ���� : " << numOfApples << endl;
		cout << "���� �ܾ� : " << myMoney << endl;
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
//class AppSeller    //�Ǹ��� Ŭ����
//{
//private:
//    const int APPLE_PRICE;
//    int numOfApples;
//    int myMoney;
//
//public:
//    void ShowSellerResult() const
//    {
//        cout << "�Ǹ��� ��� ���� : " << numOfApples << endl;
//        cout << "�Ǹ��� ���� : " << myMoney << endl;
//
//    }
//
//    AppSeller(int price, int num, int money) :APPLE_PRICE(price)          //����� �ݵ�� �ݷ��ʱ�ȭ
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
//            cout << "�����ִ� ��� ������ : " << numOfApples << endl;
//            cout << "������ �ִ� �ݾ��� : " << numOfApples * APPLE_PRICE;
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
//class AppBuyer  //������ Ŭ����
//{
//private:
//    int numOfApples;
//    int myMoney;
//
//public:
//    void ShowBuyerResult() const
//    {
//        cout << "������ ��� ���� : " << numOfApples << endl;
//        cout << "���� �ܾ� : " << myMoney << endl;
//    }
//
//    AppBuyer(int money)
//    {
//        numOfApples = 0;
//        myMoney = money;
//    }
//
//    //�޼��� ���� : ��ü���� ����� �޼����� ���ؼ� �ǻ��������ϴµ�,
//    //�̷��� �޼����� �� ��ü�� �ִ� �޼��带 ȣ���ϴ� ���̴�
//    void BuyApples(AppSeller& _seller, int money)
//    {
//        if (money <= 0)
//        {
//            cout << "���űݾ��� 0�� �̻��̿��� ��" << endl;
//            return;
//        }
//
//        if (money > myMoney)
//        {
//            cout << "�����ִ� �ݾ� : " << myMoney << endl;
//            cout << "�� �ݾ� ���Ϸ� �����ϼ���" << endl;
//            return;
//        }
//
//        int ret = _seller.SaleApples(��);
//
//        if (ret != 0)
//        {
//            numOfApples += ret;
//            myMoney -= money;
//        }
//
//        //numOfApples += _seller.SaleApples(��);
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