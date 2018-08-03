#include<iostream>
#include<cstring>
 
using namespace std;
int main()
{
    int i=1;
    int n;
    while(cin>>n,n)
    {
        char kk[n][30]; 
        for(int i=0;i<n;i++)
            cin>>kk[i];
        cout<<"SET "<<i<<endl;
        i++;
        if(n%2==0)
        {
          for(int i=0;i<n;i+=2)
            cout<<kk[i]<<endl;
          for(int j=n-1;j>0;j-=2)
            cout<<kk[j]<<endl;
        }
        else if(n%2==1)
        {
          for(int i=0;i<n;i+=2)
            cout<<kk[i]<<endl;
          for(int j=n-2;j>0;j-=2)
            cout<<kk[j]<<endl;    
        }           
        
    }
    return 0;
}  