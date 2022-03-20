//
// Created by 74476 on 2022/2/23.
//

//this is Jarvis Chan
//静态成员变量，给同类共享，用于统计实例化了多少次

//成员变量和成员函数分开储存，
//普通成员变量储存于对象中，函数存储与全局数据区
/*
#include <iostream>

using namespace std;
int cnt = 0;


class Sheep
{
public:
    char name[32];
    int age;
    //买羊
    Sheep()
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
    static int cnt;//这里只是声明，而不是定义
    //不占对象的内存空间，说明就不是对象的
    //想让这个变量和类挂钩，而不是和对象挂钩
};
int Sheep::cnt = 0;//定义了sheep类的静态成员变量,如果不初始化默认为0
int main(){
//构造了10个对象
    Sheep *p = new Sheep[10];//buy 10 sheep;
    //how to remember the exist sheep number?
    cout << Sheep::cnt << endl;
    cnt = 10;
    Sheep s1;//cnt = 11
    cout << Sheep::cnt << endl;
    Sheep s2;//第十二个对象

    cout << sizeof(s2) << endl;//如果cnt是。为40，不是则36

    cout << s2.cnt << endl;
    cout << s1.cnt << endl;
    return 0;
}
 */
/*
class C1
{
public:
    int i,j,k;
protected:
private:
};

class C2
{
public:
    int i,j,k;
public:
    //内存：自下而上：代码段，数据段，堆空间，栈空间，xxx

    //成员函数在代码段，没占对象的内存，构造函数和析构函数也在这里
    //能被所有实例化对象调用
    //函数名字相同，如何知道是谁在调用？内部的实现？
    int getk(){return k;}
    void setk(int val){k = val;}
};

class ABC
{
public:
    int x,y,z;
    //内部隐藏调用者地址，保证不出错，各用各的值
    ABC(int x,int y,int z)//内部：ABC(ABC *const this,int x,y,z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};
ABC a(1,2,3);//调用的时候内部会先传地址（&a,1,2,3)
ABC b(1,2,3);//ABC（&b,1,2,3)
int main()
{
    //在栈分配空间 12字节
    //
    //C1 c1;
    C2 c2,c3;
    //cout << sizeof(c1) << endl;
    //cout << sizeof(c2) << endl;
    c2.k = 100;
    //编译器自动加入了一个指针作为形参int (C2 * const this)指向c2
    //int getk(C2 * const this){return this -> k}
    //this指向C2
    //当调用时，把他的地址传进去getk(&xx)，xx的地址赋值给this指针，然后return this -> k获得xx的k
    //this指针，不能再指向别的对象，用于
    c2.getk();
    c3.getk();
    //void (C2 * const this, int)，this用来指向调用这个函数的对象
    c2.setk(100);
    return 0;
}
*/

