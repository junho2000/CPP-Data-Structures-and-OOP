#include <iostream>
using namespace std;
 
class Point
{
private:
        int xpos;
        int ypos;
public:
        Point(int x, int y)
            : xpos(x), ypos(y)
            {
            }
        // {
        //     xpos = x;
        //     ypos = y;
        // }
        // void Init(int x, int y)
        // {
        //        xpos = x;
        //        ypos = y;
        // }
        int GetX()
        {
               return xpos;
        }
        int GetY()
        {
               return ypos;
        }
        void ShowPointInfo() const
        {
               cout << "[" << xpos << ", " << ypos<< "]" << endl;
        }
};
class Circle
{
    private:
        Point p;
        int radius;
    public:
        Circle(int x, int y, int rad)
            : p(x, y), radius(rad)
            {
            }
        // void SaveInfo(int x, int y, int rad);
        void PrintInfo(void);
};
// void Circle::Circle(int x, int y, int rad)
// {

//     radius = rad;
// }
void Circle::PrintInfo(void)
{
    cout<<"radius: "<<radius<<endl;
    p.ShowPointInfo();
    
}

class Ring
{
    private:
        Circle c1;
        Circle c2;
    public:
        Ring(int x1, int y1, int rad1, int x2, int y2, int rad2)
            : c1(x1, y1, rad1), c2(x2, y2, rad2)
            {
            }
        // void Init(int x1, int y1, int rad1, int x2, int y2, int rad2);
        void ShowRingInfo(void);
};
// void Ring::Init(int x1, int y1, int rad1, int x2, int y2, int rad2)
// {
//     c1.SaveInfo(x1, y1, rad1);
//     c2.SaveInfo(x2, y2, rad2);
// }
void Ring::ShowRingInfo(void)
{
    cout<<"Inner Circle Info..."<<endl;
    c1.PrintInfo();
    cout<<"Outter Circle Info..."<<endl;
    c2.PrintInfo();
}

int main(void)
{
        Ring ring(1, 1, 4, 2, 2, 9);
        ring.ShowRingInfo();
        return 0;
}
