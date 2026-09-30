#include<iostream>
#include<list>
using namespace std;

int main()
{
    int t,buf,pre;
    cin >> t;
    while(t--)
    {
        list<int> ls1;
        while(cin>>buf)
        {
            if(ls1.size()>0) pre=ls1.back();
            ls1.push_back(buf);
            if(ls1.size()>1 && buf==pre) break;
        }
        ls1.sort();
        auto it=ls1.begin();
        list<int> ans;
        if(ls1.size()%2)
        {
             for(int q=0;q<ls1.size();++q)
            {
                if(q%2==0) ans.push_front(*it);
                else ans.push_back(*it);
                ++it;
            }
        }
        else{
             for(int q=0;q<ls1.size();++q)
            {
                if(q%2==0) ans.push_back(*it);
                else ans.push_front(*it);
                ++it;
            }

        }
        
        auto ita=ans.begin();
        for(int q=0;q<ans.size();++q,++ita)
        {
            if(!q) cout << *ita;
            else cout << " " << *ita;
        }
        cout << "\n";
    }
}

