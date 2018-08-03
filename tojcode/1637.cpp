#include<iostream>
using namespace std;
int dec(int a)
{
    int sum=0;
    sum+=a/1000;
    a-=(a/1000)*1000;
    sum+=a/100;
    a-=(a/100)*100;
    sum+=a/10;
    a-=(a/10)*10;
    sum+=a;
    return sum;
}    
int duo(int a)
{
    int sum=0;
    sum+=a/1728;
    a-=(a/1728)*1728;
    sum+=a/144;
    a-=(a/144)*144;
    sum+=a/12;
    a-=(a/12)*12;
    sum+=a;
    return sum;
}
int hex(int a)
{
    int sum=0;
    sum+=a/4096;
    a-=(a/4096)*4096;
    sum+=a/256;
    a-=(a/256)*256;
    sum+=a/16;
    a-=(a/16)*16;
    sum+=a;
    return sum;
}     
int main()
{
    
    for(int i=2992;i<10000;i++)
    {
        if(duo(i)==hex(i)&&hex(i)==dec(i))
        cout<<i<<endl;
    }
    
    return 0;
} 