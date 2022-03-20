//
// Created by 74476 on 2022/3/4.
//
//派生类调用基类的构造函数
//派生类拓展出来的成员变量名字和基类冲突，或者函数名冲突（隐藏）
//多继承
//this is Jarvis Chan
/*
using namespace std;
#include <iostream>

class A
{
private:
    int x;//派生类无法访问，但是他有x
public:
    int k = 20;//冲突名字
    A()
    {
        cout <<"A()" << endl;
    }
    ~A()
    {
        cout <<"~A" << endl;
    }
    int get_z()
    {return z;}
    A(int a,int b):z(a),x(b)
    {cout <<"A(int a,int b):z(a),x(b)" << endl;}
    int set_x(int)
    {
        this->x = x;
    }
protected:
    int z;
};
A a(10,20);

class B : public A
{
public:
    int k = 99;

    B()
    {
        cout << "B()" << endl;
    }
    ~B()
    {
        cout << "~B " << endl;
    }
    //当B被实例化传入参数后调用
    //在派生类构造函数想初始化，可以搭顺风车，指定调用基类中的某个构造函数
    B(int a,int b):A(a,b)//如何不用这种方法初始化B的实例化？
    {
       // z = a;
        //set_x(b);
        cout << "B(int a,int b)" << endl;
    }

};
class C:public A
{
};
class D:public B,public C
{

};
int main()
{
    B b;
    B(10,20);
    b.get_z();
    cout << b.k << endl;
    cout << b.A::k << endl;//解决同名问题
    C c;
    c.k;
    D d;
    d.B::k;
    d.C::k;

}
 */