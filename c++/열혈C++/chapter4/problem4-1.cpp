#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
	
public:
	void InitMembers(const int price, int num, int money)
	{
		if(money < 0)
		{
			cout<<"벗어난 범위의 값을 입력했습니다. "<<endl;
		}
		APPLE_PRICE=price;
		numOfApples=num;
		myMoney=money;
	}
	int SaleApples(int money)  
	{
		if(money < 0)
		{
			cout<<"벗어난 범위의 값을 입력했습니다. "<<endl;
		}
		int num=money/APPLE_PRICE;
		numOfApples-=num;
		myMoney+=money;
		return num;
	}
	void ShowSalesResult() const
	{
		cout<<"���� ���: "<<numOfApples<<endl;
		cout<<"�Ǹ� ����: "<<myMoney<<endl<<endl;
	}
};

class FruitBuyer
{
	int myMoney;		// private:
	int numOfApples;	// private:

public:
	void InitMembers(int money)
	{
		if(money < 0)
		{
			cout<<"벗어난 범위의 값을 입력했습니다. "<<endl;
		}
		myMoney=money;
		numOfApples=0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		if(money < 0)
		{
			cout<<"벗어난 범위의 값을 입력했습니다. "<<endl;
		}
		numOfApples+=seller.SaleApples(money);
		myMoney-=money;
	}
	void ShowBuyResult() const
	{
		cout<<"���� �ܾ�: "<<myMoney<<endl;
		cout<<"��� ����: "<<numOfApples<<endl<<endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);// 0보다 작은 인수가 못들어와야함
	
	cout<<"���� �Ǹ����� ��Ȳ"<<endl;
	seller.ShowSalesResult();
	cout<<"���� �������� ��Ȳ"<<endl;
	buyer.ShowBuyResult();
	return 0;
}
