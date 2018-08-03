#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;
const int MAXN = 10010;

int n, arr[MAXN];
int left_up[MAXN], right_down[MAXN];
vector<int>vt;


int main(){

    while(~scanf("%d", &n)){
    
        for(int i=0; i<n; ++i)
            scanf("%d", &arr[i]);

        vt.clear();
        for(int i=0; i<n; ++i){
            if(vt.empty() || vt.back()<arr[i]){
                vt.push_back(arr[i]);
            }else{
                int pt = lower_bound(vt.begin(), vt.end(), arr[i])-vt.begin();
                vt[pt] = arr[i];
            }
            left_up[i] = vt.size();
        }

        vt.clear();
        for(int i=n-1; i>=0; --i){
            if(vt.empty() || vt.back() < arr[i]){
                vt.push_back(arr[i]);
            }else{
                int pt = lower_bound(vt.begin(), vt.end(), arr[i])-vt.begin();
                vt[pt] = arr[i];
            }
            right_down[i] = vt.size();
        }

        int ans = 0;
        for(int i=0; i<n; ++i){
            ans = max(ans, min(left_up[i], right_down[i])*2-1); 
        }
        printf("%d\n", ans);
    }

    return 0;
}