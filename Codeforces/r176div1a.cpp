#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> ans,b;
int main()
{
    cin.tie(0),ios::sync_with_stdio(false);
    cin>>n;
    if(n==1) ans.push_back(1);
    else if((n/2)%2) ans.push_back(-1);
    else{
        for(int q=1;q<=n/2;++q) 
            if(q%2) ans.push_back(q+1);
            else ans.push_back(n-(q-1)+1);
        for(int q=0;q<ans.size();++q){
            b.push_back(n+1-ans[q]);
        }
        if(n%2) ans.push_back((n+1)/2);
        reverse(b.begin(),b.end());
        ans.insert(ans.end(),b.begin(),b.end());
    }
    for(auto &v:ans) cout << v << " " ;
    cout << "\n";
}

