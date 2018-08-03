#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int aa[6000];
    int bb[6000];
    int ac=0,bc=0;
    for(int i=1;i<=a;i++)
    {
        if(a%i==0)
        {
            aa[ac]=i;
            ac++;
        }
    }        
    for(int i=1;i<=b;i++)
    {
        if(b%i==0)
        {
            bb[bc]=i;
            bc++;
        }
    }         
    for(int i=0;i<ac;i++)
    {
        for(int j=0;j<bc;j++)
        {
            cout<<aa[i]<<" "<<bb[j]<<endl;
        }
    }
    
    
    return 0;        
}  