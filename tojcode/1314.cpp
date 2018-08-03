#include<iostream>
#include<algorithm>
using namespace std;
struct dice
{
  int a[6];//对面0,5  1,3  2,4
}d[10010];
int main()
{
  int t,n;
  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<6;j++)
      {
        cin>>d[i].a[j];
      }
    }
    int sum[6]={0,0,0,0,0,0};
    for(int k=0;k<6;k++)
    { 
      int count=0;
      int now=d[count].a[k];
      int i=k;
      while(1)
      {
        if(i==0||i==5)
        sum[k]+=max(d[count].a[1],max(d[count].a[2],max(d[count].a[3],d[count].a[4])));
        else  if(i==1||i==3)
        sum[k]+=max(d[count].a[0],max(d[count].a[2],max(d[count].a[5],d[count].a[4])));
        else
        sum[k]+=max(d[count].a[0],max(d[count].a[1],max(d[count].a[5],d[count].a[3])));
        count++;
        if(count==n)
          break; 
        for(int j=0;j<6;j++)
        {
          if(d[count].a[j]==now)
          {
            switch(j)
            {
              case 1: i=3;break;
              case 2: i=4;break;
              case 3: i=1;break;
              case 4: i=2;break;
              case 5: i=0;break;
              case 0: i=5;break;
            }
            now=d[count].a[i];
            break;
          }
        }
      }
    } 
    int maxn=0;
    for(int i=0;i<6;i++)
    {
      if(sum[i]>maxn)
        maxn=sum[i];
    } 
    cout<<maxn<<endl;            
  }
} 