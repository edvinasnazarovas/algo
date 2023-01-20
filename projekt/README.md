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
