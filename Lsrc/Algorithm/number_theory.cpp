// Nature 1
// if a>0  a mod n = k then -a mod n = n+(-a)
// Proof:
//          For example 3 mod 5 = 3 , -3 mod 5 = 2
//          Result of mod 5:
//              number:4 3 2 1 0 -1 -2 -3 -4 
//              mod   :4 3 2 1 0  4  3  2  1
//              *from 0 to k the mod n result is start from 0 and until n-1 and repeat
//              *but from 0 to -k the mod n result is start from n-1 to 0 and repeat
//              
//              number:4 3 2 1 0 -1 -2 -3 -4 
//              mod   :4 3 2 1 0  4  3  2  1
//                     - - - - -  -  -  -  -
//                     |___________________|
//                              n-1
//              so from this observation,we can conclude that if -a mod n = n-a
//another mathematical proof:
//Assume that a>0 , a mod n =k,then
//      a=nq+k
//      -a=-nq-k (but remainder is only positive under defination)
//      -a=-nq+n-n-k
//      -a=n(-q-1)+(n-k) 
//      -a mod n = (n(-q-1)+(n-k)) mod n
//      -a mod n = n-k
//*****
//
//Nature 2
//Divisibility 
//if a|b && b|c then a|c (a|b refer to a can completely divide b which mean b/a have no remainder)
//if a|b && a|c then a|(b*m+c*n)
//This nature is very simple so i will not gonna to prove but this nature is very useful on your future programming
//
//*****
//
//Nature 3
//Euclidean algorithm
//A way to find gcd between two given number number
//gcd(a,0)=a 
//gcd(a,b)=gcd(b,a%b)
//
//Proof:
//      To find the gcd between a and b assume that a>b,then
//      a=b*k1 + r1
//      r1=a-b*k1
//      And from the Nature 2 which if gcd|a && gcd|b so we have gcd|r1
//      so we can write the new formula
//      b=r1*k2 + r2
//      Similarly gcd|b && gcd|r1 thus gcd|r2,we can keep doing this and we found that r2 will become smaller each 
//      time until it become zero then b is the gcd,let us use a example
//      Ex:Find the gcd between 2740 and 1760
//          q   a     b     r
//          1   2740  1760  980
//          1   1760  980   780
//          1   980   780   200
//          3   780   200   180
//          1   200   180   20
//          9   180   20    0
//              20      
//          So gcd(2740,1760)=20
//
//*****
//
//Nature 4
//Euclidean algorithm generalized(Bézout's identity)
//s*a+t*b=gcd(a,b)
//
//Proof:
//      From the Euclidean algorithm,we can know how to find gcd(a,b),
//      a=b*k1+r1   r1=a-b*k1
//      b=r1*k2+r2  r2=b-r1*k2=b-(a-b*k1)*k2=-a*k2 + b(1+k1*k2)
//      so obviously keep doing this until ri become gcd then we have gcd(a,b)=s*a+t*b
//
//      Since we know definitely exist a pair of (s,t) such that s*a+t*b=gcd(a,b),
//      a=b*k1+r1                   r1=          (1-0)a+                     (0-k1)b
//      b=r1*k2+r2                  r2=         (0-k2)a+                  (1+k1*k2)b
//      r1=r2*k3+r3                 r3=      (1+k2*k3)a+          (-k1-k3-k1*k2*k3)b
//      r2=r3*k4+r4                 r4=(-k2-k4-k2k3k4)a+(1+k1k2+k1k4+k3k4+k1k2k3k4)b
//      .
//      .
//      .
//      gcd(a,b)=rn=(rn+1)*(rn+2)   rn=              sa+                          tb
//      Now i will introduce a special method to show that how to find s*a+t*b=gcd(a,b)
//      q   a   b   r   s1   s2             s       t1       t2                 t
//      k1  a   b  r1   m    n              1        q        w                -k1
//      k2  b  r1  r2   n    1             -k2       w       -k1              1+k1k2
//      k3 r1  r2  r3   1   -k2          1+k2k3     -k1     1+k1k2         -k1-k3-k1k2k3
//      k4 r2  r3  r4  -k2 1-k3+k2k3    .....     1+k1k2  -k1-k3-k1k2k3      .....
//      .
//      .
//      from the table above we can conclude that 
//      m-n*k1=1 (1)                q-w*k1=-k1(1)
//      n-k2=-k2(2)                 w+k1k2=1+k1k2(2)
//      from (2) n=0 ->(1)          from(2) w=1 ->(1)
//      m-0=1                       q-k1=-k1
//      m=1                         q=0
//      Thus m=1,n=0                Thus q=0,w=1
//
//      
//      Ex:Find gcd(161,28) and 161s+28t=gcd(161,28)
//        
//         q   a   b   r   s1   s2  s    t1  t2  t
//     k1  5   161 28  21  1    0   1    0   1  -5
//     k2  1   28  21  7   0    1  -1    1  -5   6
//     k3  3   21  7   0   1   -1   4   -5   6 -23
//             7          -1             6
//        So gcd(161,28)=7 and s=-1,t=6
//        
//*****
//
//Nature 5
//Linear diophantine equation solution
//Linear diophantine equation is defined as a1b1+a2b2+a3b3+...+anbn=c(ai is coefficient and bi is variable)
//2 variable diophantine equation ax+by=c solution:
//x0=(c/gcd(a,b))*s ,y0=(c/gcd(a,b))*t  (special solution)
//x=x0 + (kb)/d ,y=y0 - (ka)/d (general solution)
//
//Proof:
//      First we need to judge ax+by=c have solution or not because not all the diophantine eqn have solution
//      Assume that d = gcd(a,b)
//      so since d is the gcd of a and b,we have d|a &&  d|b
//      thus from the nature we can know d|(ax+by) which is d|c,so if d|c is not establish then we can conclude that
//      ax+by=c have no solution
//      Now assume that d|c,then
//      From the euclideon algorithm generalized we have sa+tb=d,then
//      sa+tb=d
//      sac+tbc=cd
//      a(sc/d)+b(tc/d)=c (ax+by=c)
//      So obviously x0=sc/d and y0=tc/d is a solution of ax+by=c and we can generalized this,
//      a(sc/d)+b(tc/d)=c
//      a(sc/d)+k(ab/d)-k(ab/d)+b(tc/d)=c (d|ab since d|a and d|b)
//      a(sc/d + kb/d)+b(tc/d - ka/d)=c
//      a(x0 + kb/d) + b(yo - ka/d)=c;
//      Thus general solution x=x0+(kb/d),y=yo-(ka/d)
//
//*****
//
//Nature 6
//Modulus properties
//(a+b)mod n = (a mod n + b mod n) mod n
//(a-b)mod n = (a mod n - b mod n) mod n
//(ab) mod n = (a mod n * b mod n) mod n
//
//This three properties is very important to increase your program efficacy and very eazy to prove,so you can try to 
//prove by yourself!
//
//Here is some example 
//      Ex:Find 10^100000 mod 3
//      Obviously if you run out 10^100000,no matter you use any programming language,definitely no variable can 
//      store this number!So the modulus is very important here,we only care the mod result so we no need to run out
//      the number,let take a look for the below equation
//      10 mod 3 = 1
//      from the properties ab mod n =(a mod n * b mod n) mod n
//      10 mod 3 = 1 10 mod 3 = 1
//      therefore
//      10*10 mod 3 = 1*1 mod 3
//      10^2 mod 3 = 1
//      So the answer for 10^100000 mod 3 is equal to 1^1000000 which is 1.
//      1000 digit number % 1234567
//
//*****
//
//Nature 7
//Expect 1 have only one factor,other nature number will have at least two factor(prime/composite)
//Prime number will have only two factor(1 and itself)
//Composite number will have more than two(>=2)
//
//*****
//
//Nature 8
//Inverse element under modulus
//Two type of inverse element:1)addition inverse element
//                            2)multiplication inverse element
//
//Addition inverse element
//defination:if a+b mod n = 0 then a and b are the inverse element of each other
//Proof:Every number under any modulus have inverse element
//
//      Assume that b=n-a,then
//      a+b mod n = a+n-a mod n
//                = n mod n
//                = 0
//      Proved
//      
//Multiplication inverse element
//defination:if ab mod n = 1 then a and b are the multiplication inverse element of each other
//Proof:Only gcd(n,a)=1 then ab mod n = 1 will establish
//      
//      We gonna prove from two perspective,
//      Assume that when gcd(n,a)=1,then since we know any pair of (a,b) will exist a pair of (s,t) such that sa+tb=d
//      sn+ta=1
//      (sn+ta)mod n = 1 mod n
//      ta mod n = 1
//      Therefor if b=t then,ab mod n = 1 ,proved
//
//      Now assume that when gcd(n,a)>1,let gcd(n,a) be d,then we know d|n and d|a,so we can write down the equation
//      n=k1*d and a=k2*d
//      and assume that ab mod n = r,then
//      ab=n*m+r(m is a coefficient)
//      k2*d*b=k1*d*m+r
//      r=d(k2*b-k1*m)
//      and since d>1 which mean d at least 2,and k2*b-k1*m is an integer which mean it can be ...,-2,-1,0,1,2,...
//      we can easily found that 2*any integer must not be 1,so gcd(n,a)!=1 will definitely cannot form any inverse
//      element
//                          

