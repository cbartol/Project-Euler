/*
 *	A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 *
 *	012   021   102   120   201   210
 *
 *	What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#include <iostream>
#include <list>
#include <vector>

#define MAX_PERMUT (10*9*8*7*6*5*4*3*2*1)
#define POSITION 1000000
#define N_NUMS 10


int main(){
	int i;
	int j;
	int k;
	int l;
	std::list<std::list<int> > permutations;
	std::list<std::list<int> > temp1;
	std::list<std::list<int> > temp2;
	std::list<int> base;
	base.push_back(0);
	permutations.push_front(base);
	for(i = 1 ; i < N_NUMS  ; i++){
		temp1 = permutations;
		permutations.clear();
		for(j=i, temp2 = temp1 ; j >= 0 ; j--, temp2 = temp1){
			std::list<std::list<int> >::iterator it;
			for(it = temp2.begin() ; it != temp2.end() ; it++){
				std::list<int>::iterator it2;
				for(k = j, it2 = (*it).begin() ; k >= 0 ; it2++, k--);
				(*it).insert(it2, i);
			}
			
			permutations.merge(temp2);
		}
		permutations.sort();
	}

//prints-----------------------------------------	
	std::list<std::list<int> >::iterator itt;
	for(j = 1, itt = permutations.begin() ;/*itt != permutations.end()*/ j != POSITION; itt++, j++){
/*		std::list<int>::iterator itt2;
		for(itt2 = (*itt).begin() ; itt2 != (*itt).end(); itt2++){
			std::cout << (*itt2);
		}
		std::cout << std::endl;*/
	}
//	std::cout << permutations.size() << std::endl;
	std::cout << "Answer: ";
	std::list<int>::iterator itt2;
	for(itt2 = (*itt).begin() ; itt2 != (*itt).end(); itt2++){
		std::cout << (*itt2);
	}
	std::cout << std::endl;
	return 0;
}




/*
int find(std::vector<int> v, int n){
	int i;
	for(i = 0; i < v.size() ; i++){
		if(v[i] == n)
			return i;
	}
	return -1;
}

bool compare_vectors (const std::vector<int> first, const std::vector<int> second){
	unsigned int i;
	for(i = 0 ; i < 10 ; i++){
		if(first[i] < second[i])
			return true;
		if(first[i] > second[i])
			return false;
	}
	return false;
}*/
