#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

long long t,n;
void solve()
{
    //why sqrt(n)?
    //because when k<sqrt(n) every floor(n/k) will have a unique value (can be proved)
    //and when k>sqrt(n) floor(n/k) will have a lot of same value(can be proved)
    //
    //Let consider sqrt(n) < n/2
    //sqrt(n) < n/2
    //2sqrt(n) < n
    //4n<n^2
    //n(n-4)>0
    //n<0 || n>4 (in this case we only condider positive n which is n>4)
    //so we have when n>4 n/2 is greater than sqrt(n),so in x-axis it will look like
    //0 1 2 3 ... sqrt(n) ... n/2 ... n
    //so since sqrt(n)<n/2 when n>4 and we know if k<sqrt(n),floor(n/k)>=sqrt(n)
    //this mean k in [1,floor(sqrt(n))] will produce a result in [floor(sqrt(n)),n] which is small range k to produce
    //a large range k ,in otherword when k in [1,floor(sqrt(n))],floor(n/k) is decrease rapidly and in [floor(sqrt),n]
    //floor(n/k) will decrease slowly such that duplicate a lot of same value

    //First lemma: when k<sqrt(n) floor(n/k) is decrease rapidly and k>sqrt(n) floor(n/k) is decrease slowly

    //Now we are ready to prove thah when k<sqrt(n) floor(n/k) will have unique value,in otherword no k1<k2 and
    //floor(n/k1)=floor(n/k2)
    //We are prove it by contradiction,
    //Assume that exist k1<k2 and floor(n/k1) = floor(n/k2) = x
    //since floor(n/k2)=x,so
    //      x<=n/k2<x+1
    //      x<=n/k1<x+1
    //
    //      but since k2>k1,so we have
    //      n/x >= k2 > n/(x+1)         
    //      n/x >= k1 > n/(x+1)
    //      n/x >= k2 > k1 > n/(x+1) -> n/x > k1 > n/(x+1)
    //      x < n/k1 < x+1
    //      This is a contradiction,at the begin we assume that x<=n/k1<x+1 but we get a result which x<n/k1<x+1
    //Second lemma: when k>sqrt(n),floor(n/k) inside [0,floor(n/(sqrt(n)))]
    //Proof:
    //      Assume that exist k1<k2=k1+1 such that when k>sqrt(n) ,floor(n/k1)-floor(n/k2)>=2
    //      suppose that floor(n/k1)=x,we have
    //      x<=n/k1<x+1
    //      n/x>=k1>n/(x+1)
    //      
    //      floor(n/k2)<=x-2 
    //      x-2<=n/k2<x-1
    //      n/(x-2)>=k2>n/(x-1)
    //      n/(x-2)>=k1+1>n/(x-1)
    //      |---k1---|-------|---k1+1---|--------
    //   n/(x+1)   n/x   n/(x-1)   n/(x-2)
    //   (n+x+1)/(x+1) (n+x)/x
    //   (n+x)/x < n/(x-1)
    //   n(n+x) < x(x-1)
    //   n^2 + nx < x^2 - x
    //   n^2 + x(n+1) < x^2 (0<x<=n) //impossible
    //
    //   (n+x+1)/(x+1) > (n+x)/x
    //        nx+x^2+x > nx+x^2+n+x
    //               0 > n // impossible
    //   Contradiction
    long long sq=sqrt(n);
    set<long long> ans;
    for(int q=1;q<=sq;++q) ans.insert(floor(n/q));
    for(int q=0;q<=sq;++q) ans.insert(q);
    cout << ans.size() << "\n";
    for(auto&v:ans)cout << v << " ";
    cout << "\n";
}
int main()
{
    cin>>t;
    while(t--&&cin>>n){
        solve();
    }
}



