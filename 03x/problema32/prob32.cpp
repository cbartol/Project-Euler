/*
 *	We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
 *
 *	The product 7254 is unusual, as the identity, 39 x 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
 *
 *	Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
 *
 *	HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
 */
 
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#define N_NUMS 9

std::list<std::vector<int> > *make_permutations(void);
void print_permutations(std::list<std::vector<int> > *permut);
static int sum;
void plus(int n){
	sum += n;
}

int main(){
	std::list<std::vector<int> > *permut;
	std::list<int> pandigital;
	permut = make_permutations();

	std::list<std::vector<int> >::iterator it;
	for(it = permut->begin() ;it != permut->end() ; it++){
		if((*it)[0] * (((*it)[1]*1000) + ((*it)[2]*100) + ((*it)[3]*10) + ((*it)[4])) == (((*it)[5]*1000) + ((*it)[6]*100) + ((*it)[7]*10) + ((*it)[8])))
			pandigital.push_back((((*it)[5]*1000) + ((*it)[6]*100) + ((*it)[7]*10) + ((*it)[8])));
		if((((*it)[0]*10) + ((*it)[1]))* (((*it)[2]*100) + ((*it)[3]*10) + ((*it)[4])) == (((*it)[5]*1000) + ((*it)[6]*100) + ((*it)[7]*10) + ((*it)[8])))
			pandigital.push_back((((*it)[5]*1000) + ((*it)[6]*100) + ((*it)[7]*10) + ((*it)[8])));
	}
	pandigital.sort();
	pandigital.unique();
	sum = 0;
	for_each(pandigital.begin(), pandigital.end(), plus);
	std::cout << "Answer: " << sum << std::endl;
	delete permut;
	return 0;
}




void print_permutations(std::list<std::vector<int> > *permut){
	std::list<std::vector<int> >::iterator it1;
	for(it1 = permut->begin() ;it1 != permut->end() ; it1++){
		std::vector<int>::iterator it2;
		for(it2 = (*it1).begin() ; it2 != (*it1).end(); it2++){
			std::cout << (*it2);
		}
		std::cout << std::endl;
	}
}

std::list<std::vector<int> > * make_permutations(void){
	int i, j, k, l;
	std::list<std::vector<int> > *permut = new std::list<std::vector<int> >();
	std::list<std::list<int> > permutations;
	std::list<std::list<int> > temp1;
	std::list<std::list<int> > temp2;
	std::list<int> base;
	base.push_back(1);
	permutations.push_front(base);
	for(i = 1 ; i < N_NUMS  ; i++){
		temp1 = permutations;
		permutations.clear();
		for(j=i, temp2 = temp1 ; j >= 0 ; j--, temp2 = temp1){
			std::list<std::list<int> >::iterator it;
			for(it = temp2.begin() ; it != temp2.end() ; it++){
				std::list<int>::iterator it2;
				for(k = j, it2 = (*it).begin() ; k >= 0 ; it2++, k--);
				(*it).insert(it2, i+1);
			}
			permutations.merge(temp2);
		}
		permutations.sort();
	}
	std::list<std::list<int> >::iterator it;
	for(it = permutations.begin() ; it != permutations.end() ; it++){
		permut->push_back((std::vector<int>((*it).begin(), (*it).end())));
	}
	return permut;
}
