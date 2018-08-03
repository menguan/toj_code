#include<iostream>
#include<string>
using namespace std;
int main()
{
    
    int low=0,high=11;
    int a;
    string s1,s2;
    while(cin>>a,a)
    {
        cin>>s1>>s2;
        if(s1=="too"&&s2=="high"&&a<high)
        {
            high=a;
        }
        else if(s1=="too"&&s2=="low"&&a>low)
        {
            low=a;
        }
        else if(s1=="right"&&s2=="on")
        {
            if(a<high&&a>low)
              cout<<"Stan may be honest"<<endl;
            else
              cout<<"Stan is dishonest"<<endl;
            low=0;
            high=11;
            
        }
    }
    return 0;
} 