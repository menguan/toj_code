#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        int b,c;
        cin>>b>>c;
        if(c>b||(b+c)%2!=0)
        cout<<"impossible"<<endl;
        else
        cout<<(b+c)/2<<" "<<(b-c)/2<<endl;
    }
    return 0;
}