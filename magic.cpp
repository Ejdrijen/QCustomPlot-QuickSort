#include "magic.h"
#include <QtGlobal>
#include <stdlib.h>
#include <QElapsedTimer>


Magic::Magic(){}
//int begin - hodnota na ktorej zaciname;
//int step - o kolko zvacsujeme pole;
//int count pocet prvkov pola;
QVector<double> Magic::GenerateAndSort(int begin, int step, int count){

    QVector<double> intervals(count);
    int * array;
    QElapsedTimer timer;
    timer.start();

    for(int i=0;i<count;i++){

        array = Magic::GenerateArray(begin);//generuje pole zadanej velkosti
        Magic::QuickSort(array,0,begin-1);
        intervals[i]=timer.nsecsElapsed()/1000;//vracia cas v nanosekundach -> /1000=mikrosekundy
        delete array;
        begin+=step; //velkost dalsieho pola
    }

    return intervals;
}
QVector<double> Magic::getXAxisValues(int begin,int step,int count){
    QVector<double> Xvalues(count);
    for(int i=0;i<count;i++){
        Xvalues[i]=begin+(i*step);
    }
    return Xvalues;
}



int * Magic::GenerateArray(int size){
    int * array = new int[size];
    for(int i=0;i<size;i++){
        array[i]=rand() % 100 + 1; //vygeneruje nahodne cisla medzi 100 a 1;
    }
    return array;

}
void Magic::QuickSort(int * array,int start,int end){
   Magic::recursiveQuickS(array,start,end);

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


