#include<iostream>
using namespace std;
long long f1(long long a)
{
    long long i=0;
    long long sum=0;
    while(1)
    {
        i++;
        sum+=i;
        if(sum>=a)
        break; 
    }
    if(i%2==1)
    {
        return sum-a+1;
    }
    else
    return i-(sum-a);
            
}    
long long f2(long long a)
{
    long long i=0;
    long long sum=0;
    while(1)
    {
        i++;
        sum+=i;
        if(sum>=a)
        break; 
    }
    if(i%2==0)
    {
        return sum-a+1;
    }
    else
    return i-(sum-a);
            
} 




int main()
{   
    int a;
    while(cin>>a)
    {
        cout<<"TERM "<<a<<" IS "<<f1(a)<<"/"<<f2(a)<<endl;
    }
    return 0;
}