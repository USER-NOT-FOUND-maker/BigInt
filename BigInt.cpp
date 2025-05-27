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
	if (N == 0) { return ""; }

	string Result;
	for (unsigned long long i = 0; i < N; i++){
		Result = Result + Character;
	}
	return Result;
}

string LeftPad(string str, unsigned long long n, char c){
        string AddedContent = ConstructNString(n - str.size(),c);

        AddedContent.append(str);
        return AddedContent;
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
		Result = ConstructNString(LenNumber1+1,'0');
	}
	else if (LenNumber1 > LenNumber2){
		Result = ConstructNString(LenNumber1+1,'0');
	}
	else{
		Result = ConstructNString(LenNumber2+1,'0');
	}

        unsigned long long LenResult = Result.size();

        int carry = 0;
        int sum;

        string ReversedNumber1 = ReverseString(Number1.val);
        string ReversedNumber2 = ReverseString(Number2.val);

        cout << "ReversedNumber1 before padding == " << ReversedNumber1 << " ReversedNumber2 before padding == " << ReversedNumber2 << endl;

        ReversedNumber1 = LeftPad(ReversedNumber1,LenResult,'0');
        ReversedNumber2 = LeftPad(ReversedNumber2,LenResult,'0');

        cout << "ReversedNumber1 == " << ReversedNumber1 << " ReversedNumber2 = " << ReversedNumber2 << endl << "Result = " << Result << endl;

        int DigitOne;
        int DigitTwo;

        for (unsigned long long digit = 0; digit < LenResult; digit++){
                DigitOne = (DigitToInt(ReversedNumber1[digit]));
                DigitTwo = (DigitToInt(ReversedNumber2[digit]));
                

        }


        BigNum Res;
        Res.val = ReverseString(Result);

        return Res;
}

void PrintBigNum(BigNum Number){
	cout << Number.val;
}


int main(){
        BigNum TestNum1;
        BigNum TestNum2;

        InitNum(&TestNum1,"10900");
        InitNum(&TestNum2,"1040000");

        BigNum x = AddNums(TestNum1,TestNum2);
                
        cout << "x = " << x.val << endl;

	return 1;
}
