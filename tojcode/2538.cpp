#include<iostream>
using namespace std;
int f(int a)
{
    int t=((1+a+1)*(a+1))/2;
    return a*t;
}    
int main()
{
    int a;
    cin>>a;
    int count=1;
    while(a--)
    {
        int b;
        cin>>b;
        long long c=0;
        for(int i=1;i<=b;i++)
        {
            c+=f(i);
            
        }    
        cout<<count<<" "<<b<<" "<<c<<endl;
        count++;
    }
    return 0;
} 