#include <iostream>

int main(void){
    double val1;
    std::cout<<"first number input: ";
    std::cin>>val1;

    double val2;
    std::cout<<"second number input: ";
    std::cin>>val2;

    double result = val1 + val2;
    std::cout<<"Add result: "<<result<<std::endl;
    return 0;

}