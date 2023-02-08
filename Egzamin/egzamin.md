
Pytanie testowe / 27) 'Złożoność sortowania pozyzyjnego (radix sort):': 
Odpowiedzi: 
        d) 
𝐴
(
𝑛
)
=
𝛩
(
𝑛
𝑘
)


Pytanie testowe / 19) 'Jaka z notacji asymptotycznych jest ze złożonością liniowo-logarytmiczna?': 
Odpowiedzi: 
        f) 
𝐴
(
𝑛
)
=
𝛩
(
𝑛
𝑙
𝑜
𝑔
(
𝑛
)
)


Pytanie testowe / 18) 'Jakie z podanych operacji niemozliwe w liscie dwukierunkowej.': 
Odpowiedzi: 
        h) wszystko nieprawidłowe 


Pytanie testowe / 15) 'Jaka z podanych definicji jest definicja chciwego algorytmu.': 
Odpowiedzi: 
        a) Algorytm, który wybiera najlepszy wybór na każdym kroku, zamiast uwzględnienie wszystkich sekwencji kroków, które mogą prowadzić do optymalnego rozwiązania. 


Pytanie testowe / 12) 'Jaka z notacji asymptotycznych jest ze złożonością pod-wykładniczna?': 
Odpowiedzi: 
        g) 
𝐴
(
𝑛
)
=
𝛩
(
2
𝑛
)


Pytanie testowe / 11) 'Jaka z notacji asymptotycznych jest ze złożonością stalą?': 
Odpowiedzi: 
        d) 
𝑆
(
𝑛
)
=
3
=
𝛩
(
1
)


Pytanie testowe / 8) 'Ktory(e) sa sposobami udowodnię poprawności algorytmów': 
Odpowiedzi: 
        b) matetamtycnza indukcja 
d) kontrargumentowanie 


Pytanie testowe / 7) 'W jakiej postaci możliwa reprezentacji algorytmu?': 
Odpowiedzi: 
        a) pseudokod 
c) schemat blokowy 


Pytanie testowe / 6) 'Jakie z podanych operacji mozliwe w kolejkie.': 
Odpowiedzi: 
        a) push (dodanie elementa) 
b) pop (wyjmowanie elementa) 
c) print (wyswetlenia elementow) 


Pytanie testowe / 1) 'Jaka z podanych definicji jest definicja algorytmu?': 
Odpowiedzi: 
        a) dokładny opis, przepis, np. w postaci listy kolejnych kroków, jak coś wykonać, etc. (nie tylko zadania obliczeniowe, np. przepis wykonania pewnej potrawy albo dokonania pewnej procedury prawnej, etc. 


Pytanie zlozonosc / 4) 'Mamy funkcja
𝑇
(
𝑛
)
=
2
(
𝑛
−
1
)
2
4
−
𝑛
2
2
. Jaka jest złożoność asymptotyczna ?': 
Odpowiedz: 
        c) 
𝛩
(
𝑛
2
)


Pytanie poprawnosc / 4) 'Czy wskazany algorytm jest całkowicie poprawny?': 
Pseudokod: 
```c
findMax(array, len) {
    i = 0, max = array[0];
    
    while (i < len) {
      if (max < array[i]) {
        max = array[i];
      }
      i = i + 1;
    }
    
    return max;
}
```
Odpowiedz: 
        a) Tak 


Pytanie rekursja / 2) 'Obliczyć następne rekurencja, w której
𝑇
(
1
)
=
1
i
𝑇
(
𝑛
)
=
3
𝑇
(
𝑛
/
3
)
+
𝑛
2
dla
𝑛
>=
2
 jest rowny': 
Odpowiedzi: 
        b) 
𝛩
(
𝑛
3
)
