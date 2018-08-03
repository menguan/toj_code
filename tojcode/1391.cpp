#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    char word[a][50];
    int k[a];
    for(int i=0;i<a;i++)
    {
        cin>>word[i]>>k[i];
    }
    
    string s;
    int count=0;
    long long sum=0;
    while(cin>>s)
    {
        if(s==".")
        {
            cout<<sum<<endl;
            sum=0;
            count++;
            if(count==b)
              return 0;
            else
              continue;
        }
        
        for(int i=0;i<a;i++)
        {
            if(s==word[i])
              sum+=k[i];
              
        }
    }
    
    return 0;
}                          
   