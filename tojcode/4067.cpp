#include<cstdio>
#include<algorithm>
//#include<iostream>
using namespace std;
struct f 
{
	int m,c;
}a[1010];
bool cmp(f mm,f nn)
{
     return mm.c>nn.c;
}
int dp[1010];
int main() 
{
    int cas=1;int n,s;
	while(scanf("%d%d",&n,&s)!=EOF) 
    {
		int sum=0;
		for (int i=0;i<n;i++) 
        {
			scanf("%d%d",&a[i].m,&a[i].c);
			sum+=a[i].c;
		}
		printf("Case #%d: ",cas++);
		sort(a,a+n,cmp);
		for(int i=0;i<1010;i++)
		  dp[i]=-1000000;
        double ans=-1; dp[0]=0;
		for (int i=0;i<n;i++)
			for (int j=s-1;j>=0;j--) 
            {
				//cout<<dp[j]<<endl;
                if(dp[j]>=0){
                dp[j+a[i].c]=max(dp[j+a[i].c],dp[j]+a[i].m*a[i].c);
                //cout<<dp[j+a[i].c]<<" "<<dp[j]+a[i]*a[i].m;
				if (j+a[i].c>=s)
				{   //cout<<dp[j+a[i].c]<<" "<<j+a[i].c<<endl;
					ans=max(ans,dp[j+a[i].c]*1.0/(j+a[i].c));}
            }
            }
         if(ans==-1)
           puts("-1");
         else     
		   printf("%.6lf\n",ans);
	}
}

