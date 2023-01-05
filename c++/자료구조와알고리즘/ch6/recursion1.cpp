#include <iostream>
using namespace std;

int sum_for(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += i;
	return sum;
}
int sum_recur(int n)
{
	if (n == 1)
		return 1;
	else
		return n + sum_recur(n - 1);
}

int main()
{
    int a;
    cout<<"press number: ";
    cin>>a;

    cout<<sum_for(a)<<endl;
    cout<<sum_recur(a)<<endl;

	return 0;
}