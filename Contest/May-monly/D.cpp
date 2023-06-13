#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

const int N=1e5+10;
struct Node{
    int deep,pos;
    Node(int vdeep,int vpos):deep(vdeep),pos(vpos){;}
};
int n,k;
bool done[N];

void BFS()
{
    queue<Node> qe;
    qe.push(Node(0,n));
    while(qe.size()){
        Node now=qe.front();qe.pop();
        int deep=now.deep;
        int pos=now.pos;
        if(pos==k){
            printf("%d\n",deep);
            break;
        }else{
            if(done[pos])continue;
            else done[pos]=1;
            if(pos-1>=0)
                qe.push(Node(deep+1,pos-1));
            if(pos+1<=100000)
                qe.push(Node(deep+1,pos+1));
            if(pos*2<=100000)
                qe.push(Node(deep+1,pos<<1));
        }
    }
}

signed main(void)
{
    while(~scanf("%d %d",&n,&k)){
        memset(done,0,sizeof(done));
        if(n>=k)printf("%d\n",n-k);
        else BFS();
    }
    return 0;
}
