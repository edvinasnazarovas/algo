# Iloczyn i reszta
## Pseudokod i udowodnienie ze jest częściowo poprawny


```
r, q, dzielnik=2
int lista[1][liczba/2]

while(dzielnik<liczba/2){
        r = liczba % dzielnik
        q = liczba / dzielnik
        lista[0][dzielnik-2] = r
        lista[1][dzielnik-2] = q
        dzielnik++
    }
```

Dodatkowe zmienne do r, q, dzielnik=2 do inicjacji pętli

### Pętla
**Q** (warunek wstępny ): r, q, dzielnik=2  
**B** (warunek zatrzymania): while(dzielnik<liczba/2)  
**S** (ciało pętli ): r = liczba % dzielnik; q = liczba / dzielnik; lista[0][dzielnik-2] = r; lista[1][dzielnik-2] = q; dzielnik++;
**R** (warunek końcowy): $$r = liczna % dzielnik$$

### Wlasnosc Stopu
- algorytm zatrzyma się, kiedykolwiek zajdzie $$n \leq 0$$
- n jest stałą i skończoną liczbą naturalną - tak

### Częściowa poprawność
1. Przypadek podstawowy: udowodnic, że niezmiennik pętli jest prawdziwy po osiągnięciu pętli
2. Krok indukcii:
   - załóżmy, że niezmiennik i warunek zatrzymania są prawdziwe na końcu dowolnego kroku iteracji. Hipoteza indukcji $$P(n-1)$$
   - pokaż, że niezmiennik pozostaje prawdziwy po jednej iteracji $$(P(n))$$
3. Udowodnic warunek końcowy: argumentuj, że niezmiennik i negacja warunka zatrzymania razem sfinalizujmy stan końcowy programu.

### Przypadek podstawowy
Udowdnimy że niezmiennik pętli jest prawdziwy po osiągnięciu pętli:  


### Krok indukcji
**Nieformalnie**  


