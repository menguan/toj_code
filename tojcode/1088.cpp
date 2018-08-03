#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct f
{
       int x;int y;int num;
}a[3000];
bool cmp(f mm,f nn)
{
     return mm.num>nn.num;
}
int r,c;int n=0;int step[3000];int sum[3000];
int main()
{
    int t;int tim;
    cin>>t;int temp;
    while(t--)
    {
        cin>>r>>c>>tim; n=0;
        for(int i=0;i<r;i++)
        {
          for(int j=0;j<c;j++)
          {
               cin>>temp;
               if(temp)
               {
                   a[n].x=i;
                   a[n].y=j;
                   a[n].num=temp;
                   n++;
               }
          }
        }
        sort(a,a+n,cmp);sum[0]=a[0].num;
        for(int i=1;i<n;i++)
        {
               sum[i]=sum[i-1]+a[i].num;
        }        
        step[0]=2*(a[0].x+1)+1;
        for(int i=1;i<n;i++)
        {
          step[i]=1+step[i-1]-a[i-1].x-1+abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y)+a[i].x+1;
          //cout<<step[i]<<endl;
        }
        for(int i=n-1;i>=0;i--)
        {
           
           if(tim>=step[i])
           {
           
              cout<< sum[i]<<endl;break;
           }
           if(tim<step[i]&&i==0)
             cout<<0<<endl;
        }
    }
}                   
                               
                       
                
                          
                                          
                  
                     
