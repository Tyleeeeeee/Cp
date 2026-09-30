#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define DEBUG 1
   #if DEBUG
    #define err(...) cerr << '[' << #__VA_ARGS__ << "] = "; debug(__VA_ARGS__)
       template<typename T,typename... Args>
       inline void debug (const T& val,const Args&... args){
           cerr << '[' << val; ((cerr << ' ' << args),...); cerr << "]\n";
       }
       #define terr cerr << "I am here" << '\n'
   #endif
#define forn(a,b,c) for(ll a=b;a<c;++a)
#define forr(a,b,c) for(ll a=b;a>=c;--a)
#define bg begin
#define ar array
#define vc vector
#define emp emplace_back
#define upb upper_bound
#define all(x) x.begin(),x.end()
using i128=__int128;

//10010103 200
//1001003 100
//1000100 100
//10001000 100
constexpr ll inf=0x3f3f3f3f3f3f3f3f;


struct BI {       
    static const int B = 1e9, W = 9;
    int s = 1;   
    vector<int> d; 
 
    BI() {}
    BI(long long v) { if (v < 0) s = -1, v = -v; for (; v; v /= B) d.push_back(v % B); }
    BI(const string& x) {
        int i = (x[0] == '-' || x[0] == '+'); if (x[0] == '-') s = -1;
        for (int e = x.size(); e > i; e -= W) { int b = max(i, e - W); d.push_back(stoi(x.substr(b, e - b))); }
        tr();
    }
    void tr() { while (!d.empty() && !d.back()) d.pop_back(); if (d.empty()) s = 1; }
 
    static int cmpA(const BI& a, const BI& b) {               
        if (a.d.size() != b.d.size()) return a.d.size() < b.d.size() ? -1 : 1;
        for (int i = a.d.size() - 1; i >= 0; i--) if (a.d[i] != b.d[i]) return a.d[i] < b.d[i] ? -1 : 1;
        return 0;
    }
    static BI addA(BI a, const BI& b) {                      
        if (a.d.size() < b.d.size()) a.d.resize(b.d.size());
        int c = 0;
        for (size_t i = 0; i < b.d.size() || c; i++) {
            if (i == a.d.size()) a.d.push_back(0);
            long long t = a.d[i] + c + (i < b.d.size() ? b.d[i] : 0);
            c = t >= B; a.d[i] = t - (c ? B : 0);
        }
        return a;
    }
    static BI subA(BI a, const BI& b) {                     
        int c = 0;
        for (size_t i = 0; i < b.d.size() || c; i++) {
            long long t = a.d[i] - c - (i < b.d.size() ? b.d[i] : 0);
            c = t < 0; a.d[i] = t + (c ? B : 0);
        }
        a.tr(); return a;
    }
 
    BI operator-() const { BI r = *this; if (!r.d.empty()) r.s = -r.s; return r; }
    BI operator+(const BI& o) const {
        if (s == o.s) { BI r = addA(*this, o); r.s = s; return r; }
        int c = cmpA(*this, o); if (!c) return BI();
        BI r = c > 0 ? subA(*this, o) : subA(o, *this);
        r.s = c > 0 ? s : o.s; return r;
    }
    BI operator-(const BI& o) const { return *this + (-o); }
    BI operator*(const BI& o) const {
        BI r; if (d.empty() || o.d.empty()) return r;
        r.d.assign(d.size() + o.d.size(), 0);
        for (size_t i = 0; i < d.size(); i++) {
            unsigned long long c = 0;
            for (size_t j = 0; j < o.d.size() || c; j++) {
                unsigned long long t = r.d[i + j] + c + (j < o.d.size() ? (unsigned long long)d[i] * o.d[j] : 0);
                r.d[i + j] = t % B; c = t / B;
            }
        }
        r.s = s * o.s; r.tr(); return r;
    }
    BI& operator+=(const BI& o) { return *this = *this + o; }
    BI& operator-=(const BI& o) { return *this = *this - o; }
    BI& operator*=(const BI& o) { return *this = *this * o; }
 
    int len() const { return d.empty() ? 1 : (int)(d.size() - 1) * W + (int)to_string(d.back()).size(); }
 
    BI abs() const { BI r = *this; r.s = 1; return r; }
 
    static void divmod(const BI& a, const BI& b, BI& q, BI& r) {
        BI x = a.abs(), y = b.abs();
        q = BI(); r = BI();
        if (y.d.empty()) return;                       
        q.d.assign(x.d.size(), 0);
        for (int i = x.d.size() - 1; i >= 0; i--) {
            r.d.insert(r.d.begin(), x.d[i]); r.tr();   
            int lo = 0, hi = B - 1;                   
            while (lo < hi) { int m = lo + (hi - lo + 1) / 2; if (y * BI((long long)m) <= r) lo = m; else hi = m - 1; }
            q.d[i] = lo;
            r = r - y * BI((long long)lo);
        }
        q.tr(); q.s = (q.d.empty() ? 1 : a.s * b.s);
        r.tr(); r.s = (r.d.empty() ? 1 : a.s);
    }
    BI operator/(const BI& o) const { BI q, r; divmod(*this, o, q, r); return q; }
    BI operator%(const BI& o) const { BI q, r; divmod(*this, o, q, r); return r; }
    BI& operator/=(const BI& o) { return *this = *this / o; }
    BI& operator%=(const BI& o) { return *this = *this % o; }
 
    int cmp(const BI& o) const { if (s != o.s) return s < o.s ? -1 : 1; int c = cmpA(*this, o); return s > 0 ? c : -c; }
    bool operator< (const BI& o) const { return cmp(o) <  0; }
    bool operator> (const BI& o) const { return cmp(o) >  0; }
    bool operator<=(const BI& o) const { return cmp(o) <= 0; }
    bool operator>=(const BI& o) const { return cmp(o) >= 0; }
    bool operator==(const BI& o) const { return cmp(o) == 0; }
    bool operator!=(const BI& o) const { return cmp(o) != 0; }
 
    friend istream& operator>>(istream& is, BI& v) { string x; is >> x; v = BI(x); return is; }
    friend ostream& operator<<(ostream& os, const BI& v) {
        if (v.d.empty()) return os << 0;
        if (v.s < 0) os << '-';
        os << v.d.back();
        for (int i = v.d.size() - 2; i >= 0; i--) { string t = to_string(v.d[i]); os << string(W - t.size(), '0') << t; }
        return os;
    }
};

//c[i]>=p x=i*p- c[j](j<i)
constexpr ll mxN=1e5+1;
void solve(){
	BI p,q,x=0;
	cin >> p >> q;
	forn(i,1,mxN){
		BI I=i;
		BI tmp=q*I*I*I*I*I;
		if(tmp>=p){x=I*p-x; break;}
		else x+=tmp;
	}
	//x-m*p+
	BI l=0,r("1000000000000000000000000000"),m;
	while(r-l>1){
		m=(l+r)/2;
		BI ta=x-m*p+q*(m*m*(m+1)*(m+1)*((BI)2*m*m+(BI)2*m-1))/12;
		if(ta.len()>99) r=m;
		else l=m;
	}
	cout << x << '\n' << r << '\n';
}
int main()
{
	cin.tie(0),ios_base::sync_with_stdio(false);
	int testcase;
	testcase=1;
	//cin >> testcase;
	while(testcase--) solve();
	return 0;
}
