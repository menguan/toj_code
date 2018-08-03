#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 10000000
using namespace std;
int con[110][110];
int a[110];
int main()
{
    int n;int temp;int pos;int v,w;
    while(cin>>n,n)
    {
       for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
       {
           con[i][j]=MAX;
           a[i]=0;
       }
       for(int i=1;i<=n;i++)
       {
          cin>>temp;
          while(temp--)
          {
             cin>>v>>w;
             con[i][v]=w;
          }
       }
       for(int k=1;k<=n;k++)
       for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
         con[i][j]=(i==j||j==k||i==k)?con[i][j]:min(con[i][j],con[i][k]+con[k][j]);
       int ans=MAX;
       for(int i=1;i<=n;i++)
       {
       for(int j=1;j<=n;j++)
       {
         if(i!=j&&con[i][j]>a[i])
           a[i]=con[i][j];
           }
       if(a[i]<ans)
       {
           ans=a[i];
           pos=i;
       }
       }
       if(ans==MAX)
       {
              cout<<"disjoint"<<endl;
       }
       else
         cout<<pos<<" "<<ans<<endl;
    }
}                                                    
               
                          
