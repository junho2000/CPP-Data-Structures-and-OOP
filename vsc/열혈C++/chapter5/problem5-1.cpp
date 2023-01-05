#include <iostream>
using namespace std;

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
    NameCard(char *pername, char *comname, char *phonenum, int grade) :pos(grade)// 생성자
    {  
        Per_name = new char[strlen(pername)+1];
        strcpy(Per_name, pername);

        Com_name = new char[strlen(comname)+1];
        strcpy(Com_name, comname);

        number = new char[strlen(phonenum)+1];
        strcpy(number, phonenum);
    }
    NameCard(const NameCard &ref) :pos(ref.pos) // 깊은 복사생성자
    {
        //ref.~~는 manClerk의 멤버변수들
        Per_name = new char[strlen(ref.Per_name)+1];
        strcpy(Per_name, ref.Per_name);

        Com_name = new char[strlen(ref.Com_name)+1];
        strcpy(Com_name, ref.Com_name);

        number = new char[strlen(ref.number)+1];
        strcpy(number, ref.number);
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
        NameCard copy1 = manClerk; // NameCard copy1(manClerk);
        NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
        NameCard copy2 = manSENIOR; // NameCard copy2(manSENIOR);

        copy1.ShowNameCardInfo();
        copy2.ShowNameCardInfo();

        return 0;
}