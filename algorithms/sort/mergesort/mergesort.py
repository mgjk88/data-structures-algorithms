def mergesort(array):
    if len(array) == 1: return array
    mid =  len(array) // 2
    left = mergesort(array[:mid])
    right = mergesort(array[mid:])
    leftIdx = 0
    rightIdx = 0
    result = []
    while leftIdx < len(left) and rightIdx < len(right):
        if left[leftIdx] < right[rightIdx]:
            result.append(left[leftIdx])
            leftIdx += 1
        else:
            result.append(right[rightIdx])
            rightIdx += 1
    result += left[leftIdx:]
    result += right[rightIdx:]
    return result

l = [7,2,3,1,5,4,6]
print(mergesort(l))
        
    
