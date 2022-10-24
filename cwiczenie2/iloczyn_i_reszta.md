# Iloczyn i reszta
## Pseudokod i udowodnienie ze jest częściowo poprawny

while(dzielnik<liczba/2){
        r = liczba % dzielnik
        q = liczba / dzielnik
        lista[0][dzielnik-2] = r
        lista[1][dzielnik-2] = q
        dzielnik++
    }
