#include <iostream>
#include <string>
// #include <numeric>  gcd(a,b), lcm(a,b) 함수지원
using namespace std;

long long factorial(int n) // factorial
{
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}
long long fibo(int n) // fibonacci
{
	if (n <= 1)
		return n;
	else
		return fibo(n - 1) + fibo(n - 2);

	return 0;
}
string reverse(const string &str) // reverse string without stack
{
	if (str.length() == 0)
		return "";

	return reverse(str.substr(1)) + str[0];
}
int gcd(int a, int b) // greatest common divisor 유클리드 호제법을 이용 최대공약수 구함
{
	if (b == 0)
		return a;
	else {
		return gcd(b, a % b);
	}
}
int lcm(int a, int b) // lowest common multiple 최소공배수
{
	return a * b / gcd(a, b);
}
int main()
{
	cout << factorial(5) << endl;
	cout << factorial(10) << endl;
	cout << factorial(20) << endl;

	for (int i = 1; i <= 10; i++)
		cout << fibo(i) << ", ";
	cout << endl;

	cout << reverse("HELLO WORLD") << endl;

	cout << gcd(24, 18) << endl;
	cout << lcm(24, 18) << endl;

	return 0;
}