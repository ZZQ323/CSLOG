#include<bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define RFOR(i,l,r) for(int i=r;i>=l;i--)
#define p(x,y) pair<x,y>
#define mkp make_pair

#ifdef DEBUG
#define cin fs
#endif 

class Metal{
private:
    int hardness;
    int weight;
    int volume;
public:
/*
int hardness,weight,volume,   
*/
    Metal()=default;
    Metal(int vhardness,int vweight,int vvolume)
    :hardness(vhardness),weight(vweight),volume(vvolume){;}


    Metal& operator++(){++hardness;weight+=weight/10;volume+=volume/10;return *this;}
    Metal operator--(int){Metal ret(*this);--hardness;weight-=weight/10;volume-=volume/10;return ret;}

    friend Metal operator+(Metal& var1, Metal& var2){return Metal(var1.hardness+var2.hardness,var1.weight+var2.weight,var1.volume+var2.volume);}
    friend Metal operator-(Metal& var1, Metal& var2){return Metal(var1.hardness-var2.hardness,var1.weight-var2.weight,var1.volume-var2.volume);}
    friend Metal operator*(Metal& var, double factor){return Metal(var.hardness,var.weight,var.volume*factor);}
    friend Metal operator*(double factor, Metal& var){return Metal(var.hardness,var.weight,var.volume*factor);}
    friend istream& operator>>(istream& in,Metal& var){in>>var.hardness>>var.weight>>var.volume;return in;}

    template<class T>
    friend ostream& operator<<(ostream& out,T&& var){out<<"硬度"<<var.hardness<<"--重量"<<var.weight<<"--体积"<<var.volume;return out;}
};

int main()
{
#ifdef DEBUG
fstream fs(strcat(getpwd(),'/in',ios::in));
#endif 
    Metal var1,var2;
    int n;
    cin>>var1>>var2>>n;
    cout<<var1+var2<<endl<<var1*n<<endl<< ++var1 <<endl ;
    var2--;
    cout<<var2<<endl;
    return 0;
}