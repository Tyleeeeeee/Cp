//euler totient function
//phi(x) mean the number less equal to x and greatest common divisor with x is 1
//in other word let n<=x and gcd(n,x)=1
//formula phi(x)=x*(1-1/p1)*(1-1/p2)*...
//p1 p2 ... and pn is the prime divisor of x
//ll solve(ll n){
//     ll ans=n;
//     for(ll i=2;i*i<=n;++i){
//         if(n%i==0) ans=ans/i*(i-1);
//         while(!(n%i)) n/=i;
//     }
//     if(n>1) ans=ans/n*(n-1);
//     return ans;
// }
