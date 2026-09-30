#include<functional>
#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int N)
{
    if(N==1) return false;
    if(N==2 ||N==3) return true;
    if(!(N%2) ||!(N%3)) return false;
    for(int q=5;q<=sqrt(N);q+=6)
    {
        if(!(N%q) || !(N%(q+2))) return false;
    }
    return true;
}
bool fermatTest(int N,const function<int(int)> &cn)
{
   for(int q=2;q<N;++q)
   {
       if(cn(q)!=q){return false;} 
   }
   return true;
}

int main()
{
    int N;
    auto modExp=[&N](long long int a){
        int n=N;
        long long int result=1;
        while(n>0)
        {
           if(n%2)
           {
               result=(result*a)%N;
           }
           a=(a*a)%N;
           n/=2;
        }
        return result;
    };
    while(cin>>N && N)
    {
       if(isPrime(N)==false && fermatTest(N,modExp)) cout<<"The number "<<N<<" is a Carmichael number.\n";
        else cout<<N<<" is normal.\n"; 
    }
}

