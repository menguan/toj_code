#include<iostream>
using namespace std;
int main()
{
  int c,r;
  char t;
  char a[1000];
  while(cin>>t>>r>>t>>c)
  {
    if(r==0&&c==0)
      return 0;
    int i=0;
    while(c)
    {
       a[i]=(char)(c%26+'A'-1);
       if(a[i]==(char)('A'-1))
       {
         a[i]=(char)(26+'A'-1);
         c--;
       }
       i++;  
       c/=26;
    }
    for(int j=i-1;j>=0;j--)
      cout<<a[j];
      
    cout<<r<<endl;
  }
}       