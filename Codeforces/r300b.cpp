#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    vector<int> fn;
    cin>>n;
    while(n){
        int tmp,a,ans;
        tmp=n,a=1,ans=0;
        while(tmp){
            //tmp%10==0 then 0 else 1
            if(tmp%10) ans+=a;
            tmp/=10,a*=10;
        }
        fn.push_back(ans),n-=ans;
    }
    cout << fn.size() << "\n";
    for(auto&v:fn) cout << v << " ";
    cout << "\n";
}

