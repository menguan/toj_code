#include <cstdio> 
#include<cstring>
#include<iostream>
using namespace std;

long c, h, v[5002]; 
bool f[50002];

int main() 
{ 
/* 
    freopen("1606.in", "r", stdin); 
    freopen("1606.out", "w", stdout); 
*/ 
    cin>>c>>h;
    for (long i = 1; i <= h; ++i) 
        cin>>v[i];
    f[0] = true; 
    for (long i = 1; i <= h; ++i) 
        for (long j = c; j >= v[i]; --j) 
        { 
            if (!f[j] && f[j - v[i]]) 
                f[j] = true; 
        } 
    //long ans = c; 
    for(int i=c;i>=0;i--)
    {
        if(f[i])
        {
                cout<<i<<endl;
                break;
                }
                }    
    //while(1);
    return 0; 

}
