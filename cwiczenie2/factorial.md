# Factorial
## Pseudokod i udowodnienie ze jest częściowo poprawny
### Analiza
Dodatkowe zmienne do f = 1 do inicjacji pętli

### Pseudokod
```
f = 1

while(n--){
  if(n != 0) f *= n
}

return f
```
### Pętla
**Q** (warunek wstępny ): f = 1  
**B** (warunek zatrzymania): while(n--)  
**S** (ciało pętli ): f *= n  
**R** (warunek końcowy): $$\pi_{i=1}^{n}i$$

### Wlasnosc Stopu
- algorytm zatrzyma się, kiedykolwiek zajdzie $$n \leq 0$$
- n jest stałą i skończoną liczbą naturalną - tak

### Częściowa poprawność
1. Przypadek podstawowy: udowodnic, że niezmiennik pętli jest prawdziwy po osiągnięciu pętli
2. Krok indukcii:
   - załóżmy, że niezmiennik i warunek zatrzymania są prawdziwe na końcu dowolnego kroku iteracji (hipoteza indukcji $$P(n-1)$$)
