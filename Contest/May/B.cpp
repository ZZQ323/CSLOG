#include<bits/stdc++.h>

using namespace std;

const int N=10;
int n,m,t,ans,sx,sy,fx,fy;

int mapp[N][N];
bool done[N][N];

#define nx (x+Fx[i])
#define ny (y+Fy[i])
const int Fx[4]={1,-1,0,0,};
const int Fy[4]={0,0,1,-1,};
inline bool check(int x,int y){return x>=1 && x<=n && y>=1 && y<=m ;}

void DFS(int x,int y)
{
    done[x][y]=1;
    if(x==fx && y==fy){
        ans++;
    }else{
        for(int i=0;i<4;i++){
            if(check(nx,ny) && !done[nx][ny] && mapp[nx][ny]){
                DFS(nx,ny);
            }
        }
    }
    done[x][y]=0;
}

signed main(void)
{
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mapp[i][j]=1;

    while(t--){
        int x,y;
        scanf("%d %d",&x,&y);
        mapp[x][y]=0;
    }

    DFS(sx,sy);
    printf("%d",ans);

    return 0;
}
