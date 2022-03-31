//
// Created by 74476 on 2022/3/31.
//
//基类析构函数要定义成虚函数，基类指针无法释放派生类对象，因为掉用不到它的析构函数从而导致内存泄露
//为了在实际应用中，为了实现动态多态，用基类指针指向派生类对象，并通过基类指针释放掉派生类能够成功调用其析构
//this is Jarvis Chan
using namespace std;
#include <iostream>
typedef unsigned int u32_t;
//用一个shape抽象类求出所有的派生类的东西,为派生类读服务
class Shape
{
public:
    virtual double getPermiter()=0;//求周长
    virtual double getArea() = 0;
    ~Shape(){//先调用派生类中的析构，才来调用这个
        cout<<"virtual ~Shape()"<<endl;
    }
};
//派生出三角形类
class Triangle:public Shape
{
public:
    //一般一个类需要默认构造函数，带参数的默认构造函数，拷贝构造函数，等于符号重载，析构函数
    Triangle():_a(10),_b(10),_c(10)
    {}
    Triangle(u32_t a,u32_t b,u32_t c):_a(a),_b(b),_c(c)
    {}
    double getPermiter()
    {
        return double (_a+_b+_c);
    }
    double getArea()
    {return 1000;}
    virtual ~Triangle(){
        cout<<"virtual ~Triangle()"<<endl;
    }
private:
    u32_t  _a,_b,_c;
    u32_t _permiter;
    double area;

};
//派生circle
class Circle:public Shape
{
public:
    Circle():_r(10){}
    double getPermiter();//求周长
    double getArea();

private:

    double _r;
//类中静态成员变量被所有成员共享，派生类和基类共享
    static double PI;

};
//定义静态成员变量
double Circle::PI = 3.14;
double Circle::getPermiter() {
    return 2*PI*_r;
}
double Circle::getArea() {
    return PI*_r*_r;
}
int main()
{
    /*
    Triangle x;
    //cout << x.getPermiter()<<endl;
    Circle c;
    //cout << c.getPermiter()<<endl;
    //cout << x.getArea()<<endl;
    //需求：用一个数组保存三角形和园
    Shape *shapes[2];
    shapes[0] = &x;
    shapes[1] = &c;
     */
    Shape *p = new Circle();//基类指针指向派生类对象,相当于构造了个派生类对象，在堆空间
    delete p;//释放派生类对象，通过基类指针去释放
//
//    for(int i = 0;i<2;i++)
//    {
//        cout<<shapes[i]->getArea()<<endl;
//        cout<<shapes[i]->getPermiter()<<endl;
//    }
    return 0;
}