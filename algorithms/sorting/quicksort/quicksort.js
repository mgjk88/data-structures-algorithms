function lomuto(array, leftIdx, rightIdx) {
  //picks random pivot and places it at the end
  let pivotIdx = Math.floor(Math.random() * (rightIdx - leftIdx + 1)) + leftIdx;
  [array[pivotIdx], array[rightIdx]] = [array[rightIdx], array[pivotIdx]];
  pivotIdx = rightIdx;
  rightIdx--; //exclude pivot form partitioning

  const pivot = array[pivotIdx];
  let slowIdx = leftIdx - 1;
  for (let fastIdx = leftIdx; fastIdx <= rightIdx; fastIdx++) {
    if (array[fastIdx] < pivot) {
      slowIdx++;
      [array[fastIdx], array[slowIdx]] = [array[slowIdx], array[fastIdx]];
    }
  }
  //place pivot in correct position
  [array[slowIdx + 1], array[pivotIdx]] = [array[pivotIdx], array[slowIdx + 1]];
  return slowIdx + 1;
}

function hoare(array, leftIdx, rightIdx) {
  //picks random pivot and places it at the end
  let pivotIdx = Math.floor(Math.random() * (rightIdx - leftIdx + 1)) + leftIdx;
  [array[pivotIdx], array[rightIdx]] = [array[rightIdx], array[pivotIdx]];
  pivotIdx = rightIdx;
  rightIdx--; //exclude pivot form partitioning

  const pivot = array[pivotIdx];
  while(leftIdx <= rightIdx) {
    while(array[leftIdx] <= pivot) leftIdx++; 
    while(array[rightIdx] > pivot) rightIdx--;
    if(leftIdx <= rightIdx) {
        [array[leftIdx], array[rightIdx]] = [array[rightIdx], array[leftIdx]];
        leftIdx++;
        rightIdx--;
    }
  }
  //place pivot in correct position 
  [array[leftIdx], array[pivotIdx]] = [array[pivotIdx], array[leftIdx]];
  return leftIdx;
}

function quicksort(array, leftIdx, rightIdx, partitionFn) {
  if (leftIdx >= rightIdx) return;
  const partitionIdx = partitionFn(array, leftIdx, rightIdx);
  quicksort(array, leftIdx, partitionIdx - 1, partitionFn);
  quicksort(array, partitionIdx + 1, rightIdx, partitionFn);
}

let array = [3, 2, 5, 1, 6, 2, 7, 8, 4, 9, 0];
quicksort(array, 0, array.length - 1, hoare);
console.log(array);
