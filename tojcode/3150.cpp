#include<iostream>
using namespace std;
int main()
{
    int a;
    int count=1;
    cin>>a;
    while(a--)
    {
        int m,n;
        cin>>m>>n;
        
        int i=1,j=1;
        while(1)
        {
        if(i%m==0&&i%n==0)
        break;
        i++;
        }
        for(j=(m>n?m:n);j>0;j--)
        {
            if(m%j==0&&n%j==0)
            break;
        }
        cout<<count<<" "<<i<<" "<<j<<endl;
        count++;
            
    }
    return 0;
}    