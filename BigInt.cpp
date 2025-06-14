#include <string>
#include <iostream>

using namespace std;

#define uint64 unsigned long long
#define uint32 unsigned int
#define int32 int
#define int64 long long

typedef struct{
        string Number;
        uint64 Digits;
        bool initialised;
} BigInt;

int32 DigitToInt(char Digit) { return ((int) Digit) - 48;}
char IntToDigit(int32 Int) { return ((char) Int) + 48;}


void PrintBigint(BigInt* NumAddress){
        if(!NumAddress->initialised) { throw runtime_error("shouldve thought about that before trying to use an uninitialised number");}
        cout << NumAddress->Number;
}

int32 CmpNums(BigInt Num1, BigInt Num2){
        if(!(Num1.initialised && Num2.initialised)) { throw runtime_error("shouldve thought about that before trying to use an uninitialised number");}

        if (Num1.Digits > Num2.Digits) { return -1; }
        else if (Num2.Digits > Num1.Digits) { return 1; }

        for (uint32 i = 0; i < Num1.Digits; i++){
                if (DigitToInt(Num1.Number[i]) > DigitToInt(Num2.Number[i])) { return -1; }
                else if (DigitToInt(Num2.Number[i]) > DigitToInt(Num1.Number[i])) { return 1; }
        }

        return 0;
}

const char DIGITS[11] = "0123456789";

bool IsInCharray(char arr[],char val){
        const uint64 len = sizeof(arr);

        for (uint64 i = 0; i < len; i++) { if (arr[i] == val){ return true;}}
        return false;
}

void InitBigint(BigInt* NumberAddress){
        NumberAddress->Number = "0";
        NumberAddress->Digits = 0;
        NumberAddress->initialised = true;
}

void SetBigintVal(BigInt* NumberAddress, string NewVal){
        if(!NumberAddress->initialised) { throw runtime_error("shouldve thought about that before trying to use an uninitialised number");}
       
        NumberAddress->Number = NewVal;
        NumberAddress->Digits = NewVal.length();
}

string ConstructNString(char c, uint64 n){
        string str;
        str.resize(n);
        for (uint64 i = 0; i < n; i++){
                str[i] = c;
        }
        return str;
}

string LeftPad(string str, char c, uint64 n){
        if (n < str.length()) { return str; }

        string Padding = ConstructNString(c,n - str.length());

        return Padding + str;
}

string GetSubstring(string s, uint64 start, uint64 end, uint64 step){
        string SubS= "";

        if(start > end && step > 0) { return s; }

        if (start < 0 || start > s.size()) { return s; }

        if (end < 0 || end > s.size()) { return s; }

        for (uint64 i = start; i != end; i += step) { if (i > end && step > 0 || i < end && step < 0){ return SubS; } SubS += s[i]; }

        return SubS;
}

BigInt AddNums(BigInt NumberOne, BigInt NumberTwo){
        const uint64 LenNumberOne = NumberOne.Number.length();
        const uint64 LenNumberTwo = NumberTwo.Number.length();

        string Result;
        uint64 LenRes;

        string CPNumberOne;
        string CPNumberTwo;

        if (LenNumberOne >= LenNumberTwo) { Result = ConstructNString('0',LenNumberOne + 1); LenRes = LenNumberOne + 1; CPNumberTwo = LeftPad(NumberTwo.Number,'0',LenNumberOne); CPNumberOne = NumberOne.Number; }
        else { Result = ConstructNString('0',LenNumberTwo + 1); LenRes = LenNumberTwo + 1; CPNumberOne = LeftPad(NumberOne.Number,'0',LenNumberTwo); CPNumberTwo = NumberTwo.Number; }
        
        uint32 Carry = 0;

        cout << "Num1 = " << CPNumberOne << endl << "Num2 = " << CPNumberTwo << endl;

        for (uint64 Index = LenRes - 1; Index--; Index > 0 ){
                uint32 DigitOne,DigitTwo,Total;
                
                DigitOne = DigitToInt(CPNumberOne[Index]);
                DigitTwo = DigitToInt(CPNumberTwo[Index]);

                Total = DigitOne + DigitTwo + Carry;
                        
                Carry = 0;

                if (Total > 9) {
                        Carry = 1;
                        Total -= 10;
                }
        
                Result[Index] = IntToDigit(Total);
        }
        
        if (Carry == 1){   
                Result = LeftPad(Result,IntToDigit(Carry),LenRes + 1); 
        }

        cout << "Result = " << Result << endl;

        BigInt ReturnNumber;

        InitBigint(&ReturnNumber);
        SetBigintVal(&ReturnNumber,GetSubstring(Result,0,Result.size()-1,1));

        return ReturnNumber;
}

int main(){
        BigInt TestNum;
        BigInt TestNum2;

        InitBigint(&TestNum);
        InitBigint(&TestNum2);

        SetBigintVal(&TestNum,"10");
        SetBigintVal(&TestNum2,"10");

        BigInt Result = AddNums(TestNum,TestNum2);
        cout << "TestNum + TestNum2 = " << Result.Number << endl;
        return 69420;
}
