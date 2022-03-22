//
// Created by 74476 on 2022/3/19.
//

//this is Jarvis Chan
using namespace std;
#include <iostream>
#include <Cstring>
class Test
{
public:
    int data;
    char *ptr;
    Test()
    {
        cout<<"test()"<< endl;
        data = 0;
        ptr = new char[10];

    }
    Test(int data,const char *src)
    {
        //合法性
        this->data = data;
        //空指针判断，防止段错误
        if(src)
        {
            this->ptr = new char[strlen(src)+1];
            strcpy(this->ptr,src);
        }
        else
            ptr = new char[10];
    }
    //拷贝构造函数，当用一个已经构造好的对象去初始化新的对象的时候会被调用,test t1=t2;
    //如果不调用会自动生成，浅拷贝，如果内部有指针会出问题指向同一块内存空间
    Test(const Test &t)
    {
        //深拷贝，在用
        cout<< "kaobeigouzaohanshu" << endl;
        this->data = t.data;
        //this->ptr = t.ptr;不能这样这是浅拷贝
        if(strlen(t.ptr))
        {
            this->ptr = new char[strlen(t.ptr)+1];//长度可能为0,还要为/0留空间
            strcpy(this->ptr,t.ptr);
        }
        else
            ptr = new char[10];

    }
    ~Test()
    {
        if(ptr)
        delete[] ptr;//释放指针变量在堆上的空间
    }
    //重载
    //这个函数肯定要被一个对象调用
    //要自动触发
    //该运算符重载函数由左操作数调用，右操作数当作实参传递给该函数
    // t1+t3,由t1调用t1.operator +(t3)
    //返回值应该是一个test对象

    Test operator +(Test &t)//引用提高效率，不用再次实例化对象
    {
        //所有的this是左操作数t1
        Test val;//保存最后执行的结果
        val.data - this->data +t.data;//this是左操作数t1.data也就是调用函数的人
        val.ptr  = new char[strlen(this->ptr)+strlen(t.ptr)+1];//左值ptr+右的ptr
        //字符串追加
        //堆空间初始化为0，要不然追加后会有乱码。
        memset(val.ptr,0,strlen(this->ptr)+strlen(t.ptr)+1);
        strcat(val.ptr,this->ptr);//拼string
        strcat(val.ptr,t.ptr);
        cout <<"operator" << endl;
        //这步会触发拷贝构造函数，return就是一种拷贝，系统会用一块空间保存返回，临时对象
        return val;//保存了最终运行的结果，是个对象
    }

    bool operator >(const Test &t)//没有必要改，所以
    {
        cout <<">"<< endl;
        if(strcmp(this->ptr,t.ptr)>0)
            return true;
        return false;
    }
    char operator [](int index)//index下标
    {
        cout<<"[]" << endl;
        if(index<0||index>=strlen(ptr))
            return '\0';
    }
    Test & operator ++()//++t1,前置++,返回引用不会产生新对象
    {
        cout<<"font++" << endl;
        ++data;
        return *this;//返回调用的对象。这里*this不会随着函数结束而被销毁，因此可以引用
    }
    //后置++
    //这里不用引用是因为引用是一个 存在 的变量的别名
    //引用要引用存在的东西，在这个函数中，如果返回引用，
    //不能返回这个函数栈上对象的引用，会被自动回收掉，只能返回对象
    //因此只要能保证返回值不在栈上，返回值就能引用
    /*
     * for example
     * Test &func(Test &t)
     * {
     * return t;
     * }
     * Test t3;
     *func(t3)//t3不会随着函数结束而被销毁，因此引用有效。
     */
    Test operator ++ (int)//后置返回加之前的
    {
        cout <<"back++"<<endl;
        //用临时变量保存++前状态
        Test tmp = *this;//huidiaoyong kao
        data ++;
        return tmp;//tmp is该函数栈上的，用了引用来返回他没办法，因为tmp已经被销毁了
    }
    //输出运算符重载，双目运算符,cout要是个test对象才能用，cout<<t1
    //cout is in ostream
    //os接受cout对象，test &t接受右操作数
    //左值要调用函数，但是不是test对象，所以只能把它穿进去，cout，t1分别是ostream，test对象，因此用那两个接受
    friend ostream &operator <<(ostream &os,const Test &t)//左操作数cout数不是test对象，可以将左和后操作数传进去，形参两个
    {
        //返回值不是引用会有临时对象，复杂。
        //friend
        os << t.data << endl;
        os << t.ptr << endl;
        return os;//相当返回cout
    }
};
#if 0
int main()
{

    Test t1;
    Test t2 = t1;
    cout << t2.data << endl;
    cout  << t1.ptr << endl;
    Test t3(10,"world");
    //用已经构造好的t1+t3的对象去初始化t4
    //operator+返回一个对象，会调用拷贝构造函数，类似test t4=val。
    //测试发现没有拷贝构造函数
    //原则上在这里被调用了两次拷贝构造函数，一次return val，一次下面这句
    //编译器聪明，不会这样做。编译器对临时对象的优化
    Test t4 = t1+t3;//20,helloworld重载加号
    cout << t4.data << endl;
    cout << t4.ptr << endl;

    Test t1(10,"Hello");
    Test t2(20,"heLlo");
    if(t1>t2)
    {
        cout <<"t1>t2"<< endl;
    }
    else
        cout<< "t1<=t2" << endl;
    //重载[]
    cout<<t1[3]<< endl;
    //重载++，--，达到++data，data自增

    Test t1(10,"Hello");
    Test t2;
    t2 = ++t1;
    cout << t1.data << endl;
    cout << t2.data <<endl;
    Test t3;
    t3 = t1++;
    //前置效率高。
cout << t3.data << endl;//11
cout << t1.data << endl;//12

    Test t1(10,"fuck");
    cout << t1 << endl;
    return 0;
}
#endif