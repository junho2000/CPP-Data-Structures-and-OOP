#include <iostream>
using namespace std;

// class Rectangle
// {
//  private:
//     int rxpos;
//     int rypos;
//  public:
//     Rectangle(int x, int y) :rxpos(x), rypos(y)
//     {
//     }
//     void ShowAreaInfo()
//     {
//         cout<<"area: "<<rxpos*rypos<<endl;
//     }
// };
 
// class Square :public Rectangle
// {
//  private:
//     //int length;
//  public:
//     Square(int len) :Rectangle(len, len)//, length(len)
//     {
//     }
// };

// int main(void)
// {
//         Rectangle rec(4, 3);
//         rec.ShowAreaInfo();
 
//         Square sqr(7);
//         sqr.ShowAreaInfo();
//         return 0;
// }

class Book
{
private:
        char *title; //책의 제목
        char *isbn; //국제표준도서번호
        int price; //책의 정가
public:
        Book(char *Title, char *Isbn, int Price) :price(Price)
        {
            title = new char[strlen(Title)+1];
            strcpy(title, Title);
            isbn = new char[strlen(Isbn)+1];
            strcpy(isbn, Isbn);
        }
        void ShowBookInfo()
        {
            cout<<"title: "<<title<<endl;
            cout<<"ISBN: "<<isbn<<endl;
            cout<<"price: "<<price<<endl;
        }
        ~Book()
        {
            delete []title;
            delete []isbn;
        }
};
 
class Ebook :public Book
{
private:
        char *DRMKey; //보안관련 키
public:
        Ebook(char *Title, char *Isbn, int Price, char *Dkey) :Book(Title, Isbn, Price)
        {
            DRMKey = new char[strlen(Dkey)+1];
            strcpy(DRMKey, Dkey);
        }
        void ShowEBookInfo()
        {
            ShowBookInfo();
            cout<<DRMKey<<endl;
        }
        ~Ebook()
        {
            delete []DRMKey;
        }
};

int main(void)
{
        Book book("좋은 C++", "555-12345-890-0", 20000);
        book.ShowBookInfo();
        cout << endl;
        Ebook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
        ebook.ShowEBookInfo();
        return 0;
}