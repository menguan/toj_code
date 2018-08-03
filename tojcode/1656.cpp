#include<iostream>
#include<cstring>
using namespace std;
char a[100];
int main()
{
    while(cin>>a)
    {
        if(a[0]=='0'&&a[1]=='0'&&a[3]=='0')
          return 0;
        int temp=(a[0]-'0')*10+a[1]-'0';
        for(int i=0;i<a[3]-'0';i++)
          temp*=10;
        int t=1;
        while(temp>t)
        {
          temp-=t;
          t*=2;
        }
        cout<<2*temp-1<<endl;
    }
}           
        
                 
    
