#include <iostream>
using namespace std;

int main()
{
	int *ptr = new int[3]{}; //설정 안한 나머지 값들 0으로 초기화
	ptr[0] = 10;
	ptr[1] = 20;

	for (int i = 0; i < 3; i++) {
		cout << ptr[i] << endl;
	}
	delete[] ptr;
    ptr = nullptr;
    
	return 0;
}