#include<stdio.h>//不太理解
int main()
{
       double sum;
       for(double i=0.000;i<=2.000;i+=0.001)
       {
             sum=0;
             for(double j=1.000;j<10000;j+=1.000)
              {
                     sum=sum+(1-i)/(j*(j+1)*(j+i));
             }
              sum=sum+(1-i)/(2*10000*10000)+1.0;
              printf("%5.3f %16.12f\n",i,sum);
       }
       
       //while(1);
}
