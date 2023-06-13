#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

const int mod=1000000009;
const int N=210;

int mapp[N][N],dp[N][N];
bool done[N][N];
int minn,ans,n;

#define nx (x+Fx[i])
#define ny (y+Fy[i])
const int Fx[4]={1,-1,0,0,};
const int Fy[4]={0,0,1,-1,};
inline bool check(int x,int y){return x>=1 && x<=n && y>=1 && y<=n ;}


void DFS(int x,int y,int sum,int deep)
{
    done[x][y]=1;
    if(sum>=dp[x][y])return ;
    else dp[x][y]=sum;
    if(x+y==n+1){
        if(sum<minn)minn=sum,ans=1;
        else if(sum==minn)ans=(ans+1)%mod;
    }else{
        struct NN{int val;int x;int y;}buffer[5];int k=0;
        for(int i=0;i<4;i++){
            if( check(nx,ny) && !done[nx][ny] ){
                buffer[++k].val=mapp[nx][ny];
                if(nx+ny!=n+1)buffer[k].val+=mapp[n+1-ny][n+1-nx];
                buffer[k].x=nx;buffer[k].y=ny;
            }
        }
        if(k)sort(buffer+1,buffer+1+k,[&](const NN&var1,const NN&var2)->bool {
            return var1.val<var2.val;
        });
        for(int i=1;i<=k;i++){
            if(sum+buffer[i].val<=minn)
                DFS(buffer[i].x,buffer[i].y,sum+buffer[i].val,deep-1);
        }
    }
    done[x][y]=0;
}

signed main(void)
{
    while (~scanf("%d",&n) && n){
        memset(done,0,sizeof(done));
        minn=INT_MAX,ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",mapp[i]+j);
            }
        }
        DFS(1,1,0,n*n);
        printf("%d\n",ans%mod);
    }

    return 0;
}

/*

*/
