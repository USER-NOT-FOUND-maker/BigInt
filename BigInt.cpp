#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

using namespace std;

string ReverseString(string str){
        const unsigned long long SizeOfStr = sizeof(str);

        char * StartPtr = &str[0];
        char * EndPtr = StartPtr + (SizeOfStr) - 1;

        cout << "Start ptr == " << StartPtr << endl << "EndPtr == " << EndPtr << endl;

        return "I FUCKING HATE CPP WITH ALL MY HEART, love you lot tho";
}

int DigitToInt(char Digit){
        return ((int) Digit) - 48;
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
	const unsigned long long LenNumber1 = StrLen(Number1.val);
	const unsigned long long LenNumber2 = StrLen(Number2.val);
	string Result;
        
	printf("\n\nLenNumber1 = %llu\n\nLenNumber2 = %llu\n\n",LenNumber1,LenNumber2);

	if (LenNumber1 == LenNumber2){
		cout << "LenNumber1 is the same as LenNumber2" << endl;
		Result = ConstructNString(LenNumber1,'0');
	}
	else if (LenNumber1 > LenNumber2){
		cout << "LenNumber1 is bigger than LenNumber2" << endl;
		Result = ConstructNString(LenNumber1,'0');
	}
	else{
		cout << "LenNumber2 is bigger than LenNumber1" << endl;
		Result = ConstructNString(LenNumber2,'0');
	}

        unsigned long long LenResult = StrLen(Result);

        int carry;
        int sum;

        string ReversedNumber1 = ReverseString(Number1.val);
        string ReversedNumber2 = ReverseString(Number2.val);

        cout << "ReversedNumber 1 == " << ReversedNumber1 << endl << "Number1 == " << Number1.val << endl;
        cout << "ReversedNumber 2 == " << ReversedNumber2 << endl << "Number2 == " << Number2.val << endl;


/*
        for (unsigned long long digit = 0; digit < LenResult; digit++){
                int DigitOne = DigitToInt(Number1.val[(LenResult - digit) -1]);
                int DigitTwo = DigitToInt(Number2.val[(LenResult - digit) -1]);
                sum = DigitOne + DigitTwo;

                if (sum > 9){
                        carry = 1;
                        sum = sum - 10;
                }

                cout << "digit 1: " << int(Number1.val[(LenResult - digit - 1)]) << endl;
                cout << "digit 2: " << int(Number2.val[(LenResult - digit - 1)]) << endl;
                cout << "sum = " << sum << endl;
                cout << "carry = " << carry << endl;

                Result[(LenResult - digit) - 1] = (char) sum;

                if (carry == 1){
                        Result[(LenResult - digit) - 1] = (char) (DigitToInt(Result[(LenResult - digit) - 1]) + 1);
                        carry = 0;
                }
        }

        cout << "Result is " << Result << endl;

        BigNum Res;
        Res.val = Result;
*/
        BigNum Res;

	return Res;
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
