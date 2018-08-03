#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct f
{
       int a,b;
}t[40];
bool cmp(f mm,f nn)
{
     if(mm.a==nn.a)
       return mm.b<nn.b;
     return mm.a<nn.a;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>t[i].a>>t[i].b;
    sort(t+1,t+n+1,cmp);
    int st[40];
    int top=0;
    st[0]=-1;
    for(int i=1;i<=n;i++)
    {
       if(t[i].b>st[top])
         st[++top]=t[i].b;
       else
       {
          int low=1;int high=top;
          int mid;
          while(low<=high)
          {
              mid=(low+high)/2;
              if(t[i].b>st[mid])
                low=mid+1;
              else
                high=mid-1;
          }
          st[low]=t[i].b;
       }
    }
    cout<<top<<endl;
    //while(1);
}                             
      
