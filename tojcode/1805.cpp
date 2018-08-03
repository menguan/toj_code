#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        int b,c,sum=0;
        cin>>b;
        
        for(int i=1;i<=b;i++)
        {
            cin>>c;
            sum+=c;
        }
        
        sum=sum-b+1;
        
        cout<<sum<<endl;
    }
    return 0;
}  