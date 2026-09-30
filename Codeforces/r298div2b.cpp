#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t,d,v1,v2,ans;
    ans=0;
    cin>>v1>>v2>>t>>d;
    while(t--){
        ans+=v1;
        //v1+d because always go fast is optimal choise but we need to conside if we spend 1 second to v1+d
        //is that possible we come back from v1+d to v2 in t-1 second (t is the current second),so we use a min 
        //between v1+d and v2+(t-1)*d
        v1=(v1+d<v2+(t-1)*d?v1+d:v2+(t-1)*d);
    }
    cout << ans << "\n";
}

