//
// Created by 74476 on 2022/3/18.
//

//this is Jarvis Chan
//静态联编
/*
 #include <iostream>
#include <string>
using namespace std;

void func()
{}
void func(int x)
{}
void func(char x)
{}
//重载后的函数放在符号表,编译可查看funci,funcv
class A
{
public:
    void func()
    {}
};
class B:public A
{
public:
    void func()
    {}
};
int main()
{
    B b;
    b.func();;//隐藏A的func
    b.A::func();
    string s1("hello"),s2("world");
    string s3;
    s3 = s1+s2;//+被重载overload
    cout << s3 << endl;
    cout <<s1[2] << endl;
    return 0;
}
 */