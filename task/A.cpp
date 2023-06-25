#include<bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define RFOR(i,l,r) for(int i=r;i>=l;i--)
#define p(x,y) pair<x,y>
#define mkp make_pair

#ifdef DEBUG
#define cin fs
#endif 

// 普通会员类
class Member 
{ 
protected:
	int id;
	int scores;
	string name;
public:
	Member(int vid,	int vscores,string vname):id(vid),scores(vscores),name(vname){;}

	virtual void add(int a);
	virtual int exchange(int a);
	virtual void print(); 
};

void Member::add(int payment)
{
	scores+=payment;
}

int Member::exchange(int getings)
{
	int ret=min(getings,scores)/100;
	scores-=ret*100;
	return ret*100;
}


void Member::print()
{	
	cout<<"普通会员"<<id<<"--"<<name<<"--"<<scores<<endl;
}

// 贵宾会员类
class VIP:public Member
{ 
private:
	int addrate;
	int exrate;
public:
	VIP(int vid,int vscores,string vname,int vaddrate,int vexrate):Member(vid,vscores,vname),addrate(vaddrate),exrate(vexrate){;}
	void add(int a)override;
	int exchange(int a)override;
	void print()override;
};

void VIP::add(int payment)
{
	scores+=payment*addrate;
}

int VIP::exchange(int getings)
{
	int ret=min(getings,scores)/100;
	assert(exrate);
	scores-=ret*100/exrate;
	return ret*100;
}


void VIP::print()
{	//贵宾会员8001--Jane--140
	cout<<"贵宾会员"<<id<<"--"<<name<<"--"<<scores<<endl;
}

int main()
{
	#ifdef DEBUG
		fstream fs(strcat(getpwd(),"/in",ios::in));
	#endif 
	// 创建一个基类对象指针
	Member* pm;// ....其他变量自行编写
	int temp;
	int id;	int scores;	string name;	
	while(cin>>id>>scores>>name){
		// 输入数据，创建普通会员对象mm
		// 使用指针pm执行以下操作：
		// 1、pm指向普通会员对象mm
		// 2、输入数据，通过pm执行积分累加和积分兑换
		// 3、通过pm调用打印方法输出
		Member mm(id,scores,name);
		pm=&mm;
		cin>>temp;
		pm->add(temp);
		cin>>temp;
		pm->exchange(temp);
		pm->print();

		// 输入数据，创建贵宾会员对象vv
		// 使用指针pm执行以下操作：
		// 1、pm指向贵宾会员对象vv
		// 2、输入数据，通过pm执行积分累加和积分兑换
		// 3、通过pm调用打印方法输出
		cin>>id>>scores>>name;
		Member vv(id,scores,name);
		pm=&vv;
		cin>>temp;
		pm->add(temp);
		cin>>temp;
		pm->exchange(temp);
		pm->print();
	}

	return 0;
}






