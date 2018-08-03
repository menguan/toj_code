#include<iostream>
using namespace std;
bool a[100];
bool b[100];
int main()
{
  int t,n,m;
  /*cout<<1000000%21<<endl;
  int ss=7;
  for(int i=2;i<100;i++)
  {
    ss*=7;
    ss%=100;
    cout<<ss<<endl;
  } //*/ 
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    int ans=0;
    for(int j=1;j<=n;j++)
    {
      int h=j%100;
      //cout<<h<<endl;
      int temp=1;
      for(int i=0;i<100;i++)
        a[i]=b[i]=0;
        
        
      int c=1;
      int ddd=0;
      int flag=1;
      while(c<=m)
      {
        temp=(temp*h)%100;
        //cout<<temp<<endl;
        if(b[temp])
        {
          
          int g=c-ddd;//cout<<ddd<<" "<<g<<endl;
          c=c+g*((m-c)/g);
        }  
        else if(a[temp])
         { 
           //cout<<temp<<"kkkk"<<c<<endl;
           if(flag)
           {ddd=c;flag=0;}
           b[temp]=1;
         }
        else 
          
        a[temp]=1;
        
        
        c++;
      }  
        
        
      //cout<<temp<<" jj"<<endl;
      ans+=temp;
      ans%=100;
      
    }
    if(ans<10)
    cout<<"0";
    cout<<ans<<endl;
  }
}    
    