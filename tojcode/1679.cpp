#include<iostream>
#include<cstring>
using namespace std;
char s[500001];
int getminsub(char *a)
{
    int i=0,j=1,len=strlen(a),k=0;
    while(i<len&&j<len&&k<len)
    {
        if(k==len) break;
        if(i==j) j++;
        int ni=i+k,nj = j+k;
        if(ni>=len) ni-=len;
        if(nj>=len) nj-=len;
        if(a[ni]>a[nj])
        {
            i+=k+1;
            k=0;
        }
        else if(a[ni]<a[nj])
        {
            j+=k+1;
            k=0;
        }
        else k++;
    }
    return  i;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a>>s;
        cout<<getminsub(s)<<endl;
    }
}
