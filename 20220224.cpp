//
// Created by 74476 on 2022/2/24.
//

//静态成员函数,用来访问被private和protected的静态成员变量
//可用于封装函数，直接math：：公式，而就没必要先构造对象再调用函数了
//有人可能会说：我直接声明函数就行，但是这样的好处是：
//1.日后添加删除公式方便，便于统一管理，oop。
//2.单例模式设计
//3.访问private protect

//string类函数
//this is Jarvis Chan
/*
#include <iostream>
using namespace std;
class Math
{
public:
    static int sin(int val){}
};

class Sheep
{
public:
    char name[32];
    int age;
    //买羊

    //真正的成员函数
    Sheep()//（sheep * const this),因为有this指针，就能访问成员变量和成员函数
    {
        cout << "Sheep()" << endl;
        cnt++;
    }
    //卖羊
    ~Sheep()
    {
        cnt--;
    }
    //给同类提供共享机制，类的所有对象都能访问到他，而不是具体的单个对象独有,不在其内存空间
    //作用域在类里，但不是类或者他自己个人的的成员变量，只是在类里面定义，作用域是类和其所有的实例化对象
    //静态成员函数，不是真正的成员函数，没有this指针,访问不到非静态

    static int sheep_num()
    {
        return cnt;//在数据段上，对整个进程共享
    }
//其实并不是真正意义上的类的成员变量，在别人家寄宿而不是他们家的一员
//在数据段
private://加了private，不能够在类的外部被访问,不得不通过public的静态成员函数访问
    static int cnt;//这里只是声明，而不是定义
    //不占对象的内存空间，说明就不是对象的
    //想让这个变量和类挂钩，而不是和对象挂钩
};
void cos(){}
int Sheep::cnt= 0;
int main()
{
    Sheep s1;
    //两种访问方式

    //建议用类访问静态成员变量和成员函数，因为这种访问方式可读性强看到名字
    cout << Sheep::sheep_num() << endl;//比较好的
    cout << s1.sheep_num() << endl;//不会出现sheep_num(&s1)

    cout << Math::sin(1) << endl;
    cout << cos << endl;
    string s3;
    string s2("je");//string(const char*)

    cout << s3 << endl;
    cout << s3.size() << endl;
    cout << s3.length() << endl;
    cout << s2 << endl;
    const char *p = "world";//
    string s4(p);
    string s5(4,'a');
    string s6("12345",2,3);
    //string s7('k')错误
    cout << s5 << endl;
    cout << s4 << endl;
    cout << s6 << endl;
    return 0;
}
 */