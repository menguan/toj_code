#include<iostream>
using namespace std;
long long f91(long long N)
{
    if(N<=100)
    return f91(f91(N+11));
    else if(N>100)
    return (N-10);
}
int main()
{
    long long a;
    while(cin>>a&&a!=0)
    {
      cout<<"f91("<<a<<") = "<<f91(a)<<endl;  
    }
    
    return 0;
}