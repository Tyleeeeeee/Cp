#include<iostream>
#include<cmath>
using namespace std;

#define log2(x) (log(x)/log(2))
#define log3(x) (log(x)/log(3))
#define log6(x) (log(x)/log(6))
int main()
{
    auto exp=[](unsigned long long int a,int n)->unsigned long long int{
        unsigned long long int ans=1;
        while(n)
        {
            if(n%2) ans*=a;
            a*=a;
            n/=2;
        }
        return ans;
    };
    auto solve=[](unsigned long long int a){
        int ans=log6(a);
        while(a)
        {
            ans+=(int)log2(a)+(int)log3(a);
            a/=6;
        }
        return ans;
    };
    int t,n2,n3,ans2;
    unsigned long long int ans1;
    cin >> t;
    while(t-- && cin >> n2 >> n3)
    {
        ans1=exp(2,n2)*exp(3,n3); 
        ans2=solve(ans1);
        cout << ans1 << " " << ans2 << "\n";
    }
}

