//
// Created by 74476 on 2022/3/2.
//
//鸡肋的东西不用搞
//三种不同的继承方式private最大
/*
#include <string>
//this is Jarvis Chan
using namespace std;
#include <iostream>
class Person
{
public:
    void set_age( int age)
    {
        _age = age;
    }
    int get_age(int age)
    {return _age;}
    void set_name(string name)
    {
        _name = name;
    }
    string get_name()
    {
        return _name;
    }
   void print()
   {
       cout << _name << endl;
       cout << _age << endl;
   }

protected://和protected没有继承关系的时候是一样的，如果是继承关系，
    string _name;//
    int _age;
};
class Student : public Person
{
public:

protected:
    string _stuid;
};
class Teacher : public Person
{
protected:
    string _jobid;//加下划线保护可读性
};
class A//jilei
{
public:
    int x;
protected:
    int y;
private:
    int z;
};
//paishenglei
class B : public A{
    //jibeile a de way
};
class D:protected A
{
 */
    /*
protected:
    int x;
protected:
    int y;
private:
    int z;
     */
    /*
};
int main()
{
    Teacher t;
    Student s;
    s.set_age(10);
    s.set_name("lisi");
    cout << s.get_name() << endl;
    s.print();
    cout << sizeof(Person) << endl;
    cout << sizeof(Student) << endl;
    cout << sizeof(Teacher) << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    B b;
    b.x = 100;
    
    return 0;
}
*/