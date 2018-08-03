#include <iostream>    
#include <string>    
using namespace std;    
int main()
{    
    int a;    
    string s;       
    while(cin>>a,a)
    {   
            
            
        cin>>s; 
        int dsum=0,sum=0;    
        for (int i=0;i<s.length();i++)
        {    
            dsum+=s[i]-'0';    
            sum=sum*a+s[i]-'0';
             
        }    
        if(sum%dsum==0)
          cout<<"yes"<<endl;
          
        else 
          cout<<"no"<<endl;
    }    
      
    return 0;    
}   