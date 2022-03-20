//
// Created by 74476 on 2022/2/28.
//
//
//this is Jarvis Chan
//append,如果需要追加全部整个的字符串就直接+，如果是部分就用append
//比较大小
//w位置查找
//替换replace
//插入

#include <iostream>
#include <Cstring>

using namespace std;

/*
int main()
{
    /*
    string s1 = "##temp=";
    string s2;
    float val = 33.6;
    s2 = to_string(val);//将float转成string，double和int也可以
    string s3;
    s3 = s1+s2;
    cout << s3 << endl;
     */
    /*
    string s1("123"),s2("abc");
    string s3;
    s3 = s1.append(s2);//s2追加到s1后面

    cout << s1 << endl;
    cout << s3 << endl;
//same as python
    s1.append(s2,1,2);
    cout << s1 << endl;
    s1.append(3,'k');
    cout << s1 << endl;
    s1.append("ABCDE",2,3);
    cout << s1 << endl;
     */
    /*
    string s1 = "hello,world";
    string s2 = "world";
    bool ret;//result
    ret = s1 > s2;
    if(ret)
        cout << "s1>s2" << endl;
    else
        cout << "s1<s2" << endl;
    ret = s2>s1;
    if(ret)
        cout << "s1<s2" << endl;
    else
        cout << "s1>s2" << endl;
    cout << s1.compare(s2) << endl;
    cout << s2.compare(s1) << endl;
    cout << s1.compare(1,2,s2,0,3);
    int pos;
    pos = s1.find("e");
    if(pos = s1.find("hello")!=string::npos)//返回下表,strstr判断后一个是不是前一个的子串
        cout << pos << endl;
    else
        cout << "no" << endl;
    if(pos = s1.find(',')!=string::npos)//如果return的不是no position
    cout << pos << endl;
    else
    cout << "no" << endl;

    string names[4];
    names[0] = "zh";
    names[1] = "lh";
    names[2] = "ls";
    names[3] = "zs";
    //check h
    for(int i = 0;i<4;i++)
    {
        if(names[i].find("h") != string::npos)
            cout << names[i] << endl;
    }
    for(int i = 0;i<4;i++)
    {
        if(names[i].find("z") == 0)//在整个字符串的第一位，查找性别
            cout << names[i] << endl;
    }
     */
    /*
    string s1 = "jarvis chan";//dst
    //前面是要替换的位置，后面是用src字符串的哪个部分替换
    s1.replace(7,10,"zhixin",0,5);//
    cout << s1 << endl;
    s1.replace(1,3,4,'0');
    cout << s1 << endl;
    int n = s1.find("0000");
    if(n!=string::npos)//提高容错
        s1.replace(n,4,"kkk");
    cout << s1 << endl;

    s1.erase(1,3);
    cout << s1 << endl;
    //want to delete zhixi
    n = s1.find("zhixi");
    //先看看能不能找到
    if(n != string::npos)
        s1.erase(n,5);//删5个
    cout << s1<< endl;
     */
/*
    string s1("jarvis chan"),s2("deng zhi xin");
    s1.insert(2,"123");
    cout << s1 << endl;
    s1.insert(6,s2);
    cout << s1 << endl;
    s1.insert(3,5,'x');
    cout << s1 << endl;
    s1.insert(3,"hello",1,3);
    cout << s1 << endl;
    string s3 = "world";
    s1.insert(3,s3,1,3);
    cout << s1 << endl;
*/
//dongtai数组动态数组
/*
    return 0;
}
*/