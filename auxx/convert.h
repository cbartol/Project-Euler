#ifndef __CONVERT_H__
#define __CONVERT_H__

#include <vector>
#include <list>
#include "extra_math.h"
#include <algorithm>

std::list<int> *int_to_list(int num){
	std::list<int> *lst = new std::list<int>();
	int temp, i, pow_10;
	int n = num;
	for(i=0;n > 0;i++, n /= 10);
	for(n = num ; i > 0 ; i--){
		pow_10 = s_pow(10, i-1);
		temp = n / pow_10;
		n -= temp * pow_10;
		lst->push_back(temp);
	}
	return lst;
}

std::vector<int> *int_to_vector(int num){
	std::vector<int> *vect = new std::vector<int>();
	int temp, i, pow_10;
	int n = num;
	for(i=0;n > 0;i++, n /= 10);
	for(n = num ; i > 0 ; i--){
		pow_10 = s_pow(10, i-1);
		temp = n / pow_10;
		n -= temp * pow_10;
		vect->push_back(temp);
	}
	return vect;
}

int list_to_int(std::list<int> *lst){
	int num;
	int i;
	std::list<int>::reverse_iterator it;
	for(num = 0, it = lst->rbegin(), i = 1; it != lst->rend() ; it++, i *= 10){
		num += (*it) * i;
	}
	return num;
}

int vector_to_int(std::vector<int> *vect){
	int num;
	int i;
	std::vector<int>::reverse_iterator it;
	for(num = 0, it = vect->rbegin(), i = 1; it != vect->rend() ; it++, i *= 10){
		num += (*it) * i;
	}
	return num;
}
template<class T>
std::vector<T> *to_binary(T i){
	typename std::vector<T> * vect = new std::vector<T>();
	while( i > 0 )
	{
		(i & 0x1) ? vect->push_back(1) : vect->push_back(0); 
		i >>= 1;
	}
	reverse(vect->begin(), vect->end());
	return vect;
}
#endif
