#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//linear search(선형 탐색, 순차 탐색) : 전체 자료를 처음부터 마지막까지 순서대로 탐색하는 방법, O(n)
//장점 : 간단하고 직관적, 정렬되지 않은 자료에 적용가능
//단점 : 비효율적
bool linear_search(int data[], int n, int target)
{
    for(int i = 0; i < n; i++)
    {
        if(data[i] == target)
            return true;
    }
    return false;
}

//binary search(이진 탐색) : 정렬된 배열에 대해 검색 단계별로 검색 범위를 반으로 줄여가면서 데이터를 찾는 기법, O(logn)
//장점 : 검색 속도가 빠름
//단점 : 이미 정렬되어 있는 데이터에만 적용 가능
bool binary_search(int data[], int n, int target)
{ 
    int lower = 0, upper = n - 1;

    if(data[lower] > target || data[upper] < target)
        return false;

    while(lower <= upper)
    {
        int mid = (lower + upper) / 2;
        if(data[mid] < target)
        {
            lower = mid + 1;
        }
        else if(data[mid] > target)
        {
            upper = mid - 1;
        }
        else 
            return true;
    }
    
    return false;
}


int main()
{
    int data[] = {1, 2, 3, 5, 7, 10, 13, 15, 18, 23, 25, 27, 28, 30, 33};
    int target = 23;

    bool res1 = linear_search(data, size(data), target);
    bool res2 = binary_search(data, size(data), target);

    cout<<res1<<endl;
    cout<<res2<<endl;
    
    return 0;
}