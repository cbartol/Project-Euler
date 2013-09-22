/*
 *	A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
 *
 *	1/2	= 	0.5
 *	1/3	= 	0.(3)
 *	1/4	= 	0.25
 *	1/5	= 	0.2
 *	1/6	= 	0.1(6)
 *	1/7	= 	0.(142857)
 *	1/8	= 	0.125
 *	1/9	= 	0.(1)
 *	1/10	= 	0.1
 *	Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
 *
 *	Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 */
#include <iostream>
#include <algorithm>
#include <list>

std::list<char> *divide(int num1, int num2);
void print_string(std::list<char> *string);

static bool flag;
static int max;

int main(){
	std::list<char> *num;
	int i;
	max = 0;
	for(i = 1 ; i < 1000 ; i++){
		flag = false;
		num = divide(1, i);
//		print_string(num);
		delete num;
	}
	std::cout << std::endl;
	
	
	return 0;
}

std::list<char> *divide(int num1, int num2){
	std::list<char> *res = new std::list<char>();
	std::list<int> restos;
	std::list<int>::iterator it;
	int div = num1/num2;
	int resto = -1;
	int n = 0;
	res->push_back(div + '0');
	res->push_back('.');
	resto = (num1 % num2)*10;
	restos.push_back(resto);
	while(resto != 0){
		div = resto / num2;
		if(div == 0){
			n--;
		}
		res->push_back(div + '0');
		resto = (resto % num2)*10;
		it = std::search_n (restos.begin(), restos.end(), 1, resto);
		if(it == restos.end()){
			n++;
			restos.push_back(resto);
		}
		else{
			flag = true;
			break;
		}
	}
	if(n > max){
		max = n;
		std::cout << std::endl;
		std::cout << num2 << " division: "; print_string(res); std::cout << " n: " << n << std::endl;
	}
	return res;
}

void print_string(std::list<char> *string){
	std::list<char>::iterator it;
	for(it = string->begin() ; it != string->end(); it++){
		std::cout << (*it);
	}
//	std::cout << std::endl;
}
