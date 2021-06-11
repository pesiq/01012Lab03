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

    explicit binaryHeap(const dynamicArray<T> &arr){
        heap = dynamicArray<T>(arr);
    }

    binaryHeap(const binaryHeap<T> &heap1){
        heap = dynamicArray<T>(heap1.heap);
    }

    int findIndex(T value){
        for(int i = 0; i < heap.length(); i++){
            if(heap[i] == value)
                return i;
        }
        return -1;
    }

    void add(T value){
        int i;
        int parent;

        i = heap.length();
        heap.append(value);

        parent = (i - 1) / 2;

        while (parent >= 0 && i > 0){
            if(heap[i] > heap[parent]){
                T temp = heap[i];
                heap[i] = heap[parent];
                heap[parent] = temp;
            }
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void balance(int i){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int length  = heap.length();
        T temp;

        if(left < length){
            if(heap[i] < heap[left]){
                temp = heap[i];
                heap[i] = heap[left];
                heap[left] = temp;
                balance(left);
            }
        }
        if(right < length){
            if(heap[i] > heap[right]){
                temp = heap[i];
                heap[i] = heap[right];
                heap[right] = temp;
                balance(right);
            }
        }
    }

    binaryHeap<T> &getSubtree(T value){
        int i = findIndex(heap[0]);
        if(i < 0)
            return nullptr;
        auto *result = new dynamicArray<T>;
        for(int j = 1; i*2+1+j*2 < heap.length(); i = i*2+1, j=j*2){
            for (int k = 0; k < j*2; k++) {
                result->append(heap[i * 2 + 1 + k]);
            }
        }
        return *result;
    }


    binaryHeap<T> &operator=(binaryHeap<T> const &heap1){
        heap = heap1;
        return *this;
    }

};


#endif //LAB03_BINARYHEAP_H
