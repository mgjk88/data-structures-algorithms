#include <vector>
#include <functional>
#include <iostream>

int hoare(std::vector<int> &v, int leftIdx, int rightIdx){  
    int pivotIdx = leftIdx;
    int pivot = v[leftIdx];
    leftIdx++;
    while(leftIdx <= rightIdx){
        while(v[leftIdx] < pivot) leftIdx++;
        while(v[rightIdx] > pivot) rightIdx--;
        if(leftIdx < rightIdx){
            std::swap(v[leftIdx], v[rightIdx]);
            leftIdx++;
            rightIdx--;
        }
    }
    std::swap(v[rightIdx], v[pivotIdx]);
    return rightIdx;
}

void quicksort(std::vector<int> &v, int leftIdx, int rightIdx, std::function<int(std::vector<int>&, int, int)> partition){
    if(leftIdx >= rightIdx) return;
    int partitionIdx = partition(v, leftIdx, rightIdx);
    quicksort(v, leftIdx, partitionIdx - 1, partition);
    quicksort(v, partitionIdx + 1,  rightIdx, partition);
}

int main() {
    std::vector<int> v = {3, 2, 5, 1, 6, 2, 7, 8, 4, 9, 0};
    for(auto i : v){
        std::cout<<i<<' ';
    }
    std::cout<<'\n';
    quicksort(v, 0, v.size() - 1, hoare);
    for(auto i : v){
        std::cout<<i<<' ';
    }
}