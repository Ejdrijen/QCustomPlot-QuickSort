#include "magic.h"
#include <iostream>
#include <stdlib.h>

Magic::Magic(){}

int Magic::GenerateAndSort(int size){
    int * array = Magic::GenerateArray(size);//generuje pole zadanej velkosti
    Magic::QuickSort(array,0,size-1);
    return 0;
}

int * Magic::GenerateArray(int size){
    int * array = new int[size];
    for(int i=0;i<size;i++){
        array[i]=rand() % 100 + 1; //vygeneruje nahodne cisla medzi 100 a 1;
    }
    return array;

}
int Magic::QuickSort(int * array,int start,int end){
   Magic::recursiveQuickS(array,start,end);
   return 0;
}


void Magic::recursiveQuickS(int *array,int start, int end){
   if(start < end){
       int index =sorting(array,start,end);//vola sa sortovaci algoritmus
       QuickSort(array,start,index-1);
       QuickSort(array,index+1,end);

   }
}

int Magic::sorting(int* array,int start, int end){
    int pivot=array[end];//nastavi sa pivot (posledny prvok pola)
    int index=start;
    int tmp;
    for(int i=start; i <= end-1 ; i++){

        if(array[i] <= pivot){//cisla mensie od pivota idu nalavo
            tmp= array[i];
            array[i]=array[index];
            array[index]=tmp;
            index++;
        }
    }
    tmp= array[end];
        array[end]=array[index];
        array[index]=tmp;//pivot sa vlozi na spravne miesto
    return index;
}


