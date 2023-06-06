#include<stdio.h>
#include<math.h>

int main(void)
{
    double eps;
    scanf("%lf",&eps);
    double item=1,sum=0,factor=1;
    for(int i=2; item-eps >= 0 ;i++){
        sum+=item;
        factor*=i;
        item=factor/pow(2*i-1,i);
    }
    printf("%.5f",sum);
    
    return 0;
}