#include<stdio.h>
#include<algorithm>
using namespace std;
const double inf=1e300;
int cas;
char str[110];
int x[1010],y[1010];
int n;
int xx,yy,m,cnt,ans;
double k[1010];
int main()
{
    cas=1;
    while(1)
    {
        n=0;
        while(1)
        {
            gets(str);
            if(str[1]=='-')break;
            sscanf(str,"%d%d",&x[n],&y[n]);n++;
        }
        if(n==0) break;
        if(n==1) ans=1;
        else ans=2;
        for(int i=0;i<n;i++)
        {
            m=0;cnt=1;
            for(int j=i+1;j<n;j++)
            {
                xx=(x[j]-x[i]);
                yy=(y[j]-y[i]);
                if(xx==0)k[m++]=inf;
                else k[m++]=(double)yy/xx;
            }
            sort(k,k+m);
            for(int j=1;j<m;j++)
            {
                if(k[j]==k[j-1])cnt++;
                else
                {
                    if(cnt+1>ans) ans=cnt+1;
                    cnt=1;
                }
            }if(cnt+1>ans) ans=cnt+1;
        }
        printf("%d. %d\n",cas++,ans);
    }


}
