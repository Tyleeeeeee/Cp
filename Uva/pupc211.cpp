#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t,lay;
    auto pascaltri=[](int lay,vector<vector<int> > &tri){
        tri.push_back({1});
        for(int i=1;i<=lay;++i)
        {
            vector<int> vc(i+1,1);
            for(int j=1;j<i;++j)
            {
                vc[j]=tri[i-1][j-1]+tri[i-1][j];
            }
            tri.push_back(vc);
        }
        for(auto ob:tri)
        {
            for(int i=0;i<ob.size();++i)
            {
                if(!i) cout << ob[i];
                else cout << " " << ob[i];
            }
            cout << "\n";
        }
    };
    cin >> t;
    while(t-- && cin >> lay)
    {
       vector<vector<int> > tri; 
       pascaltri(lay,tri);
       cout << "\n";
    }
}

