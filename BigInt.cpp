#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string ReverseString(string str){
        const unsigned long long SizeOfStr = str.size();

        unsigned long long StartIndex = 0;
        unsigned long long EndIndex = SizeOfStr - 1;

        while (StartIndex < EndIndex){
                char temp = str[StartIndex];
                str[StartIndex] = str[EndIndex];
                str[EndIndex] = temp;

                StartIndex++;
                EndIndex--;
        }

        return str;
}

int DigitToInt(char Digit){
        return ((int) Digit) - 48;
}

char IntToDigit(int Integer){
        return ((char) Integer) + 48;
}

string ConstructNString(unsigned long long N, char Character){
	if (N == 0) { return NULL; }

	string Result;
	for (unsigned long long i = 0; i < N; i++){
		Result = Result + Character;
	}
	return Result;
}

typedef struct{
	string val;
} BigNum;

void InitNum(BigNum* PtrToNumber, string Value){
	PtrToNumber->val = Value;
}

BigNum AddNums(BigNum Number1, BigNum Number2){
	const unsigned long long LenNumber1 = Number1.val.size();
	const unsigned long long LenNumber2 = Number2.val.size();
	string Result;
        

	if (LenNumber1 == LenNumber2){
		Result = ConstructNString(LenNumber1,'0');
	}
	else if (LenNumber1 > LenNumber2){
		Result = ConstructNString(LenNumber1,'0');
	}
	else{
		Result = ConstructNString(LenNumber2,'0');
	}

        unsigned long long LenResult = Result.size();

        int carry = 0;
        int sum;

        string ReversedNumber1 = ReverseString(Number1.val);
        string ReversedNumber2 = ReverseString(Number2.val);
        
        return Number1;
}

void PrintBigNum(BigNum Number){
	cout << Number.val;
}


int main(){
        BigNum TestNum1;
        BigNum TestNum2;

        InitNum(&TestNum1,"10000");
        InitNum(&TestNum2,"10000");

        BigNum x = AddNums(TestNum1,TestNum2);
        
	return 1;
}
