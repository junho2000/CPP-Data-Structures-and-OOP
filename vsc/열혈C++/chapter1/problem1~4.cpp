#include <iostream>

int main(void)
{
    int num = 0;

    while(1)
    {
        std::cout<<"total product sale(end to insert -1): ";
        std::cin>>num;

        if(num != -1)
        {
            std::cout<<"this month's payment: "<<50 + num*0.12<<std::endl;
        }
        else
        {
            std::cout<<"program end..."<<std::endl;
            return -1;
        }
        
        
    }
    return 0;
}