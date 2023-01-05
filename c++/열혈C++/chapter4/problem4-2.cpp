#include <iostream>
using namespace std;
 
// class Point
// {
// private:
//         int xpos;
//         int ypos;
// public:
//         void Init(int x, int y)
//         {
//                xpos = x;
//                ypos = y;
//         }
//         int GetX()
//         {
//                return xpos;
//         }
//         int GetY()
//         {
//                return ypos;
//         }
//         void ShowPointInfo() const
//         {
//                cout << "[" << xpos << ", " << ypos<< "]" << endl;
//         }
// };
// class Circle
// {
//     private:
//         Point p;
//         int radius;
//     public:
//         void SaveInfo(int x, int y, int rad);
//         void PrintInfo(void);
// };
// void Circle::SaveInfo(int x, int y, int rad)
// {
//     p.Init(x,y);
//     radius = rad;
// }
// void Circle::PrintInfo(void)
// {
//     cout<<"radius: "<<radius<<endl;
//     p.ShowPointInfo();
    
// }

// class Ring
// {
//     private:
//         Circle c1;
//         Circle c2;
//     public:
//         void Init(int x1, int y1, int rad1, int x2, int y2, int rad2);
//         void ShowRingInfo(void);
// };
// void Ring::Init(int x1, int y1, int rad1, int x2, int y2, int rad2)
// {
//     c1.SaveInfo(x1, y1, rad1);
//     c2.SaveInfo(x2, y2, rad2);
// }
// void Ring::ShowRingInfo(void)
// {
//     cout<<"Inner Circle Info..."<<endl;
//     c1.PrintInfo();
//     cout<<"Outter Circle Info..."<<endl;
//     c2.PrintInfo();
// }

// int main(void)
// {
//         Ring ring;
//         ring.Init(1, 1, 4, 2, 2, 9);
//         ring.ShowRingInfo();
//         return 0;
// }
namespace COMP_POS
{
        enum
        {
               CLERK, SENIOR, ASSIST, MANAGER
        };

         void ShowStatusInfo(int status)
        {
               switch (status)
               {
               case CLERK:
                       cout << "사원" << endl;
                       break;
               case SENIOR:
                       cout << "주임" << endl;
                       break;
               case ASSIST:
                       cout << "대리" << endl;
                       break;
               case MANAGER:
                       cout << "과장" << endl;
               }
        }
}

class NameCard
{
private:
    char *Per_name;
    char *Com_name;
    char *number;
    int pos;
public:
    NameCard(char *pername, char *comname, char *phonenum, int grade) :pos(grade)
    {  
        Per_name = new char[strlen(pername)+1];
        strcpy(Per_name, pername);

        Com_name = new char[strlen(comname)+1];
        strcpy(Com_name, comname);

        number = new char[strlen(phonenum)+1];
        strcpy(number, phonenum);
    }
    void ShowNameCardInfo()
    {
        cout<<"name: "<<Per_name<<endl;
        cout<<"company: "<<Com_name<<endl;
        cout<<"number: "<<number<<endl;
        cout<<"position: ";
        COMP_POS::ShowStatusInfo(pos);
        cout << endl;
    }

    ~NameCard()
    {
        delete []Per_name;
        delete []Com_name;
        delete []number;
    }

};

int main(void)
{
        NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
        NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
        NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
        manClerk.ShowNameCardInfo();
        manSENIOR.ShowNameCardInfo();
        manAssist.ShowNameCardInfo();
        return 0;
}