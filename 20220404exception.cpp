//
// Created by 74476 on 2022/4/4.
//

//this is Jarvis Chan
#if 0
#include <exception>
#include <CString>
#include <iostream>
#include <vector>
using namespace std;
class FrameHeadError : public exception
{
public:
    const char*what() const throw()//固定格式
    {
        return "frameheaderror";
    }
};
class FrameTailError:public exception
{
public:
    const char*what() const throw()
    {
        return "frametailerror";
    }
};
int func(int a,int b)
{
    if(b)
        return a/b;//if b=0,will error
        else
    {
            cout<<"division 0"<<endl;
            throw "division 0";
            //throw 10;
    }
}
bool func2(char *str)
{
    if(!str)
        throw "nullpointer";
    int len;
    len = strlen(str);
    //协议##name=zhangsan;age=18##
    if(!(str[0]=='#' && str[1]=='#'))//帧头错误
    {
        FrameHeadError err;
        throw err;
    }
    if(!(str[len-1]=='#'&&str[len-2]=='#'))//帧尾错误
    {
        FrameTailError err;
        throw err;//抛出异常对象
    }

    return true;
}

//

int main()
{
    //保护代码块
    try{
    vector<int> arr(3,10);
    for(int i = 0;i<3;i++)
        cout<<arr.at(i)<<endl;
        arr.at(3)=100;//will out of range,you should catch it in correct type
        cout<<"next"<<endl;//this wont be run
    }
    ///...dont care which is error,can catch all error
    //the program wont stop if we can catch exception,but we wanna know which is error
    //try(...)can catch all err
    catch(out_of_range&err){//内部会throw一个实例化对象oor，赋值给err，如果是普通的数据类型就会产生额外的东西，oor x='y',触发拷贝构造函数的调用
        cout<<"hello"<<endl;
        cout << err.what()<<endl;//what err
    }
    //。。。。。。。。。。。。。。。。。。
    //same as python's try-except
    try {
        int ret = func(10, 0);
        cout << "end.." << endl;
    }
    //once u divide 0,it will be catched
    catch(const char*msg){//msg
        cout<<"error fuc"<<endl;
        cout<<msg<<endl;//hello world
    }
    catch(int msg)//根据抛出的数据类型来捕获对应的异常
    {}
    catch(FrameHeadError&err)
    {
        cout << err.what()<<endl;//what in exception class.
    }
    catch(FrameTailError&err)//err can be catched
    {
        cout<<err.what()<<endl;
    }
    return 0;
}
#endif