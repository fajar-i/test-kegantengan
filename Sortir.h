#include<stdio.h>
#include<stdlib.h>

void tukar(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

struct To_Do{
    char hari[250];
    char jam[250];
    char kegiatan[250];
    char tanggal[250];
};

int partition(int tabel[], int low, int high){
    int pivot, j, i;
    pivot = tabel[high];
    i=low - 1;

    for (j=low; j<high; j++){
        if (tabel[j] >= pivot){
            i=i+1;
            tukar(tabel[i], tabel[j]);
        }
    }
    tukar(tabel[i+1], tabel[high]);
    
    return i+1;
}

void SortAscending(int tabel[], int low, int high){
    int pivotlocation;
    if (low < high){
        pivotlocation = partition(tabel, low, high);
        SortAscending(tabel, low, pivotlocation-1);
        SortAscending(tabel, pivotlocation + 1, high);
    }
}

void tukerin(struct To_DO *list, int size){
    char temp;
}