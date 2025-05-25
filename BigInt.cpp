#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

unsigned long long StrLen(string s){	
	if (s[0] == '\0') { return 0; } 

	char * PtrToS = &s[0];
	unsigned long long len = 0;
		

	while (*PtrToS != '\0') { PtrToS++; len++; }

	return len;
}

typedef struct{
	string val;
} BigNum;

void InitNum(BigNum* PtrToNumber, string Value){
	printf("\nPtrToNumber = %p\n",PtrToNumber);

	PtrToNumber->val = Value;
	
	printf("PtrToNumber->val == ");
	cout << PtrToNumber->val << endl;
}

BigNum AddNums(BigNum Number1, BigNum Number2){
	BigNum x;

	return x;
}

void PrintBigNum(BigNum Number){
	cout << Number.val;
}


int main(){
	BigNum TestNum;

	return 1;
}
