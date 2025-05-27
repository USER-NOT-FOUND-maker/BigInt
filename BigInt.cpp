#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <stdbool.h>

using namespace std;

#define SIZEOFINT 4

// we WILL be using little endian

typedef struct{
        unsigned int *ArrOfInts;
        unsigned long long NumberOfDigits;
        string representation;
} BigInt;

char IntToDigt(int digit){
        return ((char) digit) + 48;
}

string IntToString(unsigned int number){

}

/*
string DisplayIntArr(int arr[]){
        string Display = "[";

        const SIZEOFARR = sizeof(arr);

        for (size_t i = 0; i < SIZEOFARR; i++){
                Display.append()
        }
}
*/
void CreateBigint(BigInt* NumberAddress){
        NumberAddress->ArrOfInts = (unsigned int *) malloc(SIZEOFINT);
        NumberAddress->NumberOfDigits = 1;
        NumberAddress->representation = "0";
        NumberAddress->ArrOfInts[0] = 0;
}

void PrintBigintInfo(BigInt* NumberAddress){

        cout << "IntegerArrays (pointer) = " << NumberAddress->ArrOfInts << "\n\nNumberOfDigits = " << NumberAddress->NumberOfDigits << "\n\nREPRESENTATION = " << NumberAddress->representation << endl;
}

int main(){
        BigInt TestNum;
        CreateBigint(&TestNum);
        
        cout << "DEBUG INFO OF TESTNUM\n------------------------\n\n";
        PrintBigintInfo(&TestNum);
        
        cout << "string of 213 = " << IntToString((unsigned int) 213) << endl; 

        return 69;
}
