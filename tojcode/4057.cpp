#include<cstdio>   
#include<cstring>   
#define MAXN 1000010   
using namespace std;  
bool I[MAXN*3];  
char str[MAXN];  
int queue[MAXN];  
int T;  
void init()  
{  
    memset(I,0,sizeof(I));  
    I[1]=1;  
    int front=0,rear=0;  
    queue[rear++]=1;  
    while(front<rear)  
    {  
        int top=queue[front]; front++;  
        if(top*2<MAXN&&I[top*2]==0) 
          {I[top*2]=1; queue[rear++]=top*2;}  
        if(top-6>0&&I[top-6]==0) 
          {I[top-6]=1; queue[rear++]=top-6;}  
    }  
}  

int main()  
{  
    init();  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%s",str);  
        bool flag=1;  
        int len=strlen(str),sum=0;//sum是I的个数  
        if(str[0]!='M') flag=0;  
        if(flag)  
        for(int i=1;i<len;++i)  
        {  
            if(str[i]!='U' && str[i]!='I') 
              {flag=0;break;}  
            if(str[i]=='U') 
              sum+=3;  
            else 
              sum++;  
        }  
        printf("%s\n",I[sum]&&flag? "Yes":"No");  
    }  
}  
