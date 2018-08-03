#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long f(char c,int n)
{
     int num=c-'A'+1;
     long long ret=1;
     for(int i=0;i<n;i++)
       ret=ret*num;
     return ret;  
}
char a[100];
int main()
{
    long long num;long long temp;
    while(cin>>num>>a)
    {
              bool flag=1;
              if(num==0&&strcmp(a,"END")==0)
                break;
                
              int len=strlen(a);
              sort(a,a+len);
              for(int i=len-1;i>=0&&flag;i--)
              for(int j=len-1;j>=0&&flag;j--)
              for(int k=len-1;k>=0&&flag;k--)
              for(int l=len-1;l>=0&&flag;l--)
              for(int m=len-1;m>=0&&flag;m--)
              {
                  if(i==j||i==k||i==l||i==m||j==k||j==l||j==m||k==l||k==m||l==m)
                    continue;
                  temp=f(a[i],1)-f(a[j],2)+f(a[k],3)-f(a[l],4)+f(a[m],5);
                  /*if(i==11&&j==10&&k==4&&l==1&&m==0)  
                  {
                  cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<" "<<temp<<endl;
                  cout<<a<<endl;
                  system("pause");}*/
                  if(temp==num)
                  {
                      cout<<a[i]<<a[j]<<a[k]<<a[l]<<a[m]<<endl;
                      flag=0;
                      break;
                  }
              }
              if(flag)
                cout<<"no solution"<<endl;
              
    }
}                                                      
    
       

