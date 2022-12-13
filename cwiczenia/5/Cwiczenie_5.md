## Bubblesort

```
function swap(xp, yp) {
  temp = xp
  xp = yp
  yp = temp
}

function bubbleSort(arr, n) {
  int i, j
  for(i = 0; i < n - 1; i++)
    for(j = 0; j < n - i - 1; j++)
      if(arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1])        
}

function main(){
  fptr = open(random.dat)
  n = size of arr / size of arr[0]
  set all elements of arr to contents of random.dat
  bubbleSort(arr)
```

## Insertion sort
```
function insertionSort(arr, n) {
  for(i = 1; i < n; i++)
    key = arr[i]
    j = i - 1
    
    while(j >= 0 and arr[j] > key)
      arr[j + 1] = arr[j]
      j = j - 1
    arr[j + 1] = key
}

function main() {
  n = size of arr / size of arr[0]
  fopen(random.dat)
  set all elements of arr to contents of random.dat
  insertionSort(arr, n)
}
```

## Selection sort
```

```
