#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-8;


signed main(void)
{
    long long n;
    int k=0;
    cin>>n;
    while((1ll<<k)<=n)k++;
    cout<<k-1<<endl;
    return 0;
}
