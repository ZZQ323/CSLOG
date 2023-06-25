#include<bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define RFOR(i,l,r) for(int i=r;i>=l;i--)
#define p(x,y) pair<x,y>
#define mkp make_pair

#ifdef DEBUG
#define cin fs
#endif 

template<class T,size_t N>
auto  Max(T (&var)[N],int ql,int qr)-> T{T maxn=var[ql];FOR(i,ql,qr)maxn=max(maxn,var[i]);return maxn;}

//只支持整数类型的加密类界面
template<class T>
class Cryption
{
private:
	T ptxt[100]; //明文
	T ctxt[100]; //密文
	T key; //密钥
	int len; //长度
public:
    //参数依次对应密钥、明文、长度
    template<size_t N>
	Cryption(T tk, T (&tt)[N],int length);
    //加密
	void encrypt();

	void print() //打印，无需改造
	{
		int i;
		for (i = 0; i < len - 1; i++)
		{
			cout << ctxt[i] << " ";
		}
		cout << ctxt[i] << endl;
	}
};

template<class T>
template<size_t N>
Cryption<T>::Cryption(T tk, T (&tt)[N],int length):key(tk),len(length){ memcpy( ptxt, tt, sizeof(tt) );}


template<class T>
void Cryption<T>::encrypt()
{
    T maxn=Max(ptxt,0,len-1);   
    FOR(i,0,len-1)
        ctxt[i]=maxn-ptxt[i];
    FOR(i,0,len-1)
        ctxt[i]+=key;
}

//支持三种类型的主函数
int main()
{
#ifdef DEBUG
    fstream fs(strcat(getpwd(),'/in',ios::in));
#endif 


	int i;
	int length; //长度
	int ik, itxt[100];
	double dk, dtxt[100];
	char ck, ctxt[100];
	//整数加密
	cin >> ik >> length;
	for (i = 0; i < length; i++)
	{
		cin >> itxt[i];
	}
	Cryption<int> ic(ik, itxt, length);
	ic.encrypt();
	ic.print();
	//浮点数加密
	cin >> dk >> length;
	for (i = 0; i < length; i++)
	{
		cin >> dtxt[i];
	}
	Cryption<double> dc(dk, dtxt, length);
	dc.encrypt();
	dc.print();
	//字符加密
	cin >> ck >> length;
	for (i = 0; i < length; i++)
	{
		cin >> ctxt[i];
	}
	Cryption<char> cc(ck, ctxt, length);
	cc.encrypt();
	cc.print();

	return 0;
}

/*
10 5 1 2 3 4 5
11.11 4 1.1 2.2 3.3 4.4
O 3 a b c
*/