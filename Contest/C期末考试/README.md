# C语言期末考试
前言:acm搞了有四个多月了

### [A]()
考点:套公式...
#### 题目大意
给出r,h;输出圆锥体积和面积;
#### 解题思路
签到题目,掠过

### [B]()
考点:定精度求和
#### 题目大意
有 $$A_n=\frac{n!}{ (2n-1)^{n} }$$
累加$A_n$,直到 $A_n$小于给定精度eps;
#### 解题思路
容易出错的地方一个是精度,一个是累加的次序;

```cpp
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
```

但也没什么好说的;

### [C]()
考点:统计
#### 题目大意
统计好学生,给数据输出true false之类的(不记得)
#### 解题思路
首先迟到不能超过三次,总旷课不能超过两次;也就是说,有L才记录,一旦没有L清零;但是旷课以及就是永久记录; 

```cpp
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
```

### [D]()
考点: 函数书写,素数判断,回文数,打表...
#### 题目大意
给定一个n,找出这样两个数:
1. 一个是素数,一个是半素数,其平方和还是一个回文数,算术和不超过n;
2. 先按素数大小排列,然后按半素数排列;注意:半素数不小于素数;
3. 输出素数半素数占4格右对齐,平方和占六格;要求写判断素数和回文数的函数(返回int,true为1,false为0)

半素数的定义:有且仅有两个素数的乘积组成;

#### 解题思路
首先半素数不好处理,假设有了一个方法拿到了数,那么按照常理接下来就应该枚举素数和半素数去满足`半素数不小于素数`和`其平方和还是一个回文数`;
考试的时候,我对回文数十分的敏感,马上想到了回文字符串的判断;在判断会问字符串的时候,经典的做法就是左右指针进行遍历,两个指针没有交会就发现不同了那就不是,否则就是;此时我们同时完成了题目要求的一个函数:

```cpp
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
```

不是要一定要转化成为字符串(其实数组就可以了);但是出于对字符串的执念,同时`itoa()`显示编译错误@_@~~(所以手写,都可以手写)~~;
写完了这个还是不知道~~自己姓什么~~接下来写什么;先查看任务:
他要我找到那两个数,一个是素数一个是半素数,这些都不是自然存在的数字,需要人为查找,储存;同时他让我生成这两个数的平方和才来判断是不是回文数;可以想象,我们要两层for枚举两个数字,然后一个`if`判断是不是回文,这样就找到了答案;
那答案是储存还是直接输出?我这里比较懒,所以直接输出;那么直接输出的需要考虑顺序的问题,因为先排素数然后再排半素数,所以我们先for素数再for半素数

```cpp
for(int i=1;i<=n;i++){
    if( prime(i) )//for素数
        for(int j=1;j;j++)//for半素数
}
```

素数我熟,但是半素数是什么东西?根据定义我们可以知道是两个素数的乘积,不能有多个,不能有合数;这个东西枚举出来再进行判断肯定会tle,就算是题目要求的1000也会;分解一个数的乘积能想到的就是`dfs()`;一个数d一次,两个数d两次....反过来,我们用素数去生成它,直接从一个箱子里面去拿现有半素数;
所以生成半素数:

```cpp
for(int i=2;i<=n;i++){
    if( prime(i) )
    for(int j=i;j<=n;j++){
        if( prime(j) ){
            halfPrime[++cnt]=i*j;
        }
    }
}
```

紧接着我们调试一看,发现数字是此起彼伏的;为了方便后面,我们进行排序;
c库的`qsort()`用不惯,于是手打一个归并(算是最熟悉也算是最好写的了);

```cpp
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
```

题目就这样做出来了:(CE了两次后一A了)

```cpp
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<stdarg.h>

#define  N 250000
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
```

这都能写了100多行,~~谁出的鸟题~~

### [E]()
考点:模拟(算法)
#### 题目大意
给定一个nxn二维矩阵;注意不定次数移动;每次给出m,k代表哪一行改移动多少;输出最后矩阵的样子;
#### 解题思路
首先,矩阵平移是做过的,这次是平移某一行某一列;向左向右肯定是行不变,向上向下肯定是列不变,那么我们可以写出这样四个平移函数;

```cpp
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
```

但是这样写好像只移动了一次,那就多调用几次这个函数;

```cpp
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
```

和上次迎新赛的"邓学长出的那道2048"很像,思路比较好找;

### [F](https://www.luogu.com.cn/problem/P2005)
考点:高精度(算法)
#### 题目大意
给出大整数a,b;模拟高精度的除法和取余运算;

#### 解题思路
题目说大整数,所以高精度;空间应该是足够的所以不写压位;思路就是模拟竖式除法的过程,具体除出来的结果是几,那就是看能减多少次;
考试后完成的,而且还错了好多次;主要还是不熟练;

```cpp
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
```

## 小结

这次考试写完也是心有余悸;写cpp写久了,写c的时候用的库函数瞬间都要自己撸,然后被编译器各种卡,然后又是被更老的oj版本各种卡,写的不是很顺利,写的也不是很专注;很多基础操作忘记了(double比较eps要相减,c原版本没有bool,`qsort`不会用....);
考试前也没有做什么东西,只是去把C语言学校内没有强调的内容:

- 函数
  - 参数缺省
    - 全缺,半缺
  - 变参
    - 变参宏,v系列输入输出
  - 函数指针
    - 回调函数
- 宏
  - 带参宏
  - 宏的高级替换 #和##
  - 变参宏
- 文件IO系列函数
- 库函数
  - 字符串-整数 转换
  - 快速排序,二分查找

然后复习了一下自己之前带的板子:(排序算法,二分查找等等);
结果还是给暴打了:
- 练题目练得太少了,看到题目不能很快得形成思路;有感觉但是需要长时间编码;
  - 之前看到浙大acm新生一个多月都能练习过千,自愧不如;
- 一个题目的思考没有层次,稍微材料大一点,没有头绪一点就发麻,不想写(最终还是给克服了)
  - 不完全是懒,主要是没有计划,一下子那么多任务全部要解决那肯定是压力很大,难以集中的;
- 心态有问题
  - 打acm这些都应该压着打,AK掉;但是还是没有,虽然写的比别人多,但是还是自我感觉良好;(虽然没什么人注意这次考试,我还是把它当比赛)