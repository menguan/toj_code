#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int k,e,n;
struct feed
{
   int c,f;
}a[1000100];
bool cmp(feed mm,feed nn)
{
     return mm.c<nn.c;
}
int main()
{
    while(cin>>k>>e>>n)
    {
        long long temp,ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            cin>>a[i].f>>a[i].c;
            a[i].c+=(e-temp);
        }                
        sort(a,a+n,cmp);
        long long now=0;
        int i;
        for(i=0;i<n;i++)
        {
             if(now+a[i].f<=k)
             {
                now+=a[i].f;
                ans+=a[i].f*a[i].c;
             }
             else break;
        }
        ans+=a[i].c*(k-now);
        cout<<ans<<endl;
    }
}                    
       
