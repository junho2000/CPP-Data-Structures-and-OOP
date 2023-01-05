#include<iostream>
using namespace std;

class String
{
private:
    int len;
    char *string;
public:
    String() :len(0), string(NULL)
    {}
    String(const char* str)//생성자
    {
        len = strlen(str) + 1;
        string = new char[len];
        strcpy(string, str);
    }
    String(const String& str)//복사 생성자
    {
        len = str.len;
        string = new char[len];
        strcpy(string, str.string);
    }
    String& operator=(const String &str)//대입 연산자
    {
        if(string != NULL)
            delete []string;
        len = str.len;
        string = new char[len];
        strcpy(string, str.string);
        return *this;
    }
    String operator+(const String &str)// + + + ... 가능?
    {
        char* tempstr = new char[len + str.len - 1];
        strcpy(tempstr, string);
        strcat(tempstr, str.string);
        String temp(tempstr);
        delete []tempstr;
        return temp;
    }
    String& operator+=(const String &str)
    {
        len += str.len + 1;
        char* tempstr = new char[len];
        strcpy(tempstr, string);
        strcat(tempstr, str.string);
        
        if(string!=NULL)
            delete []string;
        string = tempstr;
        return *this;
    }
    bool operator==(const String &str)
    {
        return strcmp(string, str.string) ? false:true;
    }
    
    friend ostream& operator<<(ostream& os, String &Str);
    friend istream& operator<<(istream& is, String &Str);

    ~String()//소멸자
    {
        if(string != NULL)
            delete []string;
    }
    
};
ostream& operator<<(ostream& os, String &str)
{
    os<<str.string;
    return os;
}
istream& operator>>(istream& is, String &str)
{
    char temp[100];
    is>>temp;
    str = String(temp);
    return is;
}

int main()
{
    String str1 = "hello ";
    String str2 = "world";

    String str3 = str1 + str2;
    str1 += str2;

    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;

    return 0;
}