#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ans;
int main()
{
    int n,ver;
    while(cin>>n>>ver)
    {
        if(n==-1&&ver==-1) break;
        ans.clear();
        int l;
        for(l=0;l*(l+1)/2<ver;l++);l++;
        for(int i=1;i<=n-l;i++) ans.push_back(i);
        int temp=n-l+1+ver-(l-2)*(l-1)/2;//在需要制造你叙述的序列中只有第一个是顺序 之后都是倒序  把顺序的那个数求出来 
        ans.push_back(temp);
        for(int i=n;i>n-l;i--)
        {
            if(i!=temp) ans.push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            if(i) cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
    }
}

