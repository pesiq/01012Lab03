#include "binaryHeap.h"
#include "binaryTree.h"
#include <iostream>
using namespace std;

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

void binaryTreeTests(){
    testInsertTree(10);
    testRemoveTree(10);
}

void binaryHeapTests(){

}


int main(){
    binaryHeapTests();
    binaryTreeTests();
    return 0;
}
