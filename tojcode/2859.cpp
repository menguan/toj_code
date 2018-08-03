#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a;
    while(cin>>a,a)
    {
        int k[a];
        for(int i=0;i<a;i++)
        {
            cin>>k[i];
        }
        
        sort(k,k+a);
        
        int kk=k[a-1];
        
        for(int i=a-2;i>=0;i--)
        {
            if(k[i]<kk)
            {
                cout<<k[i]<<endl;
                break;
            }
            
        }
        
     }
     
     return 0; 
} 