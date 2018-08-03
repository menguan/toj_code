#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    int n,m;
    while(cin>>n)
    {
       m=1;
       for(int i=1;i<=n;i++)
       {
        m*=i;
        while(m%10==0)
         m/=10;
        m=m%100000;
       }
        cout<<setw(5)<<n<<" -> "<<m%10<<endl;
    }
    return 0;
}