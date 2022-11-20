# Cwiczenie 3

## Zadanie 1

$$
\begin{flalign}
& f(n) = \theta(g(n)) &\\
& f(n) = 2n + 1 &\\
& g(n) = 2n &\\
\end{flalign}
$$

$$
\begin{flalign}
& c1.g(n)\quad <=\quad f(n)\quad <=\quad c2.g(n) &\\
\end{flalign}
$$

$$
\begin{flalign}
& n_0=3 &\\
  \end{flalign}
$$

Rozwiązujemy c1

$$
\begin{flalign}
& 2 * 3 + 1 = 7 &\\
& c_1(2 * 3) <= 7 &\\
& 6c_1 <= 7 &\\
& c_1 <= 1 &\\
\end{flalign}
$$

Rozwiązujemy c2

$$
\begin{flalign}
& 2 * 3 + 1 = 7 &\\
& c_2(2 * 3) => 7 &\\
& 6c_2 => 7 &\\
& c_2 => 2 &\\
\end{flalign}
$$

Rozwiązujemy theta

$$
\begin{flalign}
& c1.g(n)\quad <=\quad f(n)\quad <=\quad c2.g(n) &\\
& 1 * (2 * 3)\quad <=\quad 2 * 3 + 1 \quad <=\quad 2 * (2 * 3) &\\
& 6 <= 7 <= 12 &\\
\end{flalign}
$$

$$
\begin{flalign}
& f(n) \in \theta(g(n)) &\\
& n => 3 &\\
& c_1 <= 1 \quad c_2 => 2 &\\
\end{flalign}
$$

## Zadanie 2
$$
\begin{flalign}
& (x + y)^2\in\theta(x^2+y^2) &\\
& f(n) = (x + y)^2 &\\
& x = 2 \quad y = 2 &\\
& (2 + 2) = 16 &\\
& (2^2 + 2^2) * c_1 \leq 16 &\\
& 8c_1 \leq 16 &\\
& c_1 \leq 2 &\\
&8c_2 \geq 16 &\\
&c_2 \geq 2 &\\
& c_1.g(n) \leq f(n) \leq c_2.g(n) &\\
& 16 \leq 16 \leq 16 &\\
& odp.:f(n)\in\theta(g(n))\ dla:\ c_1\leq2,\quad c_2\geq2,\quad n=16 &\\
\end{flalign}
$$

## Zadanie 3
$$
\begin{flalign}
& 17\in\theta(1) &\\
& 1c_1 \leq 17 &\\
& c_1 \leq 1 &\\
& 1c_2\geq 17 &\\
& 1c_2\geq1 & \\
& c_1.g(n) \leq 17 \leq c_2.g(n) &\\
& 17 \leq 17 \leq 17 &\\
& odp.:17\in\theta(1) &\\
\end{flalign}
$$

## Zadanie 4
$$
\begin{flalign}
& 2(n-1)/2\in\theta(n^2) &\\
& n = 3 &\\
& 2(3-1)/2=2 &\\
& c_1(2^2) \leq 2 &\\
& 4c_1\leq2 &\\
&c_1 \leq 0 &
& c_2(2^2) \geq 2 &\\
& 4c_2\geq2 &\\
&c_2\geq1&\\
&c_1.g(n) \leq f(n) \leq c_2.g(n) &\\
& odp.:2(n-1)/2\ni\theta(n^2),\ czyli\ 2(n-1)/2\ nie\ jest\ \theta(n^2) &\\
\end{flalign}
$$

## Zadanie 5
$$
\begin{flalign}
& max(n^3, 10n^2)\in\theta(n^3) &\\
& f(n) = max(n^3, 10n^2) &\\
& n=11 &\\
& max(11^3, 10*11^2)=1331 &\\
& c_1(11^3)\leq1331 &\\
& 1331c_1\leq1331 &\\
& c_1\leq1 &\\
& 1331c_2\geq1331 &\\
& c_2\geq1 &\\
& c_1.g(n) \leq f(n) \leq c_2.g(n) &\\
& 1331 \leq 1331 \leq 1331 &\\
& odp.:max(n^3, 10n^2)\in\theta(n^3)\ dla:\ n=11,\ c_1=1,\ c_2=1 &\\
\end{flalign}
$$

## Uporządkuj następujące funkcje według rosnącej
17</br>
loglogn</br>
logn</br>
log^2n</br>
n</br>

## Oblicz złożoność czasową dla każdego fragmentu kodu ćwiczenia.
```c
1 function someFunction(n) {
2       i, j = 0;
3       for (i; i < n*1000 ; i++) {
4           for (j; j < n*20; j++) {
5               printf("%d", i + j);
6           }
7       }
9   }
```
linija 2: O(1)</br>
linija 3: iter k i=n*1000+k-1=n</br>
k - 1 = n - n * 1000</br>
$$ k = n - n_1000 + 1 $$
O(n)</br>
linija 4: iter k i=n*20+k-1</br>
k - 1 = n - n * 20</br
$$ k = n - n_20 + 1 $$
O(n)</br>
$$Złożoność\ czasowa\ =\ O(n^2)$$</br></br>

```c
1 function someFunction(n) {
2       i, j, k, l = 0;
3       for (i; i < n ; i++) {
4           for (j; j < n; j++) {
5               for (k; k < n; j++) {
6                   for (l; l < 10; j++) {
7                       printf("%d", i + j + k + l);
8                   }
9              }
10           }
11       }
12  }
```
linija 2: O(1)</br>
linija 3: O(n)</br>
linija 4: O(n)</br>
linija 5: O(n)</br>
linija 6: O(1)</br>
$$Złożoność\ czasowa\ =\ O(n^3)$$</br></br>

## Notacja Big O
```c
1 function someFunction(n) {
2       i = 0;
3       for (i; i < 1000 ; i++) {
4           printf("%d", i);
5       }
6   }
```
$$O(1)$$</br>

```c
1 function someFunction(n) {
2       i = 0;
3       for (i; i < n * 10 ; i++) {
4           printf("%d", i);
5       }
6   }
```
$$O(n*10)$$</br>

```c
1 function someFunction(n) {
2       i = 0;
3       for (i; i < n  ; i = i * 2) {
4           printf("%d", i);
5       }
6   }
            
```
$$O(logn)$$</br>

```c
function someFunction(n) {
3       while (true) {
4           printf("%d", n);
5       }
6   }
```
$$O(\infty)$$</br>
