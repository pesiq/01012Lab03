//
// Created by pesel on 10.06.2021.
//

#ifndef LAB03_DYNAMICARRAY_H
#define LAB03_DYNAMICARRAY_H

template <class T>
class dynamicArray{
private:
    T *items;
    int size;
    int bufferSize;
public:

    //array creation
    dynamicArray(T *arr, int amount) {
        bufferSize = 2*amount;
        items = new T[bufferSize];
        size = amount;
        for(int i = 0; i < amount; i++){
            items[i] = arr[i];
        }
    } //create array from static

    explicit dynamicArray(int amount) {
        if(amount <= 0) {
            throw invalidArgument();
        }
        size = amount;
        bufferSize = 2*amount;
        items = new T[bufferSize]; //allocating memory for dynamicArray
    } //create empty buffer

    dynamicArray(const dynamicArray<T> &array) {
        bufferSize = array.bufferSize;
        items = new T[bufferSize];
        size = array.size;
        for(int i = 0; i < array.size; i++){
            items[i] = array.items[i];
        }
    }// copy existing array


    dynamicArray() {
        size = 0;
        bufferSize = 10;
        items = new T[bufferSize];
    }

    //array destruction
    ~dynamicArray() {
        if(bufferSize > 0)
            delete[] items;
        bufferSize = 0;
        size = 0;
    } //destructor


    deleteArray(){
        if(bufferSize > 0)
            delete[] items;
        bufferSize = 0;
        size = 0;
    } //deletion function

    //decomposition
    T get(int index) {
        if(index > size || index < 0){
            throw indexOutOfRange();
        }
        return items[index];
    } //get element at index

    int length() {
        return size;
    } //get size of array

    //operations
    void set(int index, T value) {
        if(index > size || index < 0){
            throw indexOutOfRange();
        }
        items[index] = value;
    } //set element at index

    void append(T value){
        size++;
        if (size > bufferSize){
            resize(bufferSize*2);
        }
        set(size-1, value);
    }

    void prepend(T value){
        size++;
        if (size > bufferSize){
            resize(bufferSize*2);
        }
        for(int i = size-2; i > 0; i--) {
            items[i+1] = items[i];
        }
        set(0, value);
    }

    //change size of array
    //negative value to reduce
    //positive value to increase
    void resize(int amount) {

        if(amount == 0){
            return;
        }

        if (amount > 0){
            size += amount;
            if(size > bufferSize){
                T* temp = new T[size+(amount * 2)];
                bufferSize += amount * 2;
                for(int i = 0; i<size-amount; i++){
                    temp[i] = items[i];
                }
                delete[] items;
                items = temp;
            }
            return;
        }

        if(amount < 0){
            if(size-amount > 0){
                size += amount;
            } else {
                size = 0;
            }
            return;
        }

    T& operator[](int index){
        if(index >= 0 && index < size)
            return items[index];
        if(index < 0 && index > -size)
            return items[size-index];
        else{
            throw indexOutOfRange();
        }
    }

    dynamicArray<T>& operator= (const dynamicArray<T>& array){
        bufferSize = array.bufferSize;
        items = new T[bufferSize];
        size = array.size;
        if(array.items == nullptr) {
            items = nullptr;
            return *this;
        }
        for(int i = 0; i < array.size; i++){
            items[i] = array.items[i];
        }
        return *this;
    }

};


#endif //LAB03_DYNAMICARRAY_H
