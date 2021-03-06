/*
 *	Pentagonal numbers are generated by the formula, Pn=n(3n1)/2. The first ten pentagonal numbers are:
 *
 *	1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...
 *
 *	It can be seen that P4 + P7 = 22 + 70 = 92 = P8. However, their difference, 70 - 22 = 48, is not pentagonal.
 *
 *	Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference is pentagonal and D = |Pk - Pj| is minimised; what is the value of D?
 */

#include <iostream>
#include <cmath>

int formula(int n);
bool isTermOfSeq(int t);

int main(){
	int n, m;
	for(n = 1 ; true ; n++){
		for(m = 1 ; m < n ; m++){
			if( isTermOfSeq(formula(n) - formula(m)) && isTermOfSeq(formula(n) + formula(m))){
				std::cout << "Answer: " << (formula(n) - formula(m)) << std::endl;
				return 0;
			}
		}
	}
}

int formula(int n){
	return n*(3*n-1)/2;
}
bool isTermOfSeq(int t){
	double n1;
	n1 = (1 + sqrt(1+24*t))/6;
	return (n1 == floor(n1));
}
