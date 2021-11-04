#include "AlgorithmSortHeap.h"
#include "BinaryHeap.h"

AlgorithmSortHeap::AlgorithmSortHeap(int k):SelectionAlgorithm(k){
    // it will use base class' construction to assing k
}

int AlgorithmSortHeap::select(){

    int element;
    int size = 0;
    cin >> size;

    BinaryHeap *minHeap = new BinaryHeap(this->k);

    for(int i = 0 ; i < this->k; i++){
        cin >> element;
        minHeap->insert(element); 
    }
    
    for(int i = this->k; i < size; i++){
        cin >> element;
        if(element < minHeap->getMin()){
            continue;
        }
        else{
            minHeap->deleteMin();
            minHeap->insert(element);
        }
    }

    int result = minHeap->getMin();
    return result;
    delete minHeap;
}