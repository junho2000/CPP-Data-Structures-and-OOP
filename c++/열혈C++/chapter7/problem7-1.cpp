// #include <iostream>
// using namespace std;
// //생성자와 메인함수를 직접 짜보자

// class Car //기본 연료 자동차
// {
// private:
//         int gasolineGauge;
// public:
//         Car(int gasoline) : gasolineGauge(gasoline)
//         {
//         }
//         int GetGasGauge()
//         {
//                return gasolineGauge;
//         }
// };
 
// class HybridCar :public Car //하이브리드 자동차
// {
// private:
//         int electricGauge;
// public:
//         HybridCar(int gasoline, int electric) : Car(gasoline), electricGauge(electric)
//         {
//         }
//         int GetElecGauge()
//         {
//                return electricGauge;
//         }
// };
 
// class HybridWaterCar :public HybridCar //하이브리드 워터카
// {
// private:
//         int waterGauge;
// public:
//         HybridWaterCar(int gasoline, int electric, int water) : HybridCar(gasoline, electric), waterGauge(water)
//         {
//         }
//         void ShowCurrentGauge()
//         {
//                cout << "잔여 가솔린: " << GetGasGauge() << endl;
//                cout << "잔여 전기량: " << GetElecGauge() << endl;
//                cout << "잔여 워터량: " << waterGauge << endl;
//         }
// };

// int main(void)
// {
//     int gasoline, electric, water;
//     cout << "가스, 전기, 물의 양을 입력:";
//     cin >> gasoline >> electric >> water;
//     HybridWaterCar car(gasoline, electric, water);
//     car.ShowCurrentGauge();

//     return 0;
// }

#include <iostream>
using namespace std;
//생성자, 소멸자, 메인함수를 직접 짜보자

class MyFriendInfo
{
private:
        char *name;
        int age;
public:
        MyFriendInfo(char *Name, int Age) :age(Age)
        {
            name = new char[strlen(Name) + 1];
            strcpy(name, Name);
        }
        void ShowMyFriendInfo()
        {
               cout << "이름: " << name << endl;
               cout << "나이: " << age << endl;
        }
        ~MyFriendInfo()
        {
            delete []name;
        }
};
 
class MyFriendDetailInfo :public MyFriendInfo //MyFriendDetailInfo -> MyFriendInfo
{
private:
        char *addr;
        char *phone;
public:
        MyFriendDetailInfo(char *Name, int Age, char *add, char *Phone) :MyFriendInfo(Name, Age)
        {
            addr = new char[strlen(add) + 1];
            strcpy(addr, add);
            phone = new char[strlen(Phone) + 1];
            strcpy(phone, Phone);
        }
        void ShowMyFriendDetailInfo()
        {
               ShowMyFriendInfo();
               cout << "주소: " << addr << endl;
               cout << "전화: " << phone << endl << endl;
        }
        ~MyFriendDetailInfo()
        {
            delete []addr;
            delete []phone;
        }
};

int main(void)
{
    char name[10];
    int age;
    char address[30];
    char phonenum[20];   

    cout<<"plz press name, age, address, phone number: ";
    cin>>name>>age>>address>>phonenum;

    MyFriendDetailInfo mfdi(name, age, address, phonenum);
    mfdi.ShowMyFriendDetailInfo();

    return 0;
}