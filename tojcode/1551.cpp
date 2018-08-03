#include<iostream>
#include<cstring>
int main()
{
  std::string a;
  while(std::cin>>a&&a!="0")
  {
    int number=0;
    for(int i=0;i<a.size();i++)
    {    
      number+=(a[i]-'0');
      if(number>9)
      {
        number=number%10+number/10;
      }
    }
    std::cout<<number<<std::endl;
  }
  return 0;
}