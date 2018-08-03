#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {   
        int b;        
        cin>>b;
        cout<<b*b-(b-1)<<" "<<b*b+(b-1)<<endl;
    }
    return 0;
}