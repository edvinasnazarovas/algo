Napisz funkcję rekurencyjną do wyprowadzenia n-tej liczby trojkatu Paskalia.

```
function pascal(row, col) {
  if(col == 0)
    return 1
    
  if(row == 0)
    return col
    
  return (row * pascal(row - 1, col - 1)) / col
```
