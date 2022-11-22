Napisz funkcję rekurencyjną do obliczenia n-tej liczby ciągu arytmetycznego.

```
d = arr[n] - arr[n - 1]
set n to size of array

function Arytm(array arr, n, d) {
  if(n == 1)
    return d
  
  sort arr
  
  if(arr[n] - arr[n-1] != d)
    return 0
  
  if(arr[n] <= 0 or arr[n-1] <= 0)
    return d
    
  else
    return Arytm(arr, n - 1)
}
```
