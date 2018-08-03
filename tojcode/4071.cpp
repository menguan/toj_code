#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
int n;int a[100010],b[100010],c[100010];
struct f
{ 
       int x,y;
}ans[100010];
bool cmp(f mm,f nn)
{
     if(mm.x!=nn.x)
     return mm.x<nn.x;
     else
     return mm.y<nn.y;
}

int main()
{
      int t;
      cin>>t;
      while(t--)
      {
        memset(ans,0,sizeof(ans));
        
        
        cin>>n;
        for(int i=0;i<n;i++)
        {
                cin>>ans[i].x>>ans[i].y;
        }
        sort(ans,ans+n,cmp);
      //for(int i=0;i<n;i++)
        // cout<<ans[i].x<<" "<<ans[i].y<<endl;
          
        for(int i=0;i<n;i++)
        {
                a[i]=ans[i].y;
                }        
        int st[100010];
        st[0]=-1;int top=0;
        for(int i=0;i<n;i++)
        {
           if(a[i]>=st[top])
           {
               st[++top]=a[i];
           }
           else
           {
               int low=1,high=top;
               int mid;
               while(low<=high)
               {
                  mid=(low+high)/2;
                  if(a[i]>=st[mid])
                    low=mid+1;
                  else
                    high=mid-1;
               }
               st[low]=a[i];
            }
        }
        cout<<top<<endl;
        }
}  
        
                                            
                             
                
        
        
      
        
                     
                  
                  
      
