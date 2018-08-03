#include <iostream>

using namespace std;

int main()
{
    int T, a, b, lcnt, rcnt;
    cin >> T;
    for(int i = 1; i <= T; ++i)
    {
        cin >> a >> b;
        lcnt = rcnt = 0;
        while(a != 1 || b != 1)
        {
            if(a >= b)
            {
                if(a % b)
                {
                    lcnt += a/b;
                    a %= b;
                }
                else
                {
                    lcnt += a/b-1;
                    a = 1;
                }
            }
            else
            {
                if(b % a)
                {
                    rcnt += b/a;
                    b %= a;
                }
                else
                {
                    rcnt += b/a-1;
                    b = 1;
                }
            }
        }
        cout << "Scenario #" << i << ':' << endl;
        cout << lcnt << ' ' << rcnt << endl <<endl;
    }
    return 0;
}