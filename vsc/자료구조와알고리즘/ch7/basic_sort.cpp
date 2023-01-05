#include <iostream>
#include <algorithm>

using namespace std;

void bubble_sort(int data[], int n) // 
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = n - 1; j > i; j--)
        {
            if(data[j] < data[j - 1])
                swap(data[j], data[j-1]);
        }
    }
}
void selection_sort(int data[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for(int j = i + 1; j < n; j++)
        {
            if(data[j] < data[idx])
                idx = j;
        }
        swap(data[i], data[idx]);
    }
}
void insert_sort(int data[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = data[i];
        int j = i - 1;
        while(j >= 0 && data[j] > key)
        {
            data[j+1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}
int main()
{


    return 0;
}