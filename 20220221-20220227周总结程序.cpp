//
// Created by 74476 on 2022/2/26.
//

//this is Jarvis Chan
//1.拷贝构造函数
//2.静态成员变量和静态成员函数
/*
#include <iostream>
using namespace std;
int stunum = 0;
class TrueLightStu
{
public:
    char name[32];
    int score;
    //与类同名的构造函数
    //在这里对成员对象进行初始化
    TrueLightStu()
    {
        char grade[32] = "xiao";
        score = 0;
        cout << "his/her name is" << name << "," << "score is:" << score << endl;
        stunum ++;
    }
    //拷贝构造函数
    TrueLightStu(const TrueLightStu &T)
    {
        cout << "TrueLightStu(const TrueLightStu &T)" << endl;
        score = T.score;

    }
    static int get_ad(int age)
    {
        return age;
    }
private:
    static int age;
public:
    ~TrueLightStu()
    {
        cout << "no"<< endl;}
};
int main()
{
    TrueLightStu t1;
    t1.score = 100;
    t1.get_ad(18);
    //由于1和2考试成绩和年龄一样，这里直接用t1初始化t2,通过拷贝构造函数实现
    //但由于年龄只能用静态成员函数一个个输入，因此年龄不能直接拷贝
    //这里相当于把t1作为参数放入TrueLightStu(const TrueLightStu &T)
    //
    TrueLightStu t2 = t1;//调用拷贝构造函数,该初始化不调用构造函数
    //测试t2
    cout << t2.score << endl;
    TrueLightStu t3;
    cout << stunum << endl;
    return 0;
}
 */
