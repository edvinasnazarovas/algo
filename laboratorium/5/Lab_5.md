## Merge Sort (Recursive)

```
function mergeSort(array, l, r) {
  if(l < r)
    set mid to l + (r - l) / 2
    mergeSort(array, l, mid)
    mergeSort(array, mid + 1, r);
    merge(array, l, mid, r)
}
```

## Merge

```
function merge(array, l, mid, r) {
  set size1 to mid - l + 1
  set size2 to r - mid
  
  for(i = 0; i < size1; i++)
    Left[i] = array[l + i]
    
  for(j = 0; j < size2; j++)
    Right[j] = array[mid + 1 + j]
    
  i = 0
  j = 0
  k = l
  
  while(i < size1 and j < size2)
    if(Left[i] <= Right[j])
      array[k] = Left[i]
      i++
    else
      array[k] = Right[j]
      j++
      k++
  
  while(i < size1)
    arr[k] = Left[i]
    i++
    k++
    
  while(j < size2)
    arr[k] = Right[j]
    j++
    k++
```

## Binary Search (Recursive)
```
function binarySearchRecursive(array, lo, hi, key) {
  kroki++
  
  if(lo > hi)
   return 0
  
  mid = (lo + hi) / 2
  
  if(array[mid] == key)
    return 1
  else if(array[mid] > key)
    binarySearchRecursive(array, lo, mid - 1, key)
  else if(array[mid] < key)
    binarySearchRecursive(array, mid + 1, hi, key)
}
```

## Binary Search
```
function binarySearch(array, f, l, n){
  kroki++
  mid = (f + l) / 2
  
  while(f <= l)
    if(array[mid[ < n)
      f = mid + 1
    else if(array[mid] == n
      return 1
    else
      l = mid - 1
  
  if(f > l)
    return 0
}
```
