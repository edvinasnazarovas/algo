Napisz funkcję rekurencyjną do obliczenia n-tej liczby ciągu Fibonacciego.

function fib(n) {
  if(n == 0)
    return 1
    
  if(n == 1 || n == 2)
    return 1
    
  else 
    return(fib(n - 1) + fib(n - 2))
}
