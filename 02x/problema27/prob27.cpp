/*
 *	Euler published the remarkable quadratic formula:
 *
 *	n² + n + 41
 *
 *	It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.
 *
 *	Using computers, the incredible formula  n² - 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, -79 and 1601, is -126479.
 *
 *	Considering quadratics of the form:
 *
 *	n² + an + b, where |a| < 1000 and |b| < 1000
 *
 *	where |n| is the modulus/absolute value of n
 *	e.g. |11| = 11 and |4| = 4
 *	Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
 */
 
#include <iostream>
#include <list>
#include "prime.h"

template <class T>
void print_vector(std::list<T> *vect);
int n_primos(int a, int b);

struct maximo{
	int a;
	int b;
	int n;
};

int main(){
	std::list<int> tbl_primos;
	std::list<int>::iterator itA;
	std::list<int>::iterator itB;
	int k, i, j;
	for(k = nextPrime(true); k < 1000 ; k = nextPrime(false)){
		tbl_primos.push_back(k);
		tbl_primos.push_front((-1)*k);
	}
//	print_vector(&tbl_primos);
	struct maximo max;
	max.a = 0; max.b = 0; max.n = 0;
	k=0;
	for(itA = tbl_primos.begin() ; itA != tbl_primos.end() ; itA++){
		for(itB = tbl_primos.begin() ; itB != tbl_primos.end() ; itB++){
			k = n_primos(*itA, *itB);
			if(k >= max.n){
				max.a = *itA; max.b = *itB; max.n = k;
			}
		}
	}
	std::cout << "a=" << max.a << " b=" << max.b << " n=" << max.n << std::endl;
	std::cout << "Answer: " << (max.a * max.b) << std::endl;
	return 0;
}

template <class T>
void print_vector(std::list<T> *vect){
	typename std::list<T>::iterator it;
	for(it = vect->begin() ; it != vect->end(); it++){
		std::cout << (*it) << " ";
	}
	std::cout << std::endl <<"size: "<<vect->size() << std::endl;
}

bool geraPrimo(int a, int b, int n){
	return isPrime((n*n) + (a*n) + b);
}

int n_primos(int a, int b){
	int n = 0;
	while(geraPrimo(a, b, n)){
		n++;
	}
	return n;
}
