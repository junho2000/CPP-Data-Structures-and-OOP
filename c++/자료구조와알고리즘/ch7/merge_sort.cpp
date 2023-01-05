#include <iostream>
using namespace std;
int buff[256];

void merge_sort(int data[], int left, int right)
{
    if(left < right) //하나의 원소로 나뉘어 졌을 때 멈춤
    {
        int mid = ( left + right ) / 2;
        merge_sort(data, left, mid);
        merge_sort(data, mid + 1, right);
        merge(data, left, mid, right); //left ~ mid , mid+1 ~ right 두 개 서로 정렬
    }
}
void merge(int data[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k =left;
    while(i <= mid && j <= right) // i번째와 j번째 중에서 비교해서 서로 작은거 buff에 넣음
    {
        if(data[i]<data[j])
        {
            buff[k++] = data[i++];
        }
        else
        {
            buff[k++] = data[j++];
        }
    }
    while(j <= right) // 남은거 처리
    {
        buff[k++] = data[j++];
    }
    while(i <= mid) // 남은거 처리
    {
        buff[k++] = data[i++];
    }
    for(int x = left; x <= right; x++) // buff에 있는 거 data로 옮김
    {
        data[x] = buff[x];
    }
}

int main()
{

    return 0;
}