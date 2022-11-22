Napisz funkcję rekurencyjną do obliczenia n-tej liczby ciągu arytmetycznego.

function Arytm(array arr, n) {
  if(n == 1)
    return 1
  
  sort arr
  
  set d to the second element of arr minus the first element of arr
  
  if(arr[n] - arr[n-1] != d)
    return 0
  
  if(arr[n] <= 0 or arr[n-1] <= 0)
    return d
    
  else
    Arytm(arr, n--)
}
