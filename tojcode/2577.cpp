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
        if(b<10)
        {
            cout<<b<<endl;
            continue;
        }    
        int wei=0;
        for(int i=1;;i*=10)
        {
            if(i>b)
            {
                break;
            }
            else
            wei++;
        }
        int l=1;
        for(int i=1;i<wei;i++)
        {
                l*=10;
                if(b%l<=(4*l)/10)
                  b=(b/l)*l;
                else
                b=(b/l+1)*l;
 
        }
        cout<<b<<endl;

        
        
     }
     return 0;
}         