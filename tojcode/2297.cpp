#include <cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

ll f(int k)
{
    ll sum = 1;
    for(int i = 0;i < k; i++)
        sum *= 2;
    return sum;
}

ll exGcd(ll a, ll b, ll &x, ll &y)
{
   ll d, t;
   if(b == 0) { x = 1; y = 0; return a; }
   d = exGcd(b, a % b, x, y);
   t = x; x = y; y = t - a / b * y;
   return d;
}

int main()
{
     ll a, b, c, x, y, d, r;
     int k;
     while(cin>>a>>b>>c>>k, a + b + c + k)
     {
         d = exGcd(c, f(k), x, y);
         if((b - a) % d != 0) cout<<"FOREVER"<<endl;
         else
		 {
            x = x * (b - a) / d;
            r = f(k) / d;
            x = (x % r + r) % r;
            cout<<x<<endl;
         }
     }
     return 0;
}
