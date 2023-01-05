#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

vector<int> odds()
{
	return {1, 3, 5, 7, 9};
}
int main()
{
	// auto: 자동으로 형을 정해준다
	auto a1 = 10;		  // int
	auto a2 = 3.1f;		  // float
	auto a3 = "hello";	  // const char*
	auto a4 = "hello"s;	  // std::string
	auto a5 = sqrt(2.0);  // double
	auto a6 = odds();	  // vector<int>
	auto a7 = a6.begin(); // vector<int>::iterator
	auto a8 = 3.1;		  // double
	auto lambda = [](int x) { return x * 2; };

	// using: typedef 쓰지말고 using 쓰자..!
	using uchar = unsigned char;
	using pis = pair<int, string>;
	using da10 = double[10];
	using func = void (*)(int);
	template <tyepname T>
	using matrix1d = vector<T>;

	da10 arr{};
	matrix1d<float> vec(3);
	void my_function(int n) {}
	func fp = &my_function;

	// range-based for: iteration한다고 생각하자
	vector<int> numbers{1, 2, 3, 4, 5};
	for (int n : numbers) // n = 순서대로 numbers 안에 있는 요소들 복사, int는 요소 타입
		cout << n << endl;
	for (auto &n : numbers) // numbers안에 있는 요소들 참조, 조금 더 효율적
		cout << n << endl;

	string strs[] = {"I", "love", "you"};
	for (const auto &n : strs) // const를 써서 numbers안에 있는 요소들을 참조를 할꺼지만 바꾸지는 않겠다.
		cout << n << endl;

	// lambda expression: 함수의 원형 찾기 귀찮을 때 한눈에 보기 쉽게 함수를 만들자
	auto square = [](double x) { return x * x; }; //[] 람다함수 쓴다..!(받을 함수 인자) {함수 내용};
	cout << "suqare(1.414): " << square(1.414) << endl;

	struct Person {
		string name;
		int age;
	};
	vector<Person> students;
	students.push_back({"KIM", 20});
	students.push_back({"PARK", 30});
	students.push_back({"CHOI", 40});
	students.push_back({"LEE", 50});
	sort(students.begin(), students.end(), [](const Person &p1, const Person &p2) {
		return p1.name < p2.name;
	});
	for (const auto &n : students)
		cout << p.name << " : " << p.age << endl;

	// chrono library: 정밀한 시간 측정 -> 알고리즘을 실행했을 때 시간 측정
	auto start = chrono::system_clock::now();

	// code

	auto end = chrono::system_clock::now();
	auto msec = chrono::duration<double>(end - start).count() * 1000;
	cout << "Elapsed time; " << msec << "ms." << endl;


	return 0;
}