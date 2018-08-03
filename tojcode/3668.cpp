#include <iostream>
using namespace std;
int a[100010];
int b[100005];
int main()
{
     long long s1,s2,ans;
     int n,m,i,j=0;
     cin>>n;
     for(j=1;j<=n;j++)
     {
        ans=0,s1=0,s2=0;
        cin>>m;
        for(i=1;i<=m;i++)
        {
            cin>>a[i]>>b[i];
            s1+=a[i];
            s2+=b[i];
        }
        for(i=1;i<m;i++)
        {
            s1-=a[i];
            s2-=b[i];
            ans+=a[i]*s2+b[i]*s1;
        }
        cout<<"Case "<<j<<": ";
        cout<<ans<<endl;
    }
}
