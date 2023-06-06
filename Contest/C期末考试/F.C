#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define N 10000000
#define min(a,b) (a>b?a:b)

char divider[N]={0},dividee[N]={0},ans[N]={0};

int compare(char* const cptr1,char* const cptr2)
{
	int len1=strlen(cptr1),len2=strlen(cptr2);
	if( len1>len2  ){
		return 1 ;
	}else if( len1<len2 ){
		return -1;
	}else{
		for(int i=len1-1;i>=0;i--){
			if( cptr1[i]>cptr2[i]  ){
				return 1 ;
            }else if( cptr1[i]<cptr2[i] ){
                return -1;
            }
        }
        return 0;
    }
}

void substract(char*const cptr1,const char* const cptr2)
{
    int len1=strlen(cptr1);
	int len2=strlen(cptr2);//检查相等性 
	int borrow=0;
	for(int i=0;i<len2;i++){
		cptr1[i]=cptr1[i]-cptr2[i]-borrow;
		if( cptr1[i]<0 ){
			borrow=-cptr1[i]/10+1;//借位是正数 
			cptr1[i]=10+cptr1[i]%10;
		}else{
			borrow=0;
		}
		cptr1[i]+='0';
	}

    for(int i=len2;i<len1 && borrow ;i++){
        cptr1[i]=cptr1[i]-borrow-'0';
        if( cptr1[i]<0 ){
            borrow=-cptr1[i]/10+1;//借位是正数 
			cptr1[i]=10+cptr1[i]%10;
        }else{
			borrow=0;
		}
        cptr1[i]+='0';
    }
}

void swap(char* const cptr1,char* const cptr2)
{
	char temp=*cptr1;
	*cptr1=*cptr2;
	*cptr2=temp;
}

void output(const char* const ptr)
{
	int len=strlen(ptr)-1;
	while(len>0 && ptr[len]=='0')
		len--;
	for(int i=len;i>=0;i--){
		putchar(ptr[i]);
	}
}

int main(void)
{
    scanf("%s %s",divider,dividee);
    int lenr=strlen(divider);
    int lene=strlen(dividee);
    if(lenr<lene){
        printf("0 %s",divider);
    }else{
    	for(int i=0;i<lenr-i-1;i++)
    		swap(divider+i,divider+lenr-i-1);
    	for(int i=0;i<lene-i-1;i++)
    		swap(dividee+i,dividee+lene-i-1);
    	
    	//转换成数字然后倒叙排放 
    	int index=lenr-1;
        for( int i=lenr-lene;i>=0;i-- ){
        	int times=0;
        	while( compare(divider+i,dividee)>=0  ){
        		substract(divider+i,dividee);
        		times++;
        		while(index>=0 &&  divider[index]=='0' )
					divider[index--]=0;//打头不能为0
			}
			ans[i]=times+'0';
        }
        
        int be=lenr-lene,ed=0;
        while( ans[be]=='0' && be>=0 )
        	be--;
        for(int i=be;i>=0;i--){
			putchar(ans[i]);
		}
		putchar(' ');
		for(int i=0;i<lenr;i++)
			divider[i]= (divider[i]?divider[i]:'0') ;
		output(divider);
    }
    return 0;
}
