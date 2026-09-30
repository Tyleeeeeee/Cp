#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n,m,a,b,c;
    long long int ans;
    while(cin >> n >> m)
    {
        ans=0;
        vector<int> vc;
        for(int i=1;i<=n;++i) vc.push_back(i);
        for(int i=0;i<m;++i)
        {
            cin >> c;
            if(c==4)
            {
                for(int i=0;i<vc.size()/2;++i)
                {
                    swap(vc[i],vc[vc.size()-1-i]);
                }
            }
            else{
                cin >> a >> b;
                if(c==1)
                {
                    auto it=find(vc.begin(),vc.end(),a);
                    vc.erase(it);
                    auto ite=find(vc.begin(),vc.end(),b);
                    vc.insert(ite,a);
                }
                else if(c==2){
                    auto it=find(vc.begin(),vc.end(),a);
                    vc.erase(it);
                    auto ite=find(vc.begin(),vc.end(),b);
                    vc.insert(++ite,a);
                }
                else if(c==3){
                    auto it=find(vc.begin(),vc.end(),a);
                    auto ite=find(vc.begin(),vc.end(),b);
                    swap(*it,*ite);
                }
            }
        }
        for(int i=0;i<vc.size();i+=2)
        {
            ans+=vc[i];
        }
        cout << ans << "\n";
    }
}



