#include<bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define RFOR(i,l,r) for(int i=r;i>=l;i--)
#define p(x,y) pair<x,y>
#define mkp make_pair

// #define firstdisplay 
// #define seconddisplay 
#define thirddisplay 

#ifdef firstdisplay
class Base{
    int a;
};

class son1:public Base{
    int b;
};

class son2:public Base{
    int c;
};

class son3:public son1,son2{
    int d;
};
#endif

#ifdef seconddisplay
class Base{
protected:
    int a;
};

class son1:virtual public Base{
protected:
    int b;
};

class son2:virtual public Base{
protected:
    int b;
};

class son3:virtual son1,son2{
protected:
    int d;
    void foo(){b+a;}
};
#endif 

#ifdef thirddisplay
class Base{
protected:
public :
    // virtual void foo(){;}
    // virtual void fooa(){;}
    // virtual void foob(){;}
    // virtual void fooc(){;}
}a;

class son:public Base{
protected:
public:
    virtual void fooc(){;}
    // void foo(){;}
}b;

#endif


int main()
{
#ifdef DEBUG
fstream fs(strcat(getpwd(),'/in',ios::in));
#endif 

    // cout<<sizeof(Base)<<endl;    
    // cout<<sizeof(son1)<<endl;    
    // cout<<sizeof(son2)<<endl;    
    // cout<<sizeof(son3)<<endl;    

    // cout<<sizeof(a)<<endl;
    // cout<<sizeof(b)<<endl;    

    // typedef void (*fun)();
    // cout<<sizeof(fun)<<endl;
    // cout<<sizeof(int*)<<endl;
    // cout<<sizeof(double*)<<endl;
    // cout<<sizeof(Base*)<<endl;

    return 0;
}


/*
gdb 是可以看到虚函数指针的，VS最好
所有的指针都是一样大的，突然发现大多数的指针大小都和int差不多。
virtual关键字，用于继承的时候就是确保如果父类中有相同来源的变量，确保只拷贝一份。
而不是确保父类没有同名的变量，如果说，父类有重名的变量，那么就是需要用作用于去限定。
virtual用于函数的话，就是会创建一个二维函数指针指向一个一维的虚函数指针数组。
只要基类写了，他的派生类就会自动共有一个虚函数表。这个虚函数表，就是一个二维指针数组。
虚函数表并不在类里面，所以如果去不断增加虚函数个数的话，很容易得到class 的大小是不变的。
*/