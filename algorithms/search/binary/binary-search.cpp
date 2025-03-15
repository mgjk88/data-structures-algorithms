//Time complexity: O(log(n))
//Space complexity: O(1)
#include <vector>
#include <iostream>
#include <chrono>
//- keeps track of the jump it has to make from the start index
//- if idx + jump > target, jump halves
// else idx += jump
int binarySearchJump(const std::vector<int> &v, int target)
{
    int n = v.size();
    int i = 0;
    for (int j = n / 2; j >= 1; j /= 2)
    {
        while (i + j < n && v[i + j] <= target)
            i += j;
    }
    return v[i] == target ? i : -1;
}

//classical method of finding the middle index using left and right index as bounds
//shifts left and right bounds to narrow search
int binarySearchMiddle(const std::vector<int> &v, int target){
    int lIdx = 0, rIdx = v.size() - 1;
    while(lIdx <= rIdx) {
        int midIdx = lIdx + (rIdx - lIdx) / 2;
        if(v[midIdx] == target) return midIdx;
        if(v[midIdx] < target) lIdx = midIdx + 1;
        else rIdx = midIdx - 1;
    }
    return -1;
}

int main()
{
    std::vector<int> v = {1,2,3,4,6,7};
    auto start = std::chrono::high_resolution_clock::now();
    std::cout<<binarySearchMiddle(v, 6)<<'\n';
    auto mid = std::chrono::high_resolution_clock::now();
    std::cout<<binarySearchJump(v, 6)<<'\n';
    auto end = std::chrono::high_resolution_clock::now();

    std::cout<<(mid - start).count()<<' '<<(end - mid).count();
    //middle: 43448ns
    //jump: 3352ns
    //jump algo is significantly faster
}