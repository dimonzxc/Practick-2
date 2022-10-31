#include <algorithm>
#include <iostream>
#include <iomanip>
#include "chrono"
#include "stdlib.h"
#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define time_now() std::chrono::high_resolution_clock::now()
#define coutline() cout<<"-------------------------------------------------------------\n"
#define ArLen 100
using namespace std;
int base_array[ArLen] ,SortAr[ArLen],sort_type = 0,task_sw;
long int delta;
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void ArrRand(int *Array){
    for (int i = 0; i < ArLen; i++) {
        Array[i] = rand() % 189 - 99;
    }
}
void ArrOUT(int *Array){
    coutline();
    for(int i = 0;i<10;i++){
        cout
                <<"|"<<setw(5)<<Array[i*10+0]
                <<"|"<<setw(5)<<Array[i*10+1]
                <<"|"<<setw(5)<<Array[i*10+2]
                <<"|"<<setw(5)<<Array[i*10+3]
                <<"|"<<setw(5)<<Array[i*10+4]
                <<"|"<<setw(5)<<Array[i*10+5]
                <<"|"<<setw(5)<<Array[i*10+6]
                <<"|"<<setw(5)<<Array[i*10+7]
                <<"|"<<setw(5)<<Array[i*10+8]
                <<"|"<<setw(5)<<Array[i*10+9]
                <<"|\n";coutline();}
}
void bubbleSort(int *Array){
    for(int i = 0;i<ArLen;i++){
        for(int j = (ArLen-1);j>=(i+1);j--){
            if(SortAr[j]<SortAr[j-1])
                swap(SortAr[j],SortAr[j-1]);
        }
    }
}
int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap (&array[i], &array[j]);
        }
    }
    swap (&array[i + 1], &array[high]);
    return (i + 1);
}
void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition (array, low, high);
        quickSort (array, low, pi - 1);
        quickSort (array, pi + 1, high);
    }
}
void insertionSort(int *Array)
{
    int key = 0;
    int i = 0;
    for(int j = 1;j<ArLen;j++){
        key = Array[j];
        i = j-1;
        while(i>=0 && Array[i]>key){
            Array[i+1] = Array[i];
            i = i-1;
            Array[i+1]=key;
        }
    }
}

