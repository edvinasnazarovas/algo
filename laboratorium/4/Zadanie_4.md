Napisz funkcję rekurencyjną do obliczenia n-tej liczby ciągu geometrycznego.

```
sum = 0

function geo(a, r, n, sum) {
  sum = sum + a
  a = a * r
  
  if(n == 1)
    return sum
  
  else
    return geo(a, r, n - 1, sum)
}
```
