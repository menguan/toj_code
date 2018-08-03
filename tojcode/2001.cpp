#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,m,count,i=1;
    string s;
    cin>>n;
    int jj=n;
    while(n--)
    {   
        count=0;
        cin>>m;
        while(m--)
        {
          cin>>s;
          if(s=="sheep")
          count++;
        }
        if(i==jj)
        cout<<"Case "<<i<<": This list contains "<<count<<" sheep.\n"; 
        else
        cout<<"Case "<<i<<": This list contains "<<count<<" sheep.\n\n";
        i++;
     }
     
     return 0;
}    