int main() {

    ArrRand(base_array);
    cout<<"  Basic array:\n";
    ArrOUT(base_array);
    for (int i = 0; i < ArLen; i++) {
        SortAr[i] = base_array[i];
    }
    while(true) {
        cout << "Choose paragraph:\n"
                "1.\tNew random array\n"
                "2.\tSort array\n"
                "3.\tMin and max of array\n"
                "4.\tAverage of min and max\n"
                "5.\tElements lower than \"x\"\n"
                "6.\tElements higher than  \"x\"\n"
                "7.\tBinary search of  \"x\"\n"
                "8.\tSwap of elements  \"x\" & \"y\"\n"
                "9.\tExit\n";
        cin >> task_sw;
        switch (task_sw) {
            case 1: {
                ArrRand(base_array);
                ArrOUT(base_array);
                for (int i = 0; i < ArLen; i++) {
                    SortAr[i] = base_array[i];
                }
                break;
            }
            case 2: {
                cout << "Choose sort:\n" <<
                     " 1. Bubble Sort\n" <<
                     " 2. Quick Sort\n" <<
                     " 3. Insertion Sort\n";
                cin >> sort_type;
                switch (sort_type) {
                    case 1: {
                        for (int i = 0; i < ArLen; i++) {
                            SortAr[i] = base_array[i];
                        }
                        auto t = time_now();
                        bubbleSort(SortAr);
                        delta = duration(time_now() - t);
                        ArrOUT(SortAr);
                        cout << "Search took " << delta << " nanoseconds\n";
                        break;
                    }
                    case 2: {
                        for (int i = 0; i < ArLen; i++) {
                            SortAr[i] = base_array[i];
                        }
                        int size = sizeof(base_array) / sizeof(base_array[0]);
                        auto t = time_now();
                        quickSort(SortAr, 0, size - 1);
                        delta = duration(time_now() - t);
                        ArrOUT(SortAr);
                        cout << "Search took " << delta << " nanoseconds\n";
                        break;
                    }
                    case 3: {
                        for (int i = 0; i < ArLen; i++) {
                            SortAr[i] = base_array[i];
                        }
                        auto t = time_now();
                        insertionSort(SortAr);
                        delta = duration(time_now() - t);
                        ArrOUT(SortAr);
                        cout << "Search took " << delta << " nanoseconds\n";
                        break;
                    }
                    default: {
                        cout << "ERR:invalid value\n";
                        break;
                    }
                }
                break;
            }
            case 3:{
                coutline();
                insertionSort(SortAr);
                cout <<" Min: "<< SortAr[0] <<" Max: " << SortAr[ArLen-1] << endl<< endl;
                cout <<"In sorted array: "<<"Search took " << 0 << " nanoseconds\n\n";
                auto t = time_now();
                for (int i = 0; i < ArLen; i++) {
                }
                for (int i = 0; i < ArLen; i++) {
                }
                delta = duration(time_now() - t);
                cout <<"In unsorted array: "<<"Search took " << delta << " nanoseconds\n";
                coutline();
                break;}
            case 4:{
                insertionSort(SortAr);
                coutline();
                cout <<"Average of min & max is "<<(SortAr[0]+SortAr[ArLen-1]) / 2 << endl<< endl;
                cout <<"Indexes: ";
                for (int i = 0; i < ArLen; i++) {
                    if(base_array[i] == ((SortAr[0]+SortAr[ArLen-1]) / 2)){
                        cout<< i << " ";
                    }
                }
                cout<<endl;
                coutline();

                break;}
            case 5:{
                int x = 0;
                insertionSort(SortAr);
                cout<<"insert x: ";
                cin>> x;
                int temp = 0;
                for (int i = 0; i < ArLen; i++) {
                    if(SortAr[i] < x){
                        temp++;
                    }
                }
                cout<< endl <<"numbers lower than x is: "<< temp<< endl;
                coutline();
                break;}
            case 6:{
                int x = 0;
                insertionSort(SortAr);
                cout<<"insert x: ";
                cin>> x;
                int temp = 0;
                for (int i = 0; i < ArLen; i++) {
                    if(SortAr[99 - i] > x){
                        temp++;
                    }
                }
                cout<< endl <<"numbers higher than x is: "<< temp<< endl;
                coutline();
                break;}
            case 7:{
                coutline();
                int mid,key;
                bool flag = false;

                cout<<"insert number: ";
                insertionSort(SortAr);
                cin >> key;
                auto t = time_now();
                int st = 0;
                int en = ArLen-1;
                while ((st <= en) && (flag != true)) {
                    mid = (st + en) / 2;

                    if (SortAr[mid] == key) flag = true;
                    if (SortAr[mid] > key) en = mid - 1;
                    else st = mid + 1;
                }
                delta = duration(time_now() - t);
                if (flag == true){cout << "such a number is in the array\n";}else {
                    cout << "there is no such number in the array\n";
                }
                cout <<"With binary search: "<<"Search took " << delta << " nanoseconds\n\n";
                t = time_now();
                for (int i = 0; i < ArLen; i++) {
                }
                delta = duration(time_now() - t);
                cout <<"With enumeration: "<<"Search took " << delta << " nanoseconds\n";
                coutline();
                break;}
            case 8:{
                int x,y;
                coutline();
                cout << "input x & y: ";
                cin >> x >> y;
                auto t = time_now();
                swap(base_array[x],base_array[y]);
                delta = duration(time_now() - t);
                ArrOUT(base_array);
                cout <<"Swap took " << delta << " nanoseconds\n";
                coutline();
                break;}
            case 9:{system("pause");
                break;}

            default: {
                cout << "ERR:invalid value\n";
                break;
            }

        }

    }
}