#include "feru.h"

int main()
{
    int choise;
    member arr[maxBr];
    int lenn = 0;
    
    int numCatI=0;
    int numCatII=0;
    int numCatIII=0;
    int numCatIV=0;

    member catI[maxBr];
    member catII[maxBr];
    member catIII[maxBr];
    member catIV[maxBr];
   
    chetene(arr, lenn);
    menu(arr, lenn,catI,catII,catIII,catIV,numCatI,numCatII,numCatIII,numCatIV);
}







