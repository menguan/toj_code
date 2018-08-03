#include<iostream>
using namespace std;
int main()
{
    int a;
    while(cin>>a,a)
    {
        int l=-1;
        char s[100];
        for(int i=0;i<100;i++)
        {
            s[i]='\0';
        }    
        for(int i=0;;i++)
        {
            s[i]=(a%2==0)?'0':'1';
            a/=2;
            l++;
            if(a==0)
            break;
        }
        
        int sum=0;
        int t=1;
        for(int i=l;i>=0;i--)
        {
            if(s[i]=='1')
            sum+=t;
                        
            t*=2;
        }
        cout<<sum<<endl;    
    }
    return 0;
} 