#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<stdarg.h>

#define N 1000
int matrix[N][N]={0};
int n;

void left(int line)
{
    int temp=matrix[line][1];
    for(int j=1;j<n;j++){
        matrix[line][j]=matrix[line][j+1];
    }
    matrix[line][n]=temp;
}

void right(int line)
{
    int temp=matrix[line][n];
    for(int j=n;j>1;j--){
        matrix[line][j]=matrix[line][j-1];
    }
    matrix[line][1]=temp;
}

void up(int column)
{
    int temp=matrix[1][column];
    for(int j=1;j<n;j++){
        matrix[j][column]=matrix[j+1][column];
    }
    matrix[n][column]=temp;
}

void down(int column)
{
    int temp=matrix[n][column];
    for(int j=n;j>1;j--){
        matrix[j][column]=matrix[j-1][column];
    }
    matrix[1][column]=temp;
}

int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%d",matrix[i]+j);
        }
    int m,k; 
    while( ~scanf("%d %d",&m,&k) && m && k){
        if(m>0 && k>0){//左移
            k%=n;
            while(k--)
                left(m);
        }else if(m<0 && k>0){//列上移
            k%=n;
            m=-m;
            while(k--)
                up(m);
        }else if(m>0 && k<0){//有意
            k=-k;
            k%=n;
            while(k--)
                right(m);
        }else(m<0 && k<0){
            k=-k;//下移
            m=-m;
            k%=n;
            while(k--)
                down(m);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%4d",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}