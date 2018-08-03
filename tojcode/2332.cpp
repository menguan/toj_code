//*******************************
//***********************************
//*********************************
//**************************************
//假如只有AB就是卡特兰数
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=310;
const int mod=1000000000;
string st;
ll cnt[maxn][maxn];
void initial(){
    memset(cnt,-1,sizeof(cnt));
}
ll dp(int l,int r){
    if(l==r) return 1;
    if(st[l]!=st[r]) return 0;
    if(cnt[l][r]!=-1) return cnt[l][r];
    ll ans=0;
    for(int i=l+2;i<=r;i++){
        if(st[l]==st[i]){
            ans=(ans+dp(l+1,i-1)*dp(i,r))%mod;
        }
    }
    return cnt[l][r]=ans;
}
int main(){
    while(getline(cin,st)){
        initial();
        cout<<dp(0,st.length()-1)<<endl;
    }
}
