#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int n;
int num[30][30];
int f[30];int d[30];
int t[30];
int ff[30];
int h;
int main()
{int fir=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(!n) return 0;
        if(fir) puts("");//cout<<endl;
        scanf("%d",&h);//cin>>h;
        for(int i=1;i<=n;i++)scanf("%d",&f[i]);//cin>>f[i];
        for(int i=1;i<=n;i++)scanf("%d",&d[i]);//cin>>d[i];
        for(int i=2;i<=n;i++)scanf("%d",&t[i]);//cin>>t[i];
        t[1]=0;
        memset(num,0,sizeof(num));
        h=h*12;
        for(int i=1;i<=n;i++)
        {
            memcpy(ff,f,sizeof(ff));
            h-=t[i];
            int tim=h;
            int gg=0;
            while(tim>0&&gg!=i)
            {
                //cout<<tim<<" "<<"kk"<<endl;
                int now=1;
                for(int j=2;j<=i;j++)
                {
                    if(ff[j]>ff[now])
                        now=j;
                }
                if(ff[now]>0)
                {
                    num[i][0]+=ff[now];
                    ff[now]-=d[now];
                    if(ff[now]<=0) { ff[now]=0;gg--;}
                }
                tim--;
                num[i][now]++;
            }
            num[i][1]+=tim;
        }
        int now=1;
        for(int i=1;i<=n;i++)
        {
            if(num[now][0]<num[i][0])
                now=i;
        }
        for(int i=1;i<=n;i++)
        {
            if(i!=1)printf(", ");//cout<<", ";
            printf("%d",num[now][i]*5);//cout<<num[now][i]*5;
        }
        puts("");
        printf("Number of fish expected: %d\n",num[now][0]);
         fir=1;

    }
}
