#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define UINT32 unsigned int

typedef struct{
	char* number; // still just a pointer to the START of the number, to get the whole number you have to use ANOTHER pointer to go through the whole list.
	UINT32 digits; 
	char* end; // this stores what the address of the ending digit of the number is
} num;

void init(num* addressNum){
	addressNum->number = malloc(2);
	(addressNum->number[0]) = '0';
	(addressNum->number[1]) = '\0';

	addressNum->digits = 1;
	addressNum->end = &(addressNum->number[0]);
}

void printNum(num Num){
	char* ptr = &(Num.number[0]);
	
	printf("%c",*ptr);

	while (*ptr++ != '\0') { printf("%c",*ptr); }
}

void printNumDebug(num Num){
	printf("number = ");
	printNum(Num);
	printf("\ndigits = %u", Num.digits);
	printf("\nstart pointer = %p",Num.number);
	printf("\nvalue at start pointer = %c",*Num.number);
	printf("\nend pointer = %p",Num.end);
	printf("\nvalue at end pointer = %c\n",*Num.end);
}

UINT32 Strlen(char* str){
	char* ptr = str;
	UINT32 len = 0;

	while (*ptr++ != '\0') { len++; }
	return len;
}

bool isNum(char* val){
	char* ptr = val;
	printf("\nval = %p",val);


	if ( (int) *ptr > 57 || (int) *ptr < 48) { return false; }

	while ( *ptr++ != '\0') {
		if (((int) *ptr > 57 || (int) *ptr < 48) && *ptr != '\0') { return false; }
	}

	return true;
}

void setNumVal(num* numPtr,char* value){
	numPtr->number = realloc(numPtr->number,Strlen(value) + 1);
	numPtr->digits = Strlen(value);
	
	char* stringPtr = numPtr->number;

	for (UINT32 i = 0; i < numPtr->digits; i++){
		*(stringPtr+i) = *(value + i);
	}
	*(stringPtr+numPtr->digits) = '\0';

	numPtr->end = numPtr->number + numPtr->digits - 1;
}

bool sanityCheck(num* number){
	UINT32 len = 0;

	char* ptrnum = number->number;

	while (*ptrnum++ != '\0') { len++; }

	if (len != number->digits) { return false; }

	if (number-> end != (number->number + number->digits - 1)) { return false; }

	return true;
}

void leftPad(char** str, char pad, UINT32 n,bool guard){
	if (n == 0) { return; }
	if ((int) pad < 32 && guard) { printf("\ntriggered check for printability\n"); return; }

	char* strcp = malloc(Strlen(*str) + 1);
	strcpy(strcp,*str);
	*str = malloc(Strlen(*str) + 1);

	char* padding = malloc(n + Strlen(*str) + 1);

	const UINT32 len = Strlen(*str);

	for (UINT32 i = 0; i < n; i++){
		*(padding + i) = pad;
	}
	
	*(padding + 1 + len + n) = '\0'; // have to manually set the null terminator here >.<

	*str = realloc(*str,n + len + 1);

	strcat(padding,strcp);
	strcpy(*str,padding);	
	free(padding);
	free(strcp);
}

num addNums(num NOne, num NTwo){
	if (NOne.digits > NTwo.digits){
		NTwo.digits = NOne.digits;
		NTwo.number = realloc(NTwo.number,NTwo.digits + 1);
	}
}

int main(){
	num testNum;
	init(&testNum);
	return 0;
}
