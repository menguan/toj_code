#include<iostream>
#include<cstring>
using namespace std;
int num[101010];
int main()
{
    int x,y,n;
    while(cin>>x>>y&&(x+y))
    {
      memset(num,0,sizeof(num));
      cin>>num[0]>>num[1]>>n;
      int huan;bool ishuan=0;int st,en;
      for(int i=2;i<=n;i++)
      {
          if(ishuan)
            break;
          num[i]=(x*num[i-1]+y*num[i-2])%100;
          for(int j=1;j<i;j++)
          {
               if(num[i]==num[j]&&num[i-1]==num[j-1])
               {         
                  huan=i-j;
                  st=j-1,en=i-1;
                  ishuan=1;
                  break;
               }
          }
      }
      int ans;
      //for(int i=0;i<n;i++)
      //  cout<<num[i]<<endl;
      if(!ishuan)
      {ans=num[n];}
      else ans=num[st+(n-en)%huan];
      if(ans<10)
        cout<<"0"<<ans<<endl;
      else
        cout<<ans<<endl;
    }
}  
               
