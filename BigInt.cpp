#include <string>
#include <iostream>

using namespace std;

#define uint64 unsigned long long
#define uint32 unsigned int
#define int32 int
#define int64 long long
#define SIZEOFINT 4
#define MAXINTSIZE 4294967295

typedef struct{
        uint32* arr;
        uint64 Chunks;
        bool initialised;
} BigInt;

void InitBigint(BigInt* Number, uint32 num){
        Number->arr = (uint32*) malloc(SIZEOFINT);
        Number->arr[0] = num;
        Number->Chunks = 1;
        Number->initialised = true;
}

void PrintIntArr(uint32* arr, uint64 len){
        cout << "[";
        for (uint64 i = 0; i < len; i++){
                cout << arr[i];
                if (len - 1 == i){
                        break;
                }
                cout << ", ";
        }
        cout << "]";
}

void PrintBigint(BigInt* num){
        PrintIntArr(num->arr,num->Chunks);
}

bool IsOverflow(uint32 Num1, uint32 Num2, char op){
        if (op != '+' && op != '-' || (Num1 == 0 || Num2 == 0) && (op != '-' && Num1 != 0)){
                return false;
        }

        if (op == '+'){
                return ((Num1 + Num2) < Num1);
        }
        else{
                return ((Num1 - Num2) > Num1);
        }
}

BigInt AddNums(BigInt NumOne, BigInt NumTwo){
        uint32* PtrToNumOne = &NumOne.arr[0];
        uint32* PtrToNumTwo = &NumTwo.arr[0];

        BigInt Sum;
        InitBigint(&Sum,0);
        bool isOverflow;

        do{
                isOverflow = IsOverflow(*PtrToNumOne,*PtrToNumTwo,'+');
                
                if (isOverflow) {
                        cout << "was overflow \n";
                        uint32 OverflowAmount = *PtrToNumOne + *PtrToNumTwo;
                        uint32 AmountUntilOverflow = MAXINTSIZE - *PtrToNumOne;
                        Sum.arr = (uint32* ) realloc(Sum.arr,Sum.Chunks + SIZEOFINT);
                        Sum.Chunks += 1;
                        Sum.arr[Sum.Chunks-2] = AmountUntilOverflow;
                        uint32 total = OverflowAmount;
                        Sum.arr[Sum.Chunks-1] = OverflowAmount;
                        continue;
                }
        
                Sum.arr[Sum.Chunks - 1] = *PtrToNumOne + *PtrToNumTwo;

                PrintBigint(&Sum);
                
                if (PtrToNumOne != &NumOne.arr[NumOne.Chunks-1]){
                        PtrToNumOne++;
                }
                if (PtrToNumTwo != &NumTwo.arr[NumTwo.Chunks-1]){
                        PtrToNumTwo++;
                }

        } while (PtrToNumOne != &NumOne.arr[NumOne.Chunks] && PtrToNumTwo != &NumTwo.arr[NumTwo.Chunks]);

        PrintBigint(&Sum);
        return Sum;
}

int main(){
        BigInt TestNumber;
        InitBigint(&TestNumber,4250);
        
        uint32 OverFlownum = 0;

        AddNums(TestNumber,TestNumber);
}
