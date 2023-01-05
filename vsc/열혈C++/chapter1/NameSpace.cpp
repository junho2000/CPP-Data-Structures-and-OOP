#include <iostream>

namespace BestComImp1
{
    void SimpleFunc(void);
}
namespace BestComImp1
{
    void PrettyFunc(void);
}
namespace ProgComImp1
{
    void SimpleFunc(void);
}

namespace Parent
{
    int num = 1;
    namespace SubOne
    {
        int num = 2;
    }
    namespace SubTwo
    {
        int num = 3;
    }
}//총 3개의 num이 존재하는 namespace가 다르므로 이름충돌 문제 발생 x 

int main(void)
{
    BestComImp1::SimpleFunc();
    ProgComImp1::SimpleFunc();
    std::cout<<Parent::num<<std::endl;
    std::cout<<Parent::SubOne::num<<std::endl;
    std::cout<<Parent::SubTwo::num<<std::endl;
}

void BestComImp1::SimpleFunc(void)
{
    std::cout<<"Function by BestCom"<<std::endl;
    PrettyFunc();// PrettyFunc is in same namespace(BestComImp)
    ProgComImp1::SimpleFunc();//different namespace
}
void BestComImp1::PrettyFunc(void)
{
    std::cout<<"So pretty!"<<std::endl;
}
void ProgComImp1::SimpleFunc(void)
{
    std::cout<<"Function by ProgCom"<<std::endl;
}
