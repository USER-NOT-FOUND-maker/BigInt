#include <string>
#include <iostream>

#define uint64 unsigned long long
#define uint32 unsigned int
#define int32 int
#define int64 long long

using namespace std;

typedef struct {
        string Number;
        uint64 Digits;
        bool initialised;
} BigInt;

void InitBigint(BigInt* NumberAddress);
void SetBigintVal(BigInt* NumberAddress, string NewVal);
BigInt AddNums(BigInt Num1, BigInt Num2);
BigInt MulNumsULL(BigInt Number, uint64 multiplier);
BigInt PowerNumsULL(BigInt Number, uint64 exponent);
BigInt PowerNumsBIGINT(BigInt Num1,BigInt Num2);
BigInt MulNumsBIGINT(BigInt Num1,BigInt Num2);
int32 DigitToInt(char Digit);
char IntToDigit(int32 Int);

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
       
        for (uint64 i = 0; i < NewVal.length(); i++) { if (!IsInCharray(DIGITS,NewVal[i])) { throw runtime_error("string was NOT a numerical value (retard), negative numbers and floats not supported")}}

        NumberAddress->Number = NewVal;
        NumberAddress->Digits = NewVal.length();
}

int main(){
        BigInt TestNum;

        InitBigint(&TestNum);

        SetBigintVal(&TestNum,"100000");
        return 69420;
}
