// #include <iostream>
// #include <cstring>
// using namespace std;
 
// class Gun
// {
// private:
//         int bullet; //장전된 총알의 수
// public:
//         Gun(int bnum) :bullet(bnum)
//         {
//         }
//         void Shot()
//         {
//                cout << "BBANG!" << endl;
//                bullet--;
//         }
// };
 
// class Police
// {
// private:
//         int handcuffs; //소유한 수갑의 수
//         Gun *pistol; //소유하고 있는 권총
// public:
//         Police(int bnum, int bcuff) :handcuffs(bcuff)
//         {
//                if (bnum > 0) 
//                        pistol = new Gun(bnum);
//                else
//                        pistol = NULL;
//         }
//         Police(Police &ref) :handcuffs(ref.handcuffs)
//         {
//             if (ref.pistol != NULL)
//                 pistol = new Gun(*(ref.pistol));
//             else
//                 pistol = NULL;
//         }
//         void PutHandCuff()
//         {
//                cout << "SNAP!" << endl;
//                handcuffs--;
//         }
//         void Shot() 
//         {
//                if (pistol == NULL)
//                        cout << "Hut BBANG!" << endl;
//                else
//                        pistol->Shot();
//         }


//         Police& operator= (const Police &ref)
//         {
//             handcuffs = ref.handcuffs;

//             if(pistol != NULL)
//                 delete pistol;
//             if(ref.pistol != NULL)
//                 pistol = new Gun(*(ref.pistol)); // Gun 객체 
//             else
//                 pistol = NULL;

//             return *this;
//         }

//         ~Police()
//         {
//                if (pistol != NULL)
//                        delete pistol;
//         }
// };
 
// int main(void)
// {
//         Police pman1(5, 3);
//         Police pman2(0, 3); //권총을 소유하지 않은 경찰
//         pman1 = pman2;
//         Police pman3 = pman2;

//         pman1.PutHandCuff();
//         pman1.Shot();

//         pman3.PutHandCuff();
//         pman3.Shot();

//         return 0;
// }

#include <iostream>
using namespace std;

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
        Book(const Book &ref) :price(ref.price) // 깊은 복사 생성자
        {
            title = new char [strlen(ref.title)+1];
            isbn = new char [strlen(ref.isbn)+1];
            strcpy(title, ref.title);
            strcpy(isbn, ref.isbn);
        }
        Book& operator=(const Book &ref) // 대입 연산자
        {
            delete []title;
            delete []isbn;
            price = ref.price;
            title = new char [strlen(ref.title)+1];
            isbn = new char [strlen(ref.isbn)+1];
            strcpy(title, ref.title);
            strcpy(isbn, ref.isbn);

            return *this;
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
        Ebook(const Ebook &ref) :Book(ref) //복사 생성자
        {
            DRMKey = new char[strlen(ref.DRMKey)+1];
            strcpy(DRMKey, ref.DRMKey);
        }
        Ebook& operator=(const Ebook &ref) //대입 연산자
        {
            Book::operator=(ref);
            delete []DRMKey;
            DRMKey = new char[strlen(ref.DRMKey)+1];
            strcpy(DRMKey, ref.DRMKey);
            
            return *this;
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
         Ebook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
        Ebook ebook2 = ebook1; //복사 생성자의 호출
        ebook2.ShowEBookInfo();
        cout << endl;
        Ebook ebook3("gudetama", "gudetama", 0, "gudetama");
        ebook3 = ebook2; //대입 연산자의 호출
        ebook3.ShowEBookInfo();

        return 0;
}