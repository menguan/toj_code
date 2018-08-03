#include<iostream>
using namespace std;
int main()
{
    int n,m;
    int count=1;
    while(cin>>n>>m,(m!=0||n!=0))    
    {
        int c=0;
        for(int b=1;b<n;b++)
        {
            for(int a=1;a<b;a++)
            {
                if((a*a+b*b+m)%(a*b)==0)
                c++;
            }
        }
        cout<<"Case "<<count<<": "<<c<<endl;
        count++;
    }
    return 0;
}