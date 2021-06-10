//
// Created by pesel on 10.06.2021.
//

#ifndef LAB03_BINARYHEAP_H
#define LAB03_BINARYHEAP_H

#include "dynamicArray.h"

template<class T>
class binaryHeap {
private:
    dynamicArray<T> heap;
public:
    binaryHeap(){
        heap = dynamicArray<T>();
    }

    binaryHeap(const dynamicArray<T> &arr){
        heap = dynamicArray<T>(arr);
    }
};


#endif //LAB03_BINARYHEAP_H
