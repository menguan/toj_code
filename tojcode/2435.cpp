#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1110],z[1110],f[1111];
int ans[1110];
int main()
{
    int n,k;
    int n1,n2;
    while(cin>>n>>k)
    {
          n1=n2=0;
          for(int i=0;i<n;i++)
          {
              cin>>a[i];
              if(a[i]>=0)
                z[n1++]=a[i];
              else
                f[n2++]=a[i];
          }
          sort(z,z+n1);
          sort(f,f+n2);
          int cnt=0; 
          if(k%2==1)
          {
             k--;
             if(n1>0)
               ans[cnt++]=z[--n1];
             else
             {
                 for(int i=n2-1;i>=n2-k;i--)
                 {
                    cout<<f[i]<<" ";
                 }
                 cout<<f[n2-k-1]<<endl;
                 continue;
             }
          }
          int n3=0;
          for(int i=0;i<k/2;i++)
          {
              int t1=-1010101010;
              int t2=-1010101010;
              if(n1==1&&n2-n3==1)
              {
                 ans[cnt++]=z[--n1];
                 ans[cnt++]=f[++n3];
              }                    
              else
              {
                 if(n1>1)
                   t1=z[n1-1]*z[n1-2];
                 if(n2-n3>1)
                   t2=f[n3]*f[n3+1];
                 if(t1>t2)
                 {
                    ans[cnt++]=z[--n1];
                    ans[cnt++]=z[--n1];
                 }
                 else
                 {
                    ans[cnt++]=f[n3++];
                    ans[cnt++]=f[n3++];
                 }
              }
          }
          sort(ans,ans+cnt);
          for(int i=cnt-1;i>0;i--)
            cout<<ans[i]<<" ";
          cout<<ans[0]<<endl;
    }
}  
                            
                            
                          
               
                                
               
                    
