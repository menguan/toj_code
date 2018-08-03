#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n, k, a[55];
inline bool jud(int low,int high)
{
    int res=0;
    for(int i=0;i<n;i++) 
	{
        if (a[i]<low)
            res+=a[i];
        else if(a[i]>high)
            res+=a[i]-high;
    }
    return res<=k;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) 
	{
        scanf("%d%d",&n,&k);
        int minn=1010,maxn=-1;
        for (int i=0;i<n;i++) 
		{
            scanf("%d",&a[i]);
            minn=min(a[i],minn);
            maxn=max(a[i],maxn);
        }
        int ans=maxn-minn;
        for (int i=minn;i<=maxn;i++)
            for (int j=i;j<=maxn;j++) 
			{
                    if(jud(i,j))
                    {
                    //  cout<<i<<" "<<j<<endl;          
                      ans=min(ans,j-i);
                    }  
            }
        printf("%d\n",ans);
    }
}
