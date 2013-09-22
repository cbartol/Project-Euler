#include <stdlib.h>
#include <string.h>

static struct number_table{
	char *one;
	char *two;
	char *three;
	char *four;
	char *five;
	char *six;
	char *seven;
	char *eight;
	char *nine;
	char *ten;
	char *eleven;
	char *twelve;
	
	char *fif;
	char *foor;
	char *thir;
	char *twen;
	char *eigh;
	
	char *teen;
	char *ty;
	
	char *ande;
	char *hundred;
} numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "fif","for",
"thir", "twen", "eigh", "teen", "ty", "and", "hundred"};
/*
numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "fif","for",
"thir", "twen", "eigh", "teen ", "ty ", "and ", " hundred "};
*/
char* numberToWord(int i){
	char *word = (char *) malloc(sizeof(char)*30);
	int flag = 0;
	if(i == 1000){
		strcpy(word, "onethousand");
		return word;
	}
	word[0] = '\0';
	if(i >= 100){
		if(i >= 900){strcpy(word, numbers.nine); i -= 900;}
		else if(i >= 800){strcpy(word, numbers.eight); i -= 800;}
		else if(i >= 700){strcpy(word, numbers.seven); i -= 700;}
		else if(i >= 600){strcpy(word, numbers.six); i -= 600;}
		else if(i >= 500){strcpy(word, numbers.five); i -= 500;}
		else if(i >= 400){strcpy(word, numbers.four); i -= 400;}
		else if(i >= 300){strcpy(word, numbers.three); i -= 300;}
		else if(i >= 200){strcpy(word, numbers.two); i -= 200;}
		else {strcpy(word, numbers.one); i -= 100;}
		strcat(word, numbers.hundred);
		flag = 1;
	}
	/******************************************/
	if(i > 0 && flag){
		strcat(word, numbers.ande);
	}
	/*****************************************/
	if(i >= 20){
		if(i >= 90){strcat(word, numbers.nine); i -= 90;}
		else if(i >= 80){strcat(word, numbers.eigh); i -= 80;}
		else if(i >= 70){strcat(word, numbers.seven); i -= 70;}
		else if(i >= 60){strcat(word, numbers.six); i -= 60;}
		else if(i >= 50){strcat(word, numbers.fif); i -= 50;}
		else if(i >= 40){strcat(word, numbers.foor); i -= 40;}
		else if(i >= 30){strcat(word, numbers.thir); i -= 30;}
		else {strcat(word, numbers.twen); i -= 20;}
		strcat(word, numbers.ty);
	}
	else{
		if(i > 12){
			if(i == 19){strcat(word, numbers.nine);}
			else if(i == 18){strcat(word, numbers.eigh);}
			else if(i == 17){strcat(word, numbers.seven);}
			else if(i == 16){strcat(word, numbers.six);}
			else if(i == 15){strcat(word, numbers.fif);}
			else if(i == 14){strcat(word, numbers.four);}
			else if(i == 13){strcat(word, numbers.thir);}
			strcat(word, numbers.teen);
		}
		else{
			if(i == 12){strcat(word, numbers.twelve);}
			else if(i == 11){strcat(word, numbers.eleven);}
			else if(i == 10){strcat(word, numbers.ten);}
		}
	}
	if(i < 10){
		if(i == 9){strcat(word, numbers.nine);}
		else if(i == 8){strcat(word, numbers.eight);}
		else if(i == 7){strcat(word, numbers.seven);}
		else if(i == 6){strcat(word, numbers.six);}
		else if(i == 5){strcat(word, numbers.five);}
		else if(i == 4){strcat(word, numbers.four);}
		else if(i == 3){strcat(word, numbers.three);}
		else if(i == 2){strcat(word, numbers.two);}
		else if(i == 1){strcat(word, numbers.one);}
	}
	return word;
}
