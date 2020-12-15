#include <iostream>
#include <typeinfo>
#include "useEigen.h"

using namespace std;

class Foo{
public:
    static int get(void){
        cout<<"Foo get()"<<endl;
        return 0;
    }
};

class Bar{
public:
    static const char* get(void){
        cout<<"Bar get()"<<endl;
        return "0";
    }
};

template<class A>
void func(void){
    auto val = A::get();
}

void testC11Func()
{
    auto x = 5;
    const auto *v = &x;
    cout<<typeid(v).name()<<endl;
    decltype(x) y = 1;
    cout<<typeid(y).name()<<endl;

    cout<<"template test..."<<endl;
    func<Foo>();
    func<Bar>();
}



int main()
{
    cout << "Hello World!" << endl;
//    testC11Func();
    MHJ_PROJ::eigenTools et;
    et.useEigenBuiltInDataType();
    return 0;
}
