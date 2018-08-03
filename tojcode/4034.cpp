#include<iostream>
#include<cstring>
#define maxt 11000
using namespace std;
int fb[maxt];
char a[maxt];
void f()
{
   fb[0]=1;
   fb[1]=1;
   for(int i=2;i<maxt;i++)
   {
      fb[i]=(fb[i-1]+fb[i-2])%10007;
}
}           
int main()
{
  
  f();
  int n,count=1;
  cin>>n;
  while(n--)
  {
     cin>>a;
     long long re=1,c=0;
     int len=strlen(a);
     for(int i=0;i<len-1;i++)
     {
        if(a[i]=='h'&&a[i+1]=='e')
        {
              c++;
              i++;
        }
        else
        {
              
              re=(re*fb[c])%10007;
              c=0;
        }
     }
     re=(re*fb[c])%10007;
     cout<<"Case "<<count++<<": "<<re<<endl;
  }
}   