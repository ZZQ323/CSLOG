#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
LL C[100][100];

void init()
{
    C[0][0]=1;
    for(int i=1;i<=51;i++){
        C[i][0]=1;
        C[i][1]=i;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
}

signed main(void)
{
    init();
//    printf("%lld\n",C[6][3]);
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%lld",C[n+m-2][n-1]);

    return 0;
}
