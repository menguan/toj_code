#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int sum=0;
    string s1,s2,c;
    int miles;
    while(cin>>s1)
    {
        if(s1=="#")
          return 0;
        if(s1=="0")
        {
          cout<<sum<<endl;  
          sum=0;
          continue;
        }         
        cin>>s2>>miles>>c;
        
        if(c=="F")
          sum+=(miles*2);
        if(c=="B")
        {
          double k=ceil(miles/2.0);
          sum=sum+miles+(int)k;
        }  
        if(c=="Y")
          sum=sum+((miles-1)/500+1)*500;
    }
    return 0;
}  