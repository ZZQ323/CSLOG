#include<bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define RFOR(i,l,r) for(int i=r;i>=l;i--)
#define p(x,y) pair<x,y>
#define mkp make_pair

#ifdef DEBUG
#define cin fs
#endif 

class Electronic{
protected:
    int id;
    int power;
public:
    Electronic()=default;
    virtual void print()=0;
};

class Fan:virtual public Electronic{
protected:
    bool Fixed;
    int windpower;
public:
    void setdir(bool state){Fixed=state;}
    void setwp(int wp){windpower=wp;}
};


class Humidity:virtual public Electronic{
protected:
    float Capacity;
    float Max_Capacity;
public:
    int alaram(){
        if(Capacity>=Max_Capacity*0.5f){
            return 1;
        }else if(Capacity<Max_Capacity*0.5f && Capacity>=Max_Capacity*0.1f){
            return 2;
        }else if(Capacity<Max_Capacity*0.1f){
            return 3;
        }
    }

};

class HumFan:public Humidity,Fan{
private:
    int level;
public:
    HumFan()=default;
    void setlev(int lvl)
    {
        if(lvl==0){
            // ;
        }else if(lvl==1){
            Fixed=1;
        }else if(lvl==2){
            Fixed=0;
            windpower=2;
        }else if(lvl==3){
            Fixed=0;
            windpower=3;
        }
    }
    
    void print()override;
};

void HumFan::print()
{
    cout<<"加湿风扇--"<<"档位"<<level<<endl;
    cout<<"编号"<<id<<"--功率"<< power<<"W"<<endl;
    if(Fixed)
        cout<<"旋转吹风";
    else 
        cout<<"定向吹风";
    cout<<"--风力"<<windpower<<"级"<<endl<<"实际水容量"<<Capacity<<"升--";
    if(alaram()<=1)
        cout<<"水量正常";
    else if(alaram()==2)
        cout<<"水量偏低";
    else if(alaram()==3)
        cout<<"水量不足";
    cout<<endl;
}

/*
编号2002--功率2000W
旋转吹风--风力3级
实际水容量1升--水量不足
加湿风扇--档位0
编号3003--功率3000W
定向吹风--风力3级
实际水容量2升--水量偏低

"编号--功率W\
旋转吹风--风力级\
实际水容量升--水量不足\
加湿风扇--档位"
"<< <<"
*/



int main()
{
#ifdef DEBUG
fstream fs(strcat(getpwd(),'/in',ios::in));
#endif 
    
    int t ; cin>>t;
    while(t--){
        ;   
    }
    
    return 0;
}