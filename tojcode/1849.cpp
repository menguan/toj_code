#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
#define MAX_N 32000 + 16

struct Inhabitant
{
    double position;
    string name;
    bool operator < (const Inhabitant& other) const
    {
        return fabs(position) < fabs(other.position);
    }
};
Inhabitant ih[MAX_N];

int main()
{

    int N;
    while (cin >> N && N)
    {
        double L, V;
        cin >> L >> V;
        for (int i = 0; i < N; ++i)
        {
            char pn;
            cin >> pn >> ih[i].position >> ih[i].name;
            if (pn == 'n' || pn == 'N')
            {
                ih[i].position = -ih[i].position;
            }
        }
        // 输入结束
        sort(ih, ih + N);
        double max_d = 0.0;  // 离端点的最远距离
        int id = 0;          // 对应的居民
        bool right = true;   // 该居民是否往右爬
        for (int i = 0; i < N; ++i)
        {
            double nd = (ih[i].position < 0.0 ? 0 : L) - ih[i].position;  // 离端点的距离
            if (nd > max_d + 1e-6)
            {
                max_d = nd;
                id = i;
                right = ih[i].position > 0.0;
            }
        }

        int count = 0;   // 该居民的前进路线上跟该居民反方向的个数
        if (right)
        {
            for (int i = id; i < N; ++i)
            {
                if (ih[i].position < 0.0)
                {
                    ++count;
                }
            }
            id += count;
        }
        else
        {
            for (int i = id; i >= 0; --i)
            {
                if (ih[i].position > 0.0)
                {
                    ++count;
                }
            }
            id -= count;
        }

        double result = max_d / V;
        cout << setw(13) << fixed << setprecision(2) << (int)(result * 100) / 100.0 << ' ' << ih[id].name << endl; // 这里是截断，不是四舍五入
    }
    return 0;
}
