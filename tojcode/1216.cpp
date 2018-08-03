//wa
/*#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct elephant
{
  int wei,iq;int id;
}ele[1200];
bool cmp(elephant a,elephant b)
{
     if(a.iq==b.iq)
       return a.wei>b.wei;
     else
       return a.iq>b.iq;
}

int main()
{
    int con=0;
    int w,q;
    while(cin>>w>>q)
    {
       ele[con].wei=w;
       ele[con].iq=q;
       ele[con].id=con+1;
       con++;
       
    }
    sort(ele,ele+con,cmp);
    for(int i=0;i<con;i++)
      cout<<ele[i].wei<<" "<<ele[i].iq<<endl;
    int st[1200];int ans[1200];
    st[0]=-1;
    int top=0;int mid,low,high;
    for(int i=0;i<con;i++)
    {
       if(ele[i].wei>st[top])
       {
         
         st[++top]=ele[i].wei;
         ans[top]=ele[i].id;
       }  
       else
       {
           low=1;high=top;
           while(low<=high)
           {  //cout<<"kk"<<endl;
              mid=(low+high)/2;
              if(st[mid]>ele[i].wei)
                high=mid-1;
              else
                low=mid+1;
           }
           st[low]=ele[i].wei;
           //ans[low]=ele[i].id;
       }
    }
    
    cout<<top<<endl;
    for(int i=1;i<=top;i++)
      cout<<ans[i]<<endl;
    while(1);
}  */
#include<stdio.h>
#define N 1005
FILE *f1,*f2;
typedef struct node
{
        long w,s,num;
}node;
node a[N];
long f[N],b[N],q[N],n;

int bigger(node x,node y)
{
     if (x.w!=y.w) return (x.w>y.w);
     else return (x.s<y.s);
}

void sort(long left,long right)
{
     long i,j;
     node x,t;
     i=left;j=right;
     x=a[(i+j)/2];
     while (i<=j)
     {
           while (bigger(x,a[i])) i++;
           while (bigger(a[j],x)) j--;
           if (i<=j)
           {     t=a[i];a[i]=a[j];a[j]=t;
                 i++;j--;
           }
     }
     if (left<j) sort(left,j);
     if (i<right) sort(i,right);
}
int main()
{
    long i,j,k,max;
    i=1;
    while (scanf("%ld%ld",&a[i].w,&a[i].s)==2)  a[i].num=i++;  
    n=i-1;
    sort(1,n);
    for (i=1;i<=n;i++) {f[i]=1;b[i]=i;}
    for (i=1;i<=n;i++)
        for (j=1;j<i;j++)
            if (a[j].w<a[i].w&&a[j].s>a[i].s&&f[j]+1>f[i])
            {  f[i]=f[j]+1; b[i]=j; }
    max=0;
    for (i=1;i<=n;i++)
        if (f[i]>max) {max=f[i];k=i;}
    printf("%ld\n",max);
    q[1]=a[k].num; i=1;
    while (b[k]!=k) {q[++i]=a[b[k]].num; k=b[k];}
    for (i=max;i>=1;i--)
        printf("%ld\n",q[i]);
    //while(1);    
    return 0;
}
                                                    
    
         

