#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<stdarg.h>

const N=250000;
int halfPrime[N]={0};int cnt=0;
int n;

int prime(int p)
{
    for(int i=2;i<=(int)(sqrt(p));i++){
        if(p%i==0)
            return 0;
    }
    return 1;
}

int palindrome(int m)
{
    char num[10]={0};
    // itoa(m,num,10);//最后一个参数是说要转换成几进制
    for(int i=0;m;i++){//真实情况
        num[i]=m%10+'0';
        m/=10;
    }
    int len=strlen(num);
    for(int i=0;i<len-i-1;i++){//swap() C还是没有
		int temp=num[i];
		num[i]=num[len-i-1];
		num[len-i-1]=temp;
	}
    	
    int l=0,r=len-1;
    while(l<r){
        if(num[l]!=num[r])
            return 0;
        l++,r--;
    }
    return 1;
}

void mergesort(int ql,int qr,int*const dest)
{
    int mid=ql+qr>>1;
    int len=qr-ql+1;
    if(ql<qr){
        mergesort(ql,mid,dest);
        mergesort(mid+1,qr,dest);
    }else{
        return ;
    }
    int l=ql,r=mid+1;
    int* temp=(int*)malloc( sizeof(int)*(len+10) );int count=0;
    while(l<=mid && r<=qr){
        if(dest[l]<dest[r]){
            temp[++count]=dest[l++];
        }else{
            temp[++count]=dest[r++];
        }
    }
    while(l<=mid)
        temp[++count]=dest[l++];
    while(r<=qr)
        temp[++count]=dest[r++];
    for(int k=1;k<=count;k++)
        dest[k-1+ql]=temp[k];
    
    free(temp);
}

int main(void)
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        if( prime(i) )
        for(int j=i;j<=n;j++){
            if( prime(j) ){
                halfPrime[++cnt]=i*j;
            }
        }
    }
    mergesort(1,cnt,halfPrime);
    for(int i=1;i<=n;i++){
        if( prime(i) ){//for素数
            for(int j=1;j<=cnt;j++){//for半素数
                if( palindrome(i*i+halfPrime[j]*halfPrime[j]) && halfPrime[j]>=i ){
                    printf("%4d%4d%6d\n",i,halfPrime[j],i*i+halfPrime[j]*halfPrime[j] );
                }
            }
        }
    }
    
    return 0;
}