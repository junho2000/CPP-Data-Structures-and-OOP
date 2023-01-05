#include<iostream>
#include<cstdio>

using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
}Point;

Point& PntAdder(const Point &p1, const Point &p2)//const Point &p1 = *p1, const Point &p2 = *p2 ???
{
    // Point a;
    // Point &NewPoint = a;//??
    Point *result=new Point;//함수 내에 선언된 변수를 참조형으로 반환하려면 해당 변수는 어떻게 선언해야하는가?

    result->xpos = p1.xpos + p2.xpos;
    result->ypos = p1.ypos + p2.ypos;
    printf("%d\n", *result);

    return *result;//???
}

int main(void)
{
    Point *p1 = new Point;
    cout<<"plz input xpos and ypos of point 1: ";
    cin>>p1->xpos>>p1->ypos;

    Point *p2 = new Point;
    cout<<"plz input xpos and ypos of point 2: ";
    cin>>p2->xpos>>p2->ypos;
    
    printf("%d\n", *p1);// 1
    printf("%d\n", *p2);// 1

    Point &point = PntAdder(*p1, *p2);//동적할당한 변수를 함수의 참조형 매개변수의 인자로 어떻게 전달해야 하는가????

    cout<<"new xpos: "<<point.xpos<<endl;
    cout<<"new ypos: "<<point.ypos<<endl;

    delete p1;
    delete p2;
    delete &point;

    return 0;
}