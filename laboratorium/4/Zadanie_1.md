## Dana całkowita liczba $n\geq1$. Napisz funkcja rekurencyjna takiej liczby a, która wypelnia taki warunek $2^{a-1}\leq n\leq2^a$.</br></br>

```
a = n
function myFunction(n, a) {
  if(a == 0)
    return 0;
    
  k1 = 2
  k2 = 2
  
  k1_pow = 1
  k2_pow = 1
  
  for(i = 0; i < a - 1; i++)
    k1_pow = k1_pow * k1
  
  for(i = 0; i < a; i++)
    k2_pow = k2_pow * k2
    
  if(k1_pow <= n && k2_pow => n)
    return a
  else
    myFunction(n, a - 1
}
```
