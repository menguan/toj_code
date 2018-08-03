#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
      
      if(s1==s2)
        cout<<"No"<<endl;
      else
        cout<<"Yes"<<endl;
    }
    return 0;
}    