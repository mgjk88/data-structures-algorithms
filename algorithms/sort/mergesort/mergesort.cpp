#include <vector>
#include <iostream>

std::vector<int> mergesort(std::vector<int> &v){
    if(v.size() == 1) return v; //vector of size 1 is already sorted
    
    int midIdx = v.size()/2;
    std::vector<int> left(v.begin(), v.begin() + midIdx);
    std::vector<int> right(v.begin() + midIdx, v.end());
    left = mergesort(left);
    right = mergesort(right);
    std::vector<int> result = {};
    int leftIdx = 0;
    int rightIdx = 0;

    //merge 2 sorted list algorithm
    while(leftIdx < left.size() && rightIdx < right.size()){
        if(left[leftIdx] < right[rightIdx]){
            result.push_back(left[leftIdx]);
            leftIdx++;
        } else {
            result.push_back(right[rightIdx]);
            rightIdx++;
        }
    }
    while(leftIdx < left.size()){
        result.push_back(left[leftIdx]);
        leftIdx++;
    }
    while(rightIdx < right.size()){
        result.push_back(right[rightIdx]);
        rightIdx++;
    }
    return result;
}

int main(){
    std::vector<int> v = {5,6,2,1,3,4};
    std::vector<int> sorted = mergesort(v);
    for(auto i : sorted){
        std::cout<<i<<" ";
    }
}