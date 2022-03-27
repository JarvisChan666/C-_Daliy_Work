//
// Created by 74476 on 2022/3/27.
//

//this is Jarvis Chan
//动态绑定原理
using namespace std;
#include <iostream>

class A{
public:
    virtual void vfunc1() {
        cout << "A::virtual void vfunc1()" << endl;
    }

    virtual void vfunc2() {
        cout << "A::virtual void vfunc2()" << endl;
    }

    void func1() {
        cout<<"A::func1(" << endl;
    }

    void func2()
    {
        cout<<"A::func2()"<<endl;
    }
private:

};
class B:public A
{
public:
    void vfunc1()
    {cout<<"B::vfunc1"<<endl;}
    void func1()//隐藏基类中的func1
    {
        cout<<"B::func1"<<endl;
    }
private:
    int m_data3;
};
int main()
{
    B b;
    b.vfunc1();//B
    b.vfunc2();//A
    b.func1();//B
    b.func2();//A
    A *p;
    p = &b;//动态绑定下面
    //通过基类指针
    p->vfunc1();//B，动态联编or动态多态，调用名为vfunc的虚函数，取决于指向了哪个派生类对象，还要看是否有重写
    p->vfunc2();//A，动态联编or动态多态
    p->func1();//A！！！静态联编实现
    p->func2();//A,静态联编实现
    /*
     * 如果有基类指针指向派生类对象，并通过基类指针调用某些函数时的原理如下
     * 编译器会先检查被调用的函数f是否为虚函数，如果f不是虚函数，采用静态编译，直接调用基类的函数f
     * 无论派生类是否隐藏了该函数f，
     * 若f是虚函数，编译时其实是不知道该调用哪个函数，什么时候才知道呢？
     * 在程序运行时，这个指针变量指向了派生类对象，通过该指针就能够访问被指向(引用）的派生类对象b中的虚表指针，通过此指针找到派生类的虚函数表
     * 然后在虚函数表中查找调用该函数的虚函数指针
     * 如果派生类重写了（覆盖了）基类的虚函数f，那么派生类的虚函数表中保存的是派生类的f函数指针
     * 因此通过基类指针访问f函数最终访问到的是派生类中的函数f；这里的前提是有重写覆盖
     * 如果派生类中没有重写覆盖基类中的虚函数，那么就还是基类的咯！
     * 总结一句话，基类指针捅不破没‘虚化’的被重装(重写)窗户纸
     */
    return 0;
}