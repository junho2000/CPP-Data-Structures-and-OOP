#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(int data[], int left, int right)
{
    if(left  < right) // right == left인 경우 원소 하나로 이루어짐
    {
        int p =partition(data , left, right); // pivot 위치 반환
        quick_sort(data, left, p - 1); //pivot보다 작은 원소 집합 정렬
        quick_sort(data, p + 1, right); //pivot보다 큰 원소 집합 정렬
    }
}
int partition(int data[], int left, int right)
{
    int pivot = data[left];
    int i = left + 1, j = right;

    while(true)
    {
        while(data[i] <= pivot && i <= right) // i를 증가시키면서 pivot보다 큰 걸 찾음
            i++;
        while(data[j] > pivot && j > left) // j를 감소시키면서 pivot보다 작은 걸 찾음
            j--;
        if(i<j)
            swap(data[i], data[j]);
        else 
            break;
    }
    swap(data[left], data[j]);
}

int main()
{

    return 0;
}