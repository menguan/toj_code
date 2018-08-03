#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int sg[10010], a[120], k;
int mex(int n) {
    bool vis[120];
    memset(vis,0,sizeof(vis));
    for(int i=0; i<k; i++) {
        int t = n - a[i];
        if(t < 0) continue;
        if(sg[t] == -1) sg[t] = mex(t);
        vis[sg[t]] = 1;
    }
    for(int i=0; ; i++) if(!vis[i]) return i;
}

int main() {
    int m;
    while(cin >> k && k) 
    {
        string s;
        for(int i=0; i<k; i++) cin >> a[i];
        cin >> m;
        memset(sg, -1, sizeof(sg));
        while(m--) {
            int j, ans = 0, hi;
            cin >> j;
            while(j--) {
                cin >> hi;
                ans ^= mex(hi);
            }
            if(ans) cout<<"W";
            else cout<<"L";
        }

        cout<<endl;
    }
}
