//
// Created by 74476 on 2022/3/15.
//

//this is Jarvis Chan
#include <iostream>
using namespace std;
class A
{
public:
    static int num;//only declaration,but not really in A,
    int x;
    //this function has no this pointer,it can only use in static variable.
    static int func(int x){
        return num;//
    }

private:
    int num1;
};
class B :public A
{
public:
    static int num;
};
int B::num = 1000;
int A::num = 10;
/*
int main()
{
    A a1,a2;
    a1.num = 100;
    a2.num = 200;
    A::num = 200;//nice
    A::func(10);
    B b1;
    b1.func(10);
   // b1.num = 300;//not only can继承，it is 共享
   b1.num = 10;
    return 0;
}
 */