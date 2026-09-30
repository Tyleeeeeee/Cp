#include<iostream>
#include<algorithm>
#include<list>
#include<set>
using namespace std;

int main()
{
    int t,a,b,max,arr[]={0,1,2};
    while(cin >> t)
    {
        max=0;
        list<int> ls;
        set<int> posb(arr,arr+3);
        while(t-- && cin >> a >> b)
        {
            if(ls.size()) max=[&ls](){int max=0; for(int m:ls){if(m>max) max=m;} return max;}();
            if(a==1) {ls.push_back(b); }
            else {
                if(find(ls.begin(),ls.end(),b)!=ls.end())
                {
                    if(b!=max) posb.erase(2);
                    if(b!=ls.back()) posb.erase(0);
                    if(b!=ls.front()) posb.erase(1);
                    ls.erase(find(ls.begin(),ls.end(),b));
                }
                else posb.clear();
            }
        }
        if(!posb.size()) cout << "impossible\n";
        else if(posb.size()>1) cout << "not sure\n";
        else if(posb.count(2)) cout << "priority queue\n";
        else if(posb.count(1)) cout << "queue\n";
        else if(posb.count(0)) cout << "stack\n";
    }
}