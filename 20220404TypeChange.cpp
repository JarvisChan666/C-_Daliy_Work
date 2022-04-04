//
// Created by 74476 on 2022/4/4.
//

//this is Jarvis Chan
#if 0
#include <iostream>
#include <CStdio>
using namespace std;
class Base
{
public:
    Base(){};
    virtual void Show(){cout<<"this is base clalss"<<endl;}
};
class Derived:public Base
{
public:
    Derived(){};
    void Show(){cout<<"this is derived class"<<endl;}
};
class Derived1:public Base
{
public:
    Derived1(){};
    void Show(){cout<<"this is derived class"<<endl;}
};
//...............
class Test
{
public:
    int a;
    Test()
    {a=10;}

};
const int *func(int *p)
{
    cout <<*p<<endl;
    int *p2 = new int(100);
    return p2;//
}
Base *func()
{
    Derived1 *p1;
    Derived1 *p;
    return p1;//we can return any subclass pointer
}
//......................................
class A
{
public:
    void f()
    {
        cout <<"a::f("<<endl;
    }
};
class B:public A{
public:
    void f()//yincang
    {
        cout<<"b::f("<<endl;
    }
};
class C
{};
int main()
{
#if 0//隐式类型转换
    int x;
    x = 3.14;
    cout << x<<endl;

    float f;
    f=3;
    printf("%f\n",f);
    int *p = (int *) malloc(10);//malloc返回值是void，要强制转换
#endif
//const cast
//const just constrain the value just can read,but wont constrain the space to only read
 //it has a const table;
#if 0
    const int data = 100;//take out int,it made data;
    int *pp = (int *)&data;;//pp point to data,we can get in the space to change value because we can get in space
    *pp = 1000;//it wont change the value of data,but *pp=1000.
    cout <<data<<endl;//100,const table value,when data,it
    cout <<*(&data)<<endl;//1000!
    cout << pp<<endl;
    cout <<&data<<endl;
    const Test b;//const only value(variable),you cant change it through it,but it canbe change by dest
    Test *b1 = const_cast<Test *>(&b);//get out const
    b1->a = 100;
    cout<<b.a << endl;

    const int *ptr = new int(10);//一个int大小的空间，并赋值为10

    //左边要符合右边类型
    const int *ret=func(const_cast<int *>(ptr));//cast the const type,but it doesnt real cast
   int *ret2 = const_cast<int *>(func(const_cast<int *>(ptr)));//take out return value's const,just instance
#endif
#if 0
    double value = 12.12;
    int nvalue = static_cast<int>(value);//only can change in 继承 relation
    A *pa = new A;
    B *pb = static_cast<B *>(pa);
    pb->f();//B::f
   // C *pc = static_cast<C *>(pa);//it cant be change,because they have no relationship
#endif

//support  向上转型
    Base b;
    Base *base;//yezhizhen
    Derived *der = new Derived;
    Derived *der2 = new Derived;
    //base = der;//point to sub class
    //base->Show();
    //der = base;  no!!!!
    //if 野指针，success，but after change still yezhizhen
    //if base point to subclass base=&b
    //base = &b;//
    //we cant low to top
    //if base_ptr point to his subclass_object
    //Derived1 d1;
   // base = &d1;//base point to a subclass object,but
    base = der2;//base point to a subclass,they must same type
    //也就是说基类指针指向了一个派生类指针1，如果他想转成派生类指针2，必须1和2类型相同
    //dynamic cast means 动态切
    der = dynamic_cast<Derived*>(base);//down change,if base is yezhizhen,defeat
    //保证向下转型是安全的，失败就空，让程序员去查
    if(der)
    {cout<<"hel"<<endl;
        der->Show();//i want to use derived fuc,no derived1 func
    }//sunb class
    //
    return 0;
}
#endif