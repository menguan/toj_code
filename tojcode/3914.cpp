#include<iostream>
#include<cmath>
int main()
{
  long long n,count1;
  while(std::cin>>n)
  {
    count1=0; 
    do{count1+=(n%2);}while(n/=2);
    std::cout<<(int)(pow(2.0,count1*1.0))<<std::endl;
  }
} 