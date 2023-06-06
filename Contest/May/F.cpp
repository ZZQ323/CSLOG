#include<bits/stdc++.h>

using namespace std;

const int N=1e3+10;
typedef long long LL;

int p[N],s[N],k[N];
LL dp[N];

signed main(void)
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",p+i);

    for(int i=1;i<=n;i++)
        scanf("%d",s+i);

    for(int i=1;i<=n;i++)
        scanf("%d",k+i);

    for(int i=1;i<=n;i++){
        int w=min(s[i],k[i]);
        for(int j=m;j>=p[i];j--){
            dp[j]=max(dp[j],dp[j-p[i]]+w);
        }
    }
    printf("%lld\n",dp[m]);

    return 0;
}
