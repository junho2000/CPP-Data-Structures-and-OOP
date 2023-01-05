#include<iostream>
#include<cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage)
    {
        int len = strlen(myname)+1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    void ShowPersonInfo(void) const
    {
        cout<<"name: "<<name<<endl;
        cout<<"age : "<<age<<endl;
    }
    ~Person()
    {
        delete []name;
        cout<<"called destructor!"<<endl;
    }
};

int main(void)
{
    Person man1("kim junho", 23);
    Person man2("eric jeon", 23);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}