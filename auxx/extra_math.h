#ifndef __EXTRA_MATH_H__
#define __EXTRA_MATH_H__

#include <algorithm>
#include <vector>

std::vector<int> *my_pow(int n, int exp, int size){
	std::vector<int> *numero = new std::vector<int>();
	int i, z;
	for(i = 0 ; i <size ; i++){
		numero->push_back(0);
	}
	(*numero)[0] = 1;
	for(z = 0; z <exp ; z++){
		for(i = 0; i <size ; i++){
			while((*numero)[i] >= 10){
				(*numero)[i] -= 10;
				(*numero)[i+1] += 1;
			}
			(*numero)[i] *= n;
		}
	}
	for(i = 0; i <size ; i++){
		while((*numero)[i] >= 10){
			(*numero)[i] -= 10;
			(*numero)[i+1] += 1;
		}
	}
	return numero;	
}

int s_pow(int num, int exp){
	int n = num;
	int e = exp;
	if(exp == 0)
		return 1;
	for(e-- ; e > 0 ; e--){
		n *= num;
	}
	return n;
}

int fact_1_to_9(int num){
	switch(num){
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 6;
		case 4:
			return 24;
		case 5:
			return 120;
		case 6:
			return 720;
		case 7:
			return 5040;
		case 8:
			return 40320;
		case 9:
			return 362880;
		default:
			int i, mult;
			for(mult=1, i=1 ; i <= num ; mult*=i, i++);
			return mult;
	}
}

template<class T>
bool isPalindromic(std::vector<T> *p){
	int i;
	int j;
	for(i=0, j=p->size()-1; i < j ; i++, j--){
		if(p->at(i) != p->at(j))
			return false;
	}
	return true;
}

bool isPandigital(std::vector<int> *p){
	std::vector<int> temp;
	std::vector<int>::iterator it;
	temp = *p;
	sort(temp.begin(), temp.end());
	it = unique(temp.begin(), temp.end());
	temp.resize( it - temp.begin() );
	if(p->size() == temp.size())
		return true;
	return false;	
}

#endif
