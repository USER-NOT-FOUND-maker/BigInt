#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define UINT32 unsigned int
#define INTSCIIVAL 48

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

char* reverseString(char* str){
	const UINT32 len = Strlen(str);
	char* strcp = malloc(Strlen(str));
	strcpy(strcp,str);
	
	if (len == 0 || len == 1) { return str; }

	char* start = strcp;
	char* end = start + len - 1;

	char temp;

	while (start < end){
		temp = *start;
		*start = *end;
		*end = temp;
		end--;
		start++;
	}

	return strcp;
}

bool isNum(char* val){
	char* ptr = val;

	if ( (int) *ptr > 57 || (int) *ptr < 48) { return false; }

	while ( *ptr++ != '\0') {
		if (((int) *ptr > 57 || (int) *ptr < 48) && *ptr != '\0') { return false; }
	}

	return true;
}

void setNumVal(num* numPtr,char* value){	
	if (!isNum(value)) { return; }
	if (Strlen(value) == 0) { return; }

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
	
	if (!isNum(number->number)) { return false; }

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

int cmpNums(num NOne, num NTwo){
	if (NOne.digits > NTwo.digits) { return -1; }
	else if (NOne.digits < NTwo.digits) { return 1; }

	for (UINT32 i = 0; i < NTwo.digits; i++){ // this absolutely has to change (to support numbers with more than 2^32 digits, will do once addNums is working
		int codeOne = (int) NOne.number[i];
		int codeTwo = (int) NTwo.number[i];

		if (codeOne > codeTwo){
			return -1;
		}
		else if (codeOne < codeTwo){
			return 1;
		}
	}

	return 0;
}

num addNums(num NOne, num NTwo){

	if (!(sanityCheck(&NOne) && sanityCheck(&NTwo))) { return; }

	if (NOne.digits > NTwo.digits){
		NTwo.digits = NOne.digits;
		NTwo.number = realloc(NTwo.number,NTwo.digits + 1);
		leftPad(&NTwo.number,'0',NTwo.digits - Strlen(NTwo.number),true);
	}
	else if (NOne.digits < NTwo.digits){
		NOne.digits = NTwo.digits;
		NOne.number = realloc(NOne.number,NOne.digits + 1);
		leftPad(&NOne.number,'0',NOne.digits - Strlen(NOne.number),true);
	}
	
	int carry; // stores the number used to carry in addition
	char digitOne; // stores the character digit of the first number
	char digitTwo; // stores the character digit of the second number
	int sum; // stores the result of adding digitOneN and digitTwoN
	int digitOneN; // digitOne but integer
	int digitTwoN; // digitTwo but integer

	char* NOneCP = malloc(NOne.digits);
	char* NTwoCP = malloc(NTwo.digits);
	strcpy(NOneCP,NOne.number);
	strcpy(NTwoCP,NTwo.number);
	NOneCP = reverseString(NOneCP);
	NTwoCP = reverseString(NTwoCP);
	
	const UINT32 len = Strlen(NOneCP);
	char* res = malloc(len + 1); // stores the result of the addition, +1 is needed to account for carries in the final digit addition
	char* resI = res;

	for (UINT32 i = 0; i < len; i++){
		digitOne = NOneCP[i];
		digitTwo = NTwoCP[i];

		digitOneN = (int) digitOne - INTSCIIVAL;
		digitTwoN = (int) digitTwo - INTSCIIVAL;
		
		printf("\ndigitOne = %c\ndigitTwo = %c\ndigitOneN = %d\ndigitTwoN = %d\n",digitOne,digitTwo,digitOneN,digitTwoN);

		sum = digitOneN + digitTwoN;

		if (sum > 9) { sum -= 10; carry = 1; }

		*(resI + i) = (char) (sum + carry + INTSCIIVAL);
		printf("\nresI + i (dereferenced) = %c",*(resI + i));
		printf("\n(char) sum + carry = %c",(char) (sum + carry));
		printf("\nin the loop, res = %s",res);

		carry = 0;
	}
	res = reverseString(res);

	printf("\n%s\n",res);

}

int main(){
	num testNum;
	init(&testNum);
	num testNum2;
	init(&testNum2);
	
	setNumVal(&testNum,"10000");
	setNumVal(&testNum2,"100000000");

	addNums(testNum,testNum2);

	return 0;
}
