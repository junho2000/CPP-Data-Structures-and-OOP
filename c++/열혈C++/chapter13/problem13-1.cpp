// #include<iostream>
// using namespace std;

// class Point
// {
// private:
//     int xpos, ypos;
// public:
//     Point(int x=0, int y=0) :xpos(x), ypos(y)
//     {}
//     void ShowPosition() const
//     {
//         cout<<"["<<xpos<<","<<ypos<<"]"<<endl;
//     }
//     // Point(Point &pos) :xpos(pos.xpos), ypos(pos.ypos)
//     // {}
// };

// template <class T>
// void Swap(T &pos1, T &pos2)
// {
//     T temp = pos1;
//     pos1 = pos2;
//     pos2 = temp;
// }

// int main()
// {
//     Point pos1(1,2);
//     Point pos2(3,4);
//     Point pos3 = pos1;
//     pos1.ShowPosition();
//     pos2.ShowPosition();
//     pos3.ShowPosition();
//     Swap(pos1, pos2); 
//     pos1.ShowPosition();
//     pos2.ShowPosition();

//     return 0;
// }
#include<iostream>
using namespace std;

// int SumArray(int arr[], int len)
// {
//         int sum = 0;
//         for (int i = 0; i < len; i++)
//                sum += arr[i];
//         return sum;
// }
template <class T>
T SumArray(T arr[], int len)
{
    T sum = 0;
    for (int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}
int main()
{
    double arr[10];
    for (int i = 0; i < 10; i++)
           arr[i] = (i + 1)*2.5;
    cout << "전체 배열 출력:";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "합계는:" << SumArray(arr, 10) << endl;

    int iarr[5] = {1,2,3,4,5};
    cout<<SumArray(iarr, 5)<<endl;

    return 0;
}