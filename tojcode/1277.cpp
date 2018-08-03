#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    long long a[50];
    a[0]=1;
    for(int i=1;i<32;i++)
    a[i]=2*a[i-1]+1;
    //cout<<a[30]<<endl;
    int t;
    cin>>t;
    while(t--)
    {
             int n;
             cin>>n;
             if(n==0)
             {
                  cout<<"0 []"<<endl;
                  continue;
             }
             cout<<n<<" [";
             int cnt=0;
             int now=30;
             int ans[1000];
             while(n)
             {//cout<<n<<" "<<a[now]<<endl;
                 while(n>=a[now])
                 {
                       
                       n-=a[now];             
                       ans[cnt++]=now;
                 }
                 now--;
             }
             sort(ans,ans+cnt);
             cout<<ans[0];
             for(int i=1;i<cnt;i++)
               cout<<","<<ans[i];
             cout<<"]\n";
    }
}  
