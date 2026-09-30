#include<iostream>
using namespace std;

int modExp(int N,int &M,int &a)
{
   if(N==1) return a%M;
   if(N%2) return ((a%M)*modExp((N-1)/2,M,a)*modExp((N-1)/2,M,a))%M; 
   else return (modExp(N/2,M,a)*modExp(N/2,M,a))%M;
}
int main()
{
    int N=40,M=5,a=3;
    cout<<modExp(40,M,a)<<"\n";
     auto modExp=[N,M](long long int a){
        int n=N;
        long long int result=1;
        while(n>0)
        {
           if(n%2)
           {
               result=(result*a)%M;
           }
           a=(a*a)%M;
           n/=2;
        }
        return result;
    };
    cout<<modExp(3)<<"\n"; 
}

