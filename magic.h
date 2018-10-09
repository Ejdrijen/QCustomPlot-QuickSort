#ifndef MAGIC_H
#define MAGIC_H


class Magic
{
public:
    Magic();
    int GenerateAndSort(int size); //vytvori pole, zosortuje
private:
    int * GenerateArray(int size);
    int QuickSort(int * array,int start,int end);
    void recursiveQuickS(int * array,int start,int end);
    int sorting(int * array,int start,int end);

};

#endif // MAGIC_H
