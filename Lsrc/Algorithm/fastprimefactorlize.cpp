//O(nlogn) built table and O(logn) prime factorlize
//     minp[1]=1;
//     forn(i,2,mxN){
//         if(!minp[i]){
//             pri.emp(i);
//             minp[i]=i;
//         }
//         for(auto&v:pri){
//             if(v>minp[i] || v*i>=mxN) break;
//             minp[v*i]=v;
//         }
//     }
