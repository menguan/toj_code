#include<iostream>
using namespace std;
int main()
{
    int a;
    int b;
    while(cin>>a)
    {
        b=1;
        int i=1;
        while(1)
        {
            b=b*10+1;
            i++;
            b%=a;
            if(b==0)
            break;
        }
        cout<<i<<endl;
    }
    return 0;
} 