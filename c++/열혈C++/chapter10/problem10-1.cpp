#include<iostream>
using namespace std;
 
class Point
{
private:
        int xpos;
        int ypos;
public:
        Point(int x = 0, int y = 0) :xpos(x), ypos(y)
        {
        }
        void ShowPosition() const
        {
            cout << '[' << xpos << ", " << ypos << ']' << endl;
        }

        friend Point& operator~(Point &pos);
        friend Point operator-(Point &pos1, Point &pos2);
        friend bool operator==(Point &pos1, Point &pos2);
        friend bool operator!=(Point &pos1, Point &pos2);

        Point operator+=(Point &pos) const
        {
            return Point(xpos + pos.xpos, ypos + pos.ypos);
        }
        Point operator-=(Point &pos) const
        {
            return Point(xpos - pos.xpos, ypos - pos.ypos);
        }
        Point& operator-() //단항 연산자 오버로딩
        {
            Point ref(-xpos, -ypos);

            return ref;
        }
        // Point &operator-(Point &ref)
        // {
        //        xpos = -ref.xpos;
        //        ypos = -ref.ypos;
        //        return *this;
        // }
};
Point& operator~(Point &pos) //단항 연산자 오버로딩
{
    int temp = pos.xpos;
    pos.xpos = pos.ypos;
    pos.ypos = temp;

    return pos;
}
Point operator-(Point &pos1, Point &pos2)
{
    return Point(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}
bool operator==(Point&pos1, Point &pos2)
{
    if(pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
        return true;
    else 
        return false;
}
bool operator!=(Point&pos1, Point &pos2)
{
    if(pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
        return false;
    else 
        return true;
}
void IfSamePosition(bool Bool)
        {
            if(Bool)
                cout<<"True"<<endl;
            else   
                cout<<"False"<<endl; 
        }

int main(void)
{
        Point pos1(10, 20);
        Point pos2(3, 4);
        Point pos3 = pos1 - pos2;
        Point pos4 = - pos1;
        Point pos5 = ~(~pos1);

        pos1.ShowPosition();
        pos2.ShowPosition();
        pos3.ShowPosition();
        pos4.ShowPosition();
        pos5.ShowPosition();
        // (pos1 += pos2).ShowPosition();
        // (pos1 -= pos2).ShowPosition();
        // IfSamePosition(pos1 == pos2);
        // IfSamePosition(pos1 != pos2);

        return 0;
}