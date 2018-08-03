#include<iostream>
using namespace std;
int main()
{
    int a;
    int s[91];
    int t[13];
    
    while(cin>>a,a!=-1)
    {   
        int i=1;
        int sum=0;
        while(a--)
        {
            cin>>s[i]>>t[i];
            if(i==1)
            sum+=s[i]*t[i];
            else
            sum+=s[i]*(t[i]-t[i-1]);
            i++;
        }
        cout<<sum<<" "<<"miles"<<endl;
    }
    return 0;
}  