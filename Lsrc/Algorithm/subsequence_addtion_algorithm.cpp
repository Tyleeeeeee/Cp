//Subsequence addtion algorithm
//if given an array of length n a1,a2,a3...,an,want you to find subsequence with {a1,a2} then you can use subsequence
//addtion algorithm
//In normal operation we can just use times of a1 appear multiply times of a2 appear but in subsequence its may not 
//work because in subsequence order in matter,for example {a1,a2} and {a2,a1} are considered different,so using na1
//multiply na2 is not always correct and there is some other condition when using na1*na2,for example:
//a1 a1 a1 a2 a2 a2 can simply using 3*3 but
//a1 a1 a2 a1 a2 a2 can not using 3*3 the correct answer is 2+3+3=8
//Here is the problem when directly using na1*na2 because obviously we can find that the before the 3rd element we 
//only have 2 a1 and after 3rd element we have 3 a1 at 5th element,so how should we count?by using 2*3?or 3*3?
//Obviously no matter is 2*3 or 3*3 the answer is always wrong because you are undercounting/overcounting,in this
//situation you need subsequence addtion algorithm!
//Subsequence addtion algorithm is simple,the kernel mindset is add the current number of a1 when you meet a2,in
//other word its dynamic to count a1 and add to a2,for example
//a1 a1 a2 a1 a2 a2
//at third element we meet a2 so we add the previous number of times of a1 to answer which is 2 and when meet another
//a2 at 5th element we add the previous number of times of a1 which is 3 to answer and when we meet a2 again ,do the
//same thing because a*b is equal to a+a+a+...+a ]-b times or b+b+b+...+b ]-a times ,so add the times of a1 appear 1
//times is equal to make na1*1,add 2 times equal to na1*2 and so on
