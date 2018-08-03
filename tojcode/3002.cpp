#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int a[200];
    int n;
    while(cin>>n,n)
    {
        for(int i=0;i<n;i++)
          cin>>a[i];
        sort(a,a+n);
        int ans=0;
        for(int i=0,j=1;j<=n/2+1;i++,j++)
        {
              ans+=(a[i]/2+1);
        }
        cout<<ans<<endl;
    }
}
                       
    
