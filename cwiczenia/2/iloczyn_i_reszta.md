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

