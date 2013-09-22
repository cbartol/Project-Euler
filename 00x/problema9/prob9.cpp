/*
 *	A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
 *
 *	a^2 + b^2 = c^2
 *	For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 *	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *	Find the product abc.
 */
#include <stdio.h>
#include <math.h>

int main(){
	double a, b, c;
	double temp;
	int flag = 0;
	for(a = 1 ; 1 ; a++){
		for(b = a+1 ; b < 1000 ; b++ ){
			if(modf(sqrt(a*a+b*b), &c) == 0){
				if(a+b+c == 1000){
					flag = 1;
					break;
				}
			}
		}
		if(flag)
			break;
	}
	printf("a: %.0f, b: %.0f, c: %.0f\nabc: %.0f\n", a, b, c, a*b*c);
	return 0;
}
