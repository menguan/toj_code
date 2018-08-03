#include<iostream>
#include<algorithm>
using namespace std;
int s[1001000];
int e[1001000];
int main()

{
    int t,n,i,j,k,ans;
    cin>>t;
    while(t--){
       cin>>n;
       for(i=0;i<n;i++){
           cin>>s[i]>>e[i];

       }
       sort(s,s+n);
       sort(e,e+n);
       i=0;
       j=0;
       ans=0;
       while(i<n){   
           if(s[i]>=e[j]){
              i++;j++;
           }else{
              i++;ans++;
           }
       }
       cout<<ans<<endl;
    }
    return 0;

}
