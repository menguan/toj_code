#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       char c;
       int s,e,a[1010],max=-1,min=2000000;
       memset(a,0,sizeof(a));
       while(n--)
       {
          cin>>c>>s>>e;
          for(int i=s;i<e;i++)
            a[i]++;
          if(e>max) max=e;
          if(s<min) min=s;
       }
       for(int i=min;i<=max;i++)
          if(a[i])
            cout<<(char)(a[i]+'A'-1);
       cout<<endl;
    }
    return 0;
}