#include<iostream>
#include<cstring>
using namespace std;
using ll=long long;

ll dp[1000000];
int main()
{
    for(int q=0;q<1000000;++q) dp[q]=1;
    dp[0]=dp[1]=0;
    for(int q=2;q*q<=1000000;++q){ //O(NloglogN)
        if(dp[q]) for(int w=q*q;w<1000000;w+=q) dp[w]=0;
    }
    for(int q=0;q<1000000;++q){
        cout << "q:" << q << " dp[q]:" << dp[q] << "\n";
    }
}
//main idea is first assume all of the number is prime then start from first prime which is 2 then start from p*p
//and p*p+p p*p+2p and so on,in this process if dp[q] is 1 this mean it is a prime then do the same thing than prime
//number before otherwise continue
