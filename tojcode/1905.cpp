 #include<stdio.h>//题目连算面积的方法都给了 我也是懒得自己打了 
 #include<math.h>
 #include<iostream>
 #include<algorithm>
 using namespace std;
 double area(int x1,int y1,int x2,int y2,int x3,int y3)
 {return fabs(0.5*((y3-y1)*(x2-x1)-(y2-y1)*(x3-x1)));}
 int main()
 {int  x[16],y[16],n,i,j,k,A,B,C,p,flag;
  double s,sarea;
  char point[16];
  while (cin>>n,n)
  {
  for (i=1;i<=n;i++)
  {
   cin>>point[i]>>x[i]>>y[i];
  }
  sarea=0; 
  for (i=  1;i<=n-2;i++)
  for (j=i+1;j<=n-1;j++)
  for (k=j+1;k<=n  ;k++)
  {s=area(x[i],y[i],x[j],y[j],x[k],y[k]);
   flag=1;
   for (p=1;p<=n;p++)
   if (!((p==i)||(p==j)||(p==k))) 
   {
   if (s==area(x[i],y[i],x[j],y[j],x[p],y[p])+area(x[i],y[i],x[p],y[p],x[k],y[k])+area(x[p],y[p],x[j],y[j],x[k],y[k]))
   {flag=0;break;}
   }
   if ((flag)&&(s>sarea)) {sarea=s; A=i; B=j; C=k;}
  }
  cout<<point[A]<<point[B]<<point[C]<<endl;
  }
 } 