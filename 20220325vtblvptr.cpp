//
// Created by 74476 on 2022/3/27.
//

//this is Jarvis Chan
//
// Created by 74476 on 2022/3/25.
//

//this is Jarvis Chan
//指向虚函数表的指针可以通过偏移读取所有的指针的值
//虚函数表属于类，被其成员共享
//虚表指针在对象内存地址的首位，能提高运行效率
//动态绑定   ，基类指针，隐藏有啥用，
#if 0
#include <iostream>
using namespace std;
class A
{
public:

    //编译器在类内部自动生成了虚表指针vfptr占8字节访问表的首地址，从而通过偏移访问到表中的所有指针的地址，从而访问到代码段函数
    virtual void func1();
    virtual void func2();
    virtual void func4();
    void func3();
};

//class B这些函数，也有一张虚函数表存着虚函数指针
//这表结尾是个数，不用管
class B:public A
{
public:
    virtual void func()//表里末尾添加，把那个结尾数字挤到后面
    {}
    //重写了，B中的虚函数表里有个func1指针指向了这个重写过的
    //虚函数表的第一个存自己的函数
    //没有重写前，虚函数表里的其中一个指针是存原先func1在代码段上的地址
    virtual void func1(){}//重写基类虚函数(覆盖),前面可不写virtual，也认为是虚函数
};
int main()
{

    return 0;
}
#endif