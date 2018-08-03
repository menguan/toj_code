#include <iostream>
using namespace std;

int get_ans(int n, int b)
{
    int sum = 0;

    while(n / b)
    {
        sum += n / b;
        n /= b;
    }
    return sum;
}

int f(int n, int b)
{
    bool flag = true;
    int cnt, ans = 0;
    int i;

    for(i = 2; i * i <= b; i++)
    {
        cnt = 0;
        while(b % i == 0)
        {
            b /= i;
            cnt++;
        }

        if(cnt)
        {
            if(flag)
            {
                ans = get_ans(n, i) / cnt;
                flag = false;
            }
            else 
                ans = min(ans, get_ans(n, i) / cnt);
        }

    }

    if(b > 1)
    {    
        if(flag)
            ans = get_ans(n, b);
        else
            ans = min(ans, get_ans(n, b));
    }
    return ans;
}

int main()
{
    int n, b;

    while(cin>>n>>b,(n+b))
    {
        cout<<f(n,b)<<endl;
    }
    return 0;
}
