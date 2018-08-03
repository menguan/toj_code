#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[100];
char b[100];
int main()
{
  int n;
  cin>>n;
  if(n==0)
  return 0; 
  while(n--)
  {
    cin>>a>>b;
    int aa=strlen(a);
    int bb=strlen(b);
    if(aa!=bb)
    {
      cout<<"No"<<endl;
      continue;
    }
    
    for(int i=0;i<aa;i++)
    {
      a[i]=tolower(a[i]);
      b[i]=tolower(b[i]);
    }
    sort(a,a+aa);
    sort(b,b+aa);
      
    
    if(memcmp(a,b,aa)==0)
     cout<<"Yes"<<endl;
    else
     cout<<"No"<<endl;
   }
}   