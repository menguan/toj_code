#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=1000010;
const int mod=1000000007;
int n;
long long f[N],t[N],a[N];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
       cin>>n;
       for(int i=0;i<n;i++)
         cin>>a[i];
       long long tot,rep=0;  
       sort(a,a+n);
       f[0]=a[0];t[n-1]=a[n-1];t[n]=1;
       for(int i=1;i<n;i++)
       {
          f[i]=(f[i-1]*a[i])%mod;
       }
       for(int i=n-2;i>=0;i--)
       {
          t[i]=(t[i+1]*a[i])%mod;
       }
       tot=1;
       for(int i=0;i<n;i++)
       {
          tot=(tot*a[i])%mod;
       }
       for(int i=n-1;i>n/2;i--)
       {
           rep=(rep+2*f[i-1]*t[i+1])%mod;
       }
       if(n%2==0)  rep=(rep+f[n/2-1]*t[n/2+1])%mod;
       cout<<((tot*n-rep)%mod+mod)%mod<<endl;
    }
}         
                          
    
