#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
    bool prime[10001];
    memset(prime,1,sizeof (prime));
    prime[0] = false;prime[1] = false;
    for (int i = 2; i < 5000; ++i)
    {
        int k = 2;
        int next;
        while((next = (k++) * i) < 10000)
            prime[next] = false;
    }

    int cases;
    cin >> cases;
    int beg, end;
    int step;
    int visited[10001];
    int base[4]= {1, 10, 100, 1000};
    for (int c = 0; c < cases; ++c)
    {
        scanf("%d %d", &beg, &end);
        memset(visited, -1, sizeof(visited));
        queue<int> q;
        q.push(beg);
        visited[beg] = 0;
        step = -1;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (cur == end)
            {
                step = visited[cur];
                break;
            }
            
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 10; ++j)
                {
                    int l = cur / (base[i] * 10);
                    int r = cur % base[i];
                    int num = l * base[i] * 10 + j * base[i] + r;
                    if (num > 1000 && num != cur && prime[num] == true && visited[num] == -1)
                    {
                        q.push(num);
                        visited[num] = visited[cur] + 1;
                    }
                }
            }
        }

        if (step == -1)cout << "Impossible\n";
        else cout << step << endl;
    }

    return 0;
}
