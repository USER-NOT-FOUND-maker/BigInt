#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <stdbool.h>

using namespace std;

#define SIZEOFINT 4
#define MAXINTSIZE 4294967295

// we WILL be using little endian

typedef struct{
        unsigned int *ArrOfInts;
        unsigned long long NumberOfDigits;
        string representation;
} BigInt;

char IntToDigt(int digit){
        return ((char) digit) + 48;
}

void DisplayIntArr(unsigned int arr[], unsigned long long length){
        cout << "[";
        for (unsigned long long i = 0; i < length; i++){
                cout << arr[i];
                if (i < (length - 1)){
                        cout << ", ";
                }
        }
        cout << "]" << endl;
}

bool IsOverflow(unsigned int Num1, unsigned int Num2, char op){
        if ( op != '+' && op != '-') { cout << "entered op was " << op << endl << endl; throw runtime_error("fucking retard put in a valid op next time (+ or -)"); }

        unsigned int Result;

        if (op == '+') { Result = Num1 + Num2; return Result < Num1; }
        else { Result = Num1 - Num2; return Result > Num1; }
}

void CreateBigint(BigInt* NumberAddress){
        NumberAddress->ArrOfInts = (unsigned int *) malloc(SIZEOFINT);
        NumberAddress->NumberOfDigits = 1;
        NumberAddress->representation = "0";
        NumberAddress->ArrOfInts[0] = 0;
}

void SetBigIntVal(BigInt * PointerToNum, unsigned int Num){
        free(PointerToNum->ArrOfInts);
        PointerToNum->NumberOfDigits = 1;
        PointerToNum->ArrOfInts = (unsigned int*) malloc(SIZEOFINT);
        PointerToNum->ArrOfInts[0] = Num;
}

int CmpNums(BigInt NumberOne,BigInt NumberTwo){
        if (NumberOne.NumberOfDigits > NumberTwo.NumberOfDigits) { return -1; }
        else if (NumberOne.NumberOfDigits < NumberTwo.NumberOfDigits) { return 1; }

        const unsigned long long NumberOfDigits = NumberOne.NumberOfDigits - 1;

        if (NumberOne.ArrOfInts[NumberOfDigits] == NumberTwo.ArrOfInts[NumberOfDigits]) { return 0; }
        else if (NumberOne.ArrOfInts[NumberOfDigits] > NumberTwo.ArrOfInts[NumberOfDigits]) { return -1; }
        else { return 1; }
}

BigInt AddNums(BigInt NumberOne,BigInt NumberTwo){
        BigInt Result;
        CreateBigint(&Result);

        unsigned long long ResultSize = SIZEOFINT;

        unsigned int *PtrNum1, *PtrNum2, *PtrResArr;

        PtrNum1 = &NumberOne.ArrOfInts[0];
        PtrNum2 = &NumberTwo.ArrOfInts[0];
        PtrResArr = &Result.ArrOfInts[0];

        while (true){
                bool OverFlowResult = IsOverflow(*PtrNum1,*PtrNum2,'+');

                if (OverFlowResult){
                        unsigned int* TempResultArr = (unsigned int*) realloc(Result.ArrOfInts,(ResultSize * SIZEOFINT) + SIZEOFINT);

                        if (TempResultArr == NULL) { throw runtime_error("something failed in memory allocation and we couldnt continue the program"); }

                        Result.ArrOfInts = TempResultArr;
                }
        }

        return Result;
}

void PrintBigintInfo(BigInt* NumberAddress){
        cout << "Integer array = ";
        DisplayIntArr(NumberAddress->ArrOfInts,NumberAddress->NumberOfDigits);
        cout << "\nInteger array pointer = " << NumberAddress->ArrOfInts;
        cout << "\n\nNumberOfDigits = " << NumberAddress->NumberOfDigits << "\n\nREPRESENTATION = " << NumberAddress->representation << endl << endl;
}

int main(){
        cout << "DISCLAIMER, USING 'SetBigIntVal' ONLY WORKS WHEN YOU PASS IN AN UNSIGNED INTEGER THAT FITS IN AN UNSIGNED INTEGER (wont error if it doesn't fit, will just overflow)" << endl << endl << endl;

        BigInt TestNum;
        BigInt TestNum2;
        CreateBigint(&TestNum);
        CreateBigint(&TestNum2);

        SetBigIntVal(&TestNum,0-1);

        SetBigIntVal(&TestNum2,4250);

        AddNums(TestNum,TestNum2);

        return 69;
}
