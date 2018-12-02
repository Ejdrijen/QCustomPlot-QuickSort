#ifndef MAGIC_H
#define MAGIC_H
#include <QVector>


class Magic
{
public:
    Magic();
QVector<double> GenerateAndSort(int begin, int step, int count); //vytvori pole, zosortuje, vrati vektor casov
QVector<double> getXAxisValues(int begin,int step,int count);
private:
    int * GenerateArray(int size);
    void QuickSort(int * array,int start,int end);
    void recursiveQuickS(int * array,int start,int end);
    int sorting(int * array,int start,int end);

};

#endif // MAGIC_H
