#include "binaryHeap.h"
#include "binaryTree.h"
#include <iostream>
using namespace std;


int multiply(int val){
    return val * 3;
}


void testInsertTree(int amount){
    binaryTree<int> tree;
    for(int i = 0; i < amount; i++)
        tree.add(i+2, i*10);
    for(int i = 0; i < amount; i++){
        cout<<tree.has(i*10);
    }
    cout<<endl<<"Insert Tree OK"<<endl;
}

void testRemoveTree(int amount){
    binaryTree<int> tree;
    for(int i = 0; i < amount; i++)
        tree.add(i+2, i*10);
    for (int i = 0; i < amount / 2; i++) {
        tree.remove(i+2);
    }
    for(int i = amount / 2; i < amount; i++){
        cout<<tree.has(i*10);
    }
    cout<<endl<<"Remove Tree OK"<<endl;
}

void testString(int amount){
    binaryTree<int> tree;
    for(int i = 0; i < amount; i++)
        tree.add(i+2, i*10);
    string res = tree.getValueString(tree.getRoot());
    cout<<"Strings ok"<<endl;
}

void testBalanceTree(int amount){
    binaryTree<int> tree;
    for(int i = 0; i < amount; i++)
        tree.add(i+2, i*10);
    tree.balance(tree.getRoot());
    cout << tree.getValueString(tree.getRoot()) << endl;
    cout << "Balance is ok" << endl;
}



void testMapTree(int amount){
    binaryTree<int> tree;
    for(int i = 0; i < amount; i++)
        tree.add(i+2, i*10);

    binaryTree<int> result = tree.map(multiply);
    cout << result.getValueString(result.getRoot()) << endl;
    cout << "Tree map is OK" << endl;
}

void testSearchTree(int amount){
    binaryTree<int> tree;
    for(int i = 0; i < amount; i++)
        tree.add(i, i*10);
    auto * temp = tree.search(tree.getRoot(), 3);
    cout << tree.getValue(temp) << endl;
}

void testInsertHeap(int amount){
    binaryHeap<int> heap;
    for(int i = 0; i < amount; i++)
        heap.add(i*10);
    for(int i = 0; i < amount;i++){
        cout << heap.findIndex(i*7);
    }
    cout << endl << "Inset is ok" << endl;

}

void testStrHeap(int amount){
    binaryHeap<int> heap;
    for(int i = 0; i < amount; i++)
        heap.add(i*10);
    cout << heap.getStr(0, 0) << endl;
    cout << "to string is ok" << endl;
}


void testBalanceHeap(int amount){
    binaryHeap<int> heap;
    for(int i = 0; i < amount; i++)
        heap.add(i*10);
    cout << heap.getStr(0, 0) << endl;
    heap.balance(0);
    cout << heap.getStr(0, 0) << endl;
    cout << "balance is ok" << endl;
}




void binaryTreeTests(){
    testInsertTree(10);
    testRemoveTree(10);
    testString(10);
    testBalanceTree(10);
    testMapTree(10);
    //testSearchTree(10);
}

void binaryHeapTests(){
    testInsertHeap(10);
    testStrHeap(10);
    testBalanceHeap(10);
}


int main(){
    binaryHeapTests();
    binaryTreeTests();
    return 0;
}
