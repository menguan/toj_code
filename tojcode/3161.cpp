#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int a[m+1];
    for(int i=1;i<m+1;i++)
    {
            cin>>a[i];
    }
    int s,e;
    while(n--)
    {
            int sum=0;
            cin>>s>>e;
            for(int i=s;i<=e;i++)
              sum+=a[i];
              
           cout<<sum<<endl;
}
       

}    
