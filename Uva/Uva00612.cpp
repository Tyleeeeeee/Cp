#include<iostream>
#include<vector>
#include<string>
using namespace std;

class ans{
    public:
    string s;
    int c;
    ans(int val):c(val){}
};
void solve(vector<ans> &dna)
{
    for(int n=0;n<dna.size();++n)
    {
        for(int i=0;i<dna[n].s.length();++i)
        {
            for(int j=i+1;j<dna[n].s.length();++j)
            {
                if(dna[n].s[i]>dna[n].s[j]) dna[n].c++;
            }
        }
    }
}
int main()
{
    int t,n,m;
    while(cin >> t)
    {
        while(t-- && cin >> n >> m)
        {
            vector<ans> dna(m,ans(0));
            for(int i=0;i<m;++i) cin >> dna[i].s;
            solve(dna);
            for(int i=0;i<=(n-1)*(n)/2;++i)
            {
                for(int j=0;j<m;++j)
                {
                    if(dna[j].c==i) cout << dna[j].s << "\n";
                }
            }
            cout << "\n";
        }
    }
}