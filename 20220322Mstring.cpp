//
// Created by 74476 on 2022/3/22.
//

//this is Jarvis Chan
/*
 * what can Mstring do?
 * 1.store string
 * 2.enlarge itself
 * 3.can find item by index
 * 4.can use "=" to set value to Mstring
 * 5.can use + to append
 * 6.can compare with <,><....
 */
//此文件用于实现函数，h文件用于声明函数
#include "Mstring.h"
#include <Cstring>
using namespace std;
//实现默认构造函数,Mstring s就会被调用
Mstring::Mstring() {
    _data = new char[DEFAULTLEN];
    _maxlen = DEFAULTLEN;
    _len = 0;
}
//Mstring s("hello")
//带参数的构造函数
Mstring::Mstring(const char *data) {
    //hello+/0,we can use more than 6
    cout <<"Mstring::Mstring(const char *data)" << endl;
    int len = strlen(data)+1;
    _data = new char[len];
    _maxlen = len;

    strcpy(_data,data);
    _len = len-1;//长度不包括/0

}
//拷贝构造函数，用一个已经实例化的对象去实例化另一个对象会被调用,实现深拷贝
Mstring::Mstring(const Mstring &t) {
    cout<<"Mstring::Mstring(const Mstring &t)"<< endl;
    _data = new char[t._maxlen];
    _maxlen = t._maxlen;
    _len = t._len;
    strcpy(_data,t._data);//copy
}
//析构函数
Mstring::~Mstring() {
    if(_data)
        delete[] _data;
    cout<<"Mstring::~Mstring()"<< endl;
}
//重载= s1=s2   s3=s1=s2
//返回的不是函数栈上的对象，this不在里面，所以可以引用
Mstring & Mstring::operator =(const Mstring &t)
{
    //释放原来申请的空间
    cout<<"string & Mstring::operator =(const Mstring &t)"<<endl;
    delete[] _data;
    //重新申请空间
    _data = new char[t._maxlen];
    _maxlen = t._maxlen;//youzhi gei zuozhi
    _len = t._len;
    strcpy(_data,t._data);
    return *this;//返回左操作数,
}
//它不属于mstring真正的成员函数，因为前面有friend友元函数，朋友不是我的家人
ostream &operator<<(ostream &os,const Mstring &t)//cout<<<S1<<endl;
{
   // cout<<"ostream &operator<<(ostream &os,const Mstring &t)"<< endl;
  //  os << t._data;//不换行
    return os;
}
//对_data所知指向的堆空间扩容
//size is 扩容大小
//原来的小房子可以卖掉，拷贝完后放掉，避免内存泄漏
void Mstring::extend(u32_t size) {
    //先保存一下原来空间首地址，要不然分配空间时原先空间会找不到，没法释放
    char *tmp = _data;
    //add
    _data = new char[size];
    //copy
    strcpy(_data,tmp);//strcpy只能字符串，memcpy啥都可以
    //delete
    delete []tmp;
    _maxlen = size;//更新空间最大值，len表示存储的字符串的长度，长度拷过去不变
}
//重载 []
char Mstring::operator [](u32_t index){
    if(index>=_len) {
        cout << "index out of range!" << endl;
        return '\0';
    }
        return _data[index];//return *(_data +index)
}
//+    s1+s2,双目，左操作数调用，右操作数当作实参传入
Mstring Mstring::operator+(const Mstring &t) {
    //要用一个对象保存结果，还要返回
    Mstring ret;//result，保存运算后的结果

    ret._maxlen =  this->_maxlen + t._maxlen;//this是左值，默认存在这个指针
    ret._len = this->_len+t._len;
    //
    ret._data = new char[_maxlen];
    //分别追加两部分内容到新的data，最好data先初始化为0,防止覆盖了原有数据出错误
    memset(ret._data,0,_maxlen);
    strcat(ret._data,this->_data);
    strcat(ret._data,t._data);
    return ret;
}
//string追加函数,t = s1.append(s2)
Mstring & Mstring::append(const Mstring &t) {
    //追加后len可能小于maxlen，可能大于超过了，空间不够
    //1.this->_len +t._len<
    if(this->_len +t._len>=this->_maxlen) {
        extend(this->_len+t._len+1);//扩容,不需要操心空间释放，已经弄了
    }
        strcat(_data,t._data);//追加
        _len+=t._len;
        return *this;//返回调用者this
}
//如果传入的是字符串常量的追加
Mstring & Mstring::append(const char * data) {
    cout <<"Mstring & Mstring::append(const char * data"<< endl;
    if(this->_len+strlen(data)>=this->_maxlen)
    {
        extend(this->_len+ strlen(data)+1);//扩容
    }
    strcat(_data,data);//追加
    _len +=strlen(data);
    return *this;
}
//重载>
bool Mstring::operator>(Mstring &t) {
//    if(strcmp(_data,t._data))//如果返回值大于0说明前比后大，this比&t大
//    {
//        return true;
//    }
    //自己实现strcmp，有不同字符时停止,继续比下去的条件是前面和后面都不是、0
    int i = 0;
    while(_data[i]!='0'||t._data[i]!='0')
    {
        if(_data[i]==t._data[i])//
        {
            i++;//避免死循环
            continue;
        }
        if(_data[i]>t._data[i])
            return true;
        else
            return false;
    }
    return false;//相等相对于大于也是false
}
bool Mstring::operator<(Mstring &t) {
    if(strcmp(_data,t._data))//如果返回值大于0说明前比后大，this比&t大
    {
        return true;
    }
    return false;
}
//返回字符串长度
u32_t Mstring::length() const {
    return _len;
}
void Mstring::destroy() {
    //手动释放_data 指针在堆上申请的空间
    //之所以要判断，假如对象实现了两次，第二次会释放空指针。
    if(_data)
        delete[] _data;
    //但是会出现destroy和析构函数双重释放，所以弄null，调用析构函数就会出现逻辑假，避免多次释放
    _data = NULL;

}