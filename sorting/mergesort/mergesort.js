function mergesort(array){
    if(array.length <= 1) return array;
    const midIdx = Math.floor(array.length / 2);
    const left = mergesort(array.slice(0, midIdx));
    const right = mergesort(array.slice(midIdx));
    let combined = [];
    let leftIdx = 0;
    let rightIdx = 0;
    while(leftIdx < left.length && rightIdx < right.length){ //merge 2 sorted arrays
        if(left[leftIdx] < right[rightIdx]){
            combined.push(left[leftIdx]);
            leftIdx++;
        } else {
            combined.push(right[rightIdx]);
            rightIdx++;
        }
    }
    //remaining elements added to the combined array
    while(leftIdx < left.length){ 
        combined.push(left[leftIdx]);
        leftIdx++;
    }
    while(rightIdx < right.length){
        combined.push(right[rightIdx]);
        rightIdx++;
    }
    return combined;
}

let arr = [5, 3, 7, 1, 9, 2, 8, 4, 6];
console.log(mergesort(arr));