#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;

int main()

{double a[10000],b[10000];

 int i,n;

 while(scanf("%d",&n)!=EOF)

 {for(i=0;i<n;i++)
{
  scanf("%lf%lf",&a[i],&b[i]);
}
  a[i]=a[0];

  b[i]=b[0];

  cout<<n;

  for(i=0;i<n;i++){

  cout<<" "<<setprecision(6)<<fixed<<(a[i]+a[i+1])/2<<" "<<setprecision(6)<<fixed<<(b[i]+b[i+1])/2;
}
  cout<<endl;               

                           }

      }
