#include<stdio.h>
#include<stdbool.h>

char record[1100]={0};

int main(void)
{
    scanf("%s",record);
    int len=strlen(record);
    int cnt=0,sum=0;
    bool flag=1;
    for(int i=0;i<len;i++){
        switch(record[i]){
            case 'A':
                sum++;
                cnt=0;
                break;
            case 'L':
                cnt++;
                break;
            case 'P':
                cnt=0;
                break;
        }
        if(cnt>=3 || sum>=2){
            flag=0;
            break;
        }
    }

    if(flag)
        printf("true");
    else
        printf("false");

    return 0;
}