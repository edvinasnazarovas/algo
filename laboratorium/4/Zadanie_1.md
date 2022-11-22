## Dana całkowita liczba $n\geq1$. Napisz funkcja rekurencyjna takiej liczby a, która wypelnia taki warunek $2^{a-1}\leq n\leq2^a$.</br></br>
function myFunction(n, a) {
  n = 1
  k1 = 2
  k2 = 2
  a = 0
  
  for(i = 0; i < a - 1; i++)
    k1 = k1 * k1
  
  for(i = 0; i < a; i++)
    k2 = k2 * k2
    
  if(k1 <= n && k2 => n)
    return a
  else
    myFunction(n, a++)
}
