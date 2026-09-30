//burnside's lemma
//Assume that G is a group and X is the applied set then number of distinct ways is
//1/|G| * (|X^g1| + |X^g2| + ... |X^gn)
//The main reason why its work is in normal if we want to do a circular permutation than we will use the formula
//nCr / n because for example [1,2,3,4],[2,3,4,1],[3,4,1,2],[4,1,2,3] are same so we need to divide it by 4 so why
//we don't just M^N / N is answer right?The answer is no because we found that some of the permutation in M^N is not
//complete.What does it mean?for example,in M^N we will generate [1,2,3,4],[2,3,4,1],[3,4,1,2],[4,1,2,3] right? but
//how about [1,2,1,2],for [1,2,1,2] we will only form [1,2,1,2] and [2,1,2,1] this permutaion only generate 2 times 
//but we divide it by 4 so obviously this is wrong,in other word in M^N some of the permutaion is completely generated
//like permutation [1,2,3,4] but some of the permutation is not completely like [1,2,1,2],in particular [1,2,1,2]
//should generate [1,2,1,2],[2,1,2,1],[1,2,1,2],[2,1,2,1] then we can divide it by N and not all the incompletely
//permutation have equal amount of lack of permutation of ex [1,1,1,1] in M^N [1,1,1,1] will generate 1 times but 
//obviously the complete permutation of [1,1,1,1] is [1,1,1,1],[1,1,1,1],[1,1,1,1],[1,1,1,1] so its need more 3 
//permutation and for our previous example [1,2,1,2] which is only need 2,so now our problem is, for those which are
//not completely we need to generate manually to make it complete so how can we found that?Now we use a new concept
//which is call cyclic group,we observe that when under some operation like turn k times the array will form d(d>1)
//cyclic group and when each cyclic group with same colour the permutation will be undercount ,for example [1,2,1,2]
//and [1,1,1,1] when we turn 1 times then [1,2,1,2] will become [2,1,2,1] which is already count in M^N but [1,1,1,1]
//will become[1,1,1,1] which is not count in M^N so in other word not all operation g will generate new permutation
//its depent on the cyclic group in the array when applied g
