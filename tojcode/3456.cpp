#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    int b[a];
    for(int i=0;i<a;i++)
    {
        cin>>b[i];
    }
    int k=1;
    for(int i=1;i<a;i++)
    {
        if(b[i]>b[0])
        k++;
    }
    cout<<k<<endl;
    
    return 0;
}