/*
 *	In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
 *
 *	1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 *	It is possible to make £2 in the following way:
 *
 *	1£1 + 150p + 220p + 15p + 12p + 31p
 *	How many different ways can £2 be made using any number of coins?
 */

#include <iostream>

int main(){
	int a, b, c, d, e, f, g, h;
	int times = 0;
	bool flag = true;
	for(a=0; a <= 200 ; a++, flag = true){
		for(b=0; flag && b <= 100 ; b++){
			for(c=0; c <= 40  ; c++){
				for(d=0; d <= 20  ; d++){
					for(e=0; e <= 10  ; e++){
						for(f=0; f <= 4   ; f++){
							for(g=0; g <= 2   ; g++){
								for(h=0; h <= 1   ; h++){
									if(a*1 + b*2 + c*5 + d*10 + e*20 + f*50 + g*100 + h*200 == 200)
										times++;
								}
							}
						}
					}
				}
			}
		}
	}
	std::cout << "Answer: " << times << std::endl;
}
