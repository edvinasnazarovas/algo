## Praca wykonał [Edvinas Nazarovas](https://github.com/edvinasnazarovas/)

## Projekt do przedmiotu "Algorytmy i struktury danych"

## Data 2023-01-20

- [Algorytm generacji liczb pseudolosowych](#algorytm-generacji-liczb-pseudolosowych)
- [Algorytm deszyfrowania z pseudolosowym odstępem](#algorytm-deszyfrowania-z-pseudolosowym-odstępem)
- [Algorytm usuwania duplikatów z listy dwukierunkowej](#algorytm-usuwania-duplikatów-z-listy-dwukierunkowej)
- [Zródła](#zródła)

## Algorytm generacji liczb pseudolosowych

### Pseudokod :page_facing_up:

```
linearCongruentialMethod(Xo, m, a, c, randomNums, noOfRandomNums)
Input:
Xo - the seed state or initial value
m - the modulus value
a - the multiplier value
c - the increment value
randomNums - array to store the generated random numbers
noOfRandomNums - number of random numbers to be generated
Output: None
Begin
1. Set randomNums[0] to Xo
2. For i = 1 to noOfRandomNums-1
2.1 Set randomNums[i] = (randomNums[i-1] * a + c) % m
3. End For
End
End function
```

### Udowodnienie, że algorytm jest końcowy

1. LCG spełnia wymagania generatorów liczb pseudolosowych, takie jak brak powtarzalności w sekwencji liczb, brak wzoru w rozkładzie liczb oraz brak uprzedniej zależności między liczbami.
2. LCG jest oparty na matematycznej formule $Xn+1 = (aXn + c) mod m$, gdzie `Xn` to n-ta liczba w sekwencji, `a`, `c` i `m` to parametry użyte w algorytmie. Działanie algorytmu jest zgodne z tą formułą i spełnia warunki matematyczne związane z metodą liniowego kongruencji.

### Złożonośc

1. Pierwszym krokiem jest inicjalizacja stanu początkowego, co jest operacją stałego czasu, `O(1)`.

2. Drugim krokiem jest pętla `for`, która iteruje od `1` do `noOfRandomNums-1`. Wewnątrz pętli `for`, wykonywane są 2 operacje:

* Pierwsza operacja to obliczenie $(randomNums[i - 1] * a + c) % m$, która jest operacją stałego czasu, `O(1)`.
* Druga operacja to przypisanie wyniku obliczenia do `randomNums[i]`, która również jest operacją stałego czasu, `O(1)`.
3. Całkowity czas działania pętli `for` jest liczbą iteracji pomnożonych przez czas działania operacji wewnątrz pętli: $(noOfRandomNums - 1) * (O(1) + O(1)) = (noOfRandomNums - 1) * O(1) = O(n)$

Z tego wynika, że ogólna złożoność czasowa funkcji linearCongruentialMethod jest $O(1) + O(n) = O(n)$.

### Przykład zastosowania

Linear Congruent Method (LCG) może być używany do generowania sekwencji liczb pseudolosowych. LCG używa matematycznego wzoru, aby produkować sekwencję liczb, które przypominają właściwości liczb losowych. Te liczby mogą być używane w różnych aplikacjach, takich jak symulacje statystyczne, kryptografia i tworzenie gier.

Na przykład, w tworzeniu gier, LCG może być używane do generowania losowych wydarzeń w grze, takich jak losowe pojawianie się przeciwników czy losowe generowanie poziomów. Może być również używany do generowania losowych liczb do użycia jako klucze szyfrowania w grach sieciowych.

## Program
[lcg.h](/C%20Example/lcg.h)

## Algorytm deszyfrowania z pseudolosowym odstępem.

### Pseudokod :page_facing_up:

```
cipher(klucz, m, a, c, napis)
Wejście:
klucz - stan początkowy do generowania liczb losowych
m - wartość modulo dla LCG
a - wartość mnożnika dla LCG
c - wartość inkrementu dla LCG
napis - ciąg znaków do zaszyfrowania
Wyjście: None
Początek
1. Zadeklaruj zmienne i i liczbyLosowe jako tablica 256 liczb całkowitych
2. Wywołaj linearCongruentialMethod(klucz, m, a, c, liczbyLosowe, 256) w celu wygenerowania tablicy liczb losowych
3. Dla i = 0 do długości ciągu znaków s - 1
3.1 Ustaw klucz = liczbyLosowe[i]
3.2 Zmień znak s[i] na dużą literę
3.3 Jeśli znak s[i] jest między 'A' a 'Z' włącznie, ustaw s[i] = 65 + (s[i] - 65 + klucz % 26) % 26
4. Koniec pętli
Koniec

decipher(klucz, m, a, c, napis)
Wejście:
klucz - stan początkowy do generowania liczb losowych
m - wartość modulo dla LCG
a - wartość mnożnika dla LCG
c - wartość inkrementu dla LCG
napis - ciąg znaków do odszyfrowania
Wyjście: None
Początek
1. Zadeklaruj zmienne i i liczbyLosowe jako tablica 256 liczb całkowitych
2. Wywołaj linearCongruentialMethod(klucz, m, a, c, liczbyLosowe, 256) w celu wygenerowania tablicy liczb losowych
3. Dla i = 0 do długości ciągu znaków s - 1
3.1 Ustaw klucz = liczbyLosowe[i]
3.2 Zmień znak s[i] na dużą literę
3.3 Jeśli znak s[i] jest między 'A' a 'Z' włącznie, ustaw s[i] = 65 + (s[i] - 65 - klucz % 26 + 26) % 26
4. Koniec pętli
Koniec
```

### Udowodnienie, że algorytm jest końcowy

1. Algorytm deszyfrowania korzysta z sekwencji liczb pseudolosowych generowanych przez metodę liniowego kongruencji (LCG) i przesuwa znaki w tekście jawnym w przeciwną stronę, niż to robi algorytm szyfrowania.
2. Algorytm deszyfrowania porusza się po ciągu tekstu jawnego za pomocą pętli for i dla każdego znaku wykonuje operacje zamiany znaku na wielką literę, sprawdzenie czy znak jest w zakresie od `'A'` do `'Z'`, odejmowanie `modulo 26` liczby pseudolosowej od indeksu znaku, i przypisanie nowej wartości znaku.
3. Te operacje są odwrotne do operacji wykonywanych przez algorytm szyfrowania, co pozwala na odzyskanie pierwotnego tekstu jawnego.
4. Algorytm deszyfrowania jest zgodny z algorytmem szyfrowania, ponieważ działa na tych samych parametrach, takich jak `klucz`, `m`, `a`, `c`, i przy użyciu tej samej sekwencji liczb pseudolosowych generowanej przez LCG.

### Złożoność

1. Pierwszym krokiem jest generowanie sekwencji liczb pseudolosowych za pomocą metody liniowego kongruencji (LCG), co jest złożonością `O(n)` dla generowania `n` liczb pseudolosowych.

2. Drugim krokiem jest pętla `for`, która iteruje od `0` do `długości ciągu tekstu jawnego - 1`. Wewnątrz pętli `for`, wykonywane są następujące operacje:

* Konwersja znaku na wielką literę, co jest operacją stałego czasu `O(1)`.
* Sprawdzenie czy znak jest w zakresie od `'A'` do `'Z'`, co jest operacją stałego czasu `O(1)`
* Odejmowanie `modulo 26` liczby pseudolosowej od indeksu znaku, co jest operacją stałego czasu `O(1)`
* Przypisanie nowej wartości znaku, co jest operacją stałego czasu `O(1)`
3. Całkowity czas działania pętli for jest liczbą iteracji pomnożonych przez czas działania operacji wewnątrz pętli: $(n) * (O(1) + O(1) + O(1) + O(1)) = n * O(1) = O(n)$

4. Z tego wynika, że ogólna złożoność czasowa algorytmu deszyfrowania z pseudolosowym odstępem jest $O(n) + O(n) = O(n)$, gdzie `n` jest liczbą znaków w ciągu tekstu jawnego.

### Przykład zastosowania 

Algorytm deszyfrowania z pseudolosowym odstępem może być używany do deszyfrowania tekstu zaszyfrowanego przy użyciu metody szyfrowania z pseudolosowym odstępem. W tym procesie, sekwencja liczb pseudolosowych jest generowana za pomocą metody liniowego kongruencji (LCG) i jest używana do przesunięcia znaków w tekście jawnym.

Na przykład, w systemie komunikacji sieciowej, algorytm deszyfrowania z pseudolosowym odstępem może być używany do odszyfrowywania wiadomości przesłanych przez sieć. Kluczem deszyfrującym jest sekwencja liczb pseudolosowych generowana przez LCG na podstawie klucza prywatnego, który jest używany do szyfrowania wiadomości przed wysłaniem. Dzięki temu, osoby nieupoważnione nie będą mogły odczytać przesłanej wiadomości.

## Algorytm usuwania duplikatów z listy dwukierunkowej

### Pseudokod :page_facing_up:

```
usuńDuplikaty(lista)
Wejście:
lista - wskaźnik na obiekt typu DoubleLinkedList
Wyjście: None
Początek
1. Sprawdź czy lista jest pusta lub NULL, jeśli tak zwróć
2. Ustaw aktualny element na głowę listy
3. Dopóki aktualny element jest różny od NULL
3.1 Ustaw następny na aktualny->następny
3.2 Ustaw duplikat na aktualny->następny
3.3 Dopóki duplikat jest różny od NULL
3.3.1 Jeśli duplikat->dane jest równe aktualny->dane
3.3.1.1 Ustaw duplicateNext na duplikat->następny
3.3.1.2 Wywołaj funkcję usuńNode(lista, duplikat) by usunąć duplikat
3.3.1.3 Ustaw duplikat na duplicateNext
3.3.2 W przeciwnym razie
3.3.2.1 Ustaw duplikat na duplikat->następny
3.4 Ustaw aktualny na następny
4. Koniec pętli
Koniec
```

### Przykład zastosowania

Przykład zastosowania algorytmu usuwania duplikatów z listy dwukierunkowej może być zastosowanie w systemie zarządzania biblioteką.

1. W bibliotece jest lista książek, które są dostępne do wypożyczenia.
2. W systemie zarządzania biblioteką, kiedy ktoś wprowadza nową książkę do biblioteki, system sprawdza czy książka już jest na liście.
3. Jeśli książka jest już na liście, system usuwa duplikat.
4. Dzięki temu algorytmowi system zarządzania biblioteką zawsze ma aktualną i dokładną listę książek dostępnych do wypożyczenia.
5. W tym przypadku algorytm usuwania duplikatów z listy dwukierunkowej jest skutecznym rozwiązaniem, ponieważ pozwala na utrzymanie aktualnej i dokładnej listy książek dostępnych do wypożyczenia bez konieczności ręcznego sprawdzania i usuwania duplikatów.

## Zródła

- [Linear conguential generator](https://en.wikipedia.org/wiki/Linear_congruential_generator)
- [Szyfrowanie z pseudolosowym odstępem](https://eduinf.waw.pl/inf/alg/001_search/0064.php)
- [Usuwanie duplikatów z lsity](https://eduinf.waw.pl/inf/alg/001_search/0093.php)
