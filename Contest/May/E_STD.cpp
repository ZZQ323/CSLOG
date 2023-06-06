#include<bits/stdc++.h>

using std::pair;
using std::queue;
using std::make_pair;

typedef long long LL;
#define pii pair<int ,int >
#define mkp make_pair

const int mod=1000000009;
const int N=210;
int mapp[N][N],dis[N][N],dp[N][N];
bool done[N][N];
int n,m;

#define nx (Fx[i]+x)
#define ny (Fy[i]+y)
const int Fx[4]={1,-1,0,0,};
const int Fy[4]={0,0,1,-1,};
inline bool check(int x,int y){return x>=1 && x<=n && y>=1 && y<=n;}


int DFS(int x,int y)
{
    if(dp[x][y])return dp[x][y];
    if(dp[1][1])return dp[1][1]=1;
    
    for(int i=0;i<4;i++){
        if( check(nx,ny)  &&  nx+ny<=n+1 &&  dp[nx][ny]==dp[x][y]-mapp[x][y]){
            dp[x][y]=(dp[x][y]+DFS(nx,ny))%mod;
        }
    }
    return dp[x][y];
}

void BFS()
{
    queue<pii>qe;
    qe.push(mkp(1,1));
    while(qe.size()){
        pii now=qe.front();qe.pop();
        int x=now.first;
        int y=now.second;

        for(int i=0;i<4;i++){
            if(check(nx,ny)  &&  nx+ny<=n+1 && dis[nx][ny]>dis[x][y]+mapp[x][y]){
                dis[nx][ny]=dis[x][y]+mapp[nx][ny];
                qe.push(mkp(nx,ny));
            }
        }
    }
    int x0,y0;
    int minn=INT_MAX;
    for(int i=1;i<=n;i++){
        if(dis[i][n+1-i] < minn){
            minn=dis[i][n+1-i];
            x0=i,y0=n+1-i;
        }
    }
    DFS(x0,y0);
    printf("%d\n",dp[x0][y0]);
}

signed main(void)
{
    while (~scanf("%d",&n) && n){
        memset(dp,0,sizeof(dp));
        memset(mapp,0,sizeof(mapp));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",mapp[i]+j);
                dis[i][j]=mod+2;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mapp[i][j]+=mapp[n+1-j][n+1-i];
                mapp[n+1-j][n+1-i]=0;
            }
        }
        BFS();
    }
    
    return 0;
}
