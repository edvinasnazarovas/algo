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
removeDuplicates(list)
Input:
list - pointer to a DoubleLinkedList object
Output: None
Begin
1. Check if the list is NULL or empty, if true return
2. Set current to the head of the list
3. While current is not NULL
3.1 Set next to current->next
3.2 Set duplicate to current->next
3.3 While duplicate is not NULL
3.3.1 If duplicate->data is equal to current->data
3.3.1.1 Set duplicateNext to duplicate->next
3.3.1.2 Call deleteNode(list, duplicate) to remove the duplicate node
3.3.1.3 Set duplicate to duplicateNext
3.3.2 Else
3.3.2.1 Set duplicate to duplicate->next
3.4 Set current to next
4. End While
End
```
