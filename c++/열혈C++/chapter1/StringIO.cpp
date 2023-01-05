#include <iostream>

int main(void)
{
    char name[100];
    char lang[200];

    std::cout<<"what is your name? ";
    std::cin>>name;

    std::cout<<"what is your favorite programming language? ";
    std::cin>>lang;

    std::cout<<"my name is "<<name<<".\n";
    std::cout<<"my favorite programming language is "<<lang<<"."<<std::endl;
    return 0;
}