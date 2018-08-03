 #include<iostream>
 #include<cmath>
 using namespace std;
 int main()
 {
    long long n,sum;
    int b;
    cin>>n>>b;
    sum=(long long)pow(2,(b+1)*1.0);
    if(n>sum-1)cout<<"no"<<endl;
    else cout<<"yes"<<endl; \
    //while(1);
    return 0;   
 }

