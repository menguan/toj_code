#include<iostream>
using namespace std;
int main()
{
    int a[16];
    for(int i=0;i<16;i++)
    {
        a[i]=0;
    }
    int k=0;
    
    kk:while(cin>>a[k])
    {
        if(a[k]==-1)
        return 0;
        if(a[k]==0)
        break;
        k++;
    }
    
    int count=0;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(a[j]==2*a[i])
            count++;
        }
    }
    cout<<count<<endl;
    count=0;
    k=0;
    goto kk;
    
}