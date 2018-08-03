#include<iostream>
using namespace std;
int main()
{
    int a;
    while(cin>>a)
    {
        int b;
        int sum=0;
        for(int i=0;i<a;i++)
        {
            cin>>b;
            sum+=b;
            
        }
        int ave=sum/a;
        cout<<ave<<endl;
    }
    return 0;
}        
   