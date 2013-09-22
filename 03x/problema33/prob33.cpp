/*
 *	The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
 *
 *	We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *
 *	There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
 *
 *	If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

//bool isDivisible(int num, int den);
bool isTrivial(int num, int den);

int main(){
	int a, b;
	for(b = 10 ; b < 100 ; b++){
		for(a = 10 ; a < b ; a++){
			isTrivial(a, b);
		}
	}
	return 0;
}

bool isDivisible(int num, int den){
	int i;
	int n;
	(num > den) ? n = sqrt(den) : n = sqrt(num);
	
	for(i = 2; i <= n ; i++){
		if(num % i == 0 && den % i == 0)
			return true;
	}
	return false;
}

bool isTrivial(int num, int den){
	std::vector<int> n;
	std::vector<int> d;
	int temp;
	temp = num/10;
	n.push_back(temp);
	n.push_back(num - (temp*10));
	temp = den/10;
	d.push_back(temp);
	d.push_back(den - (temp*10));
	if(n[0] == d[0]){
		if(d[1] != 0 && n[1] / d[1] == num / den)
			return true;
	}
	if(n[0] == d[1]){
		if(d[0] != 0 && n[1] / d[0] == num / den)
			return true;
	}
	if(n[1] == d[0]){
		if(d[1] != 0 && n[0] / d[1] == num / den)
			return true;	
	}
	if(n[1] == d[1]){
		if(d[0] != 0 && n[0] / d[0] == num / den)
			return true;	
	}
	std::cout << "num: " << n[0] << n[1] << " den: " << d[0] << d[1] << std::endl;
	return false;
}
