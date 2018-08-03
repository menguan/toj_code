#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        long double m,n;
        cin>>m>>n;
        if(m>n||((m-n)>=0&&(m-n)<1)||((n-m)>=0&&(n-m)<1))
        {
            cout<<"MMM BRAINS"<<endl;
        }
        else
            cout<<"NO BRAINS"<<endl;
    }
    
    return 0;
} 