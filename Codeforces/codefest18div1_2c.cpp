#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n,ans=0;
    string a,b;
    cin>>n>>a>>b;
    for(int q=0;q<n;++q){
        if(a[q]==b[q]) continue;
        else{
            if(q+1<n && a[q+1]==b[q] && a[q]==b[q+1]) swap(a[q],a[q+1]),ans++;
            else if(q+1<n && a[q+1]!=b[q]) a[q]=1-a[q],ans++;
            else ans++;
        }
    }
    cout << ans << "\n";
}

