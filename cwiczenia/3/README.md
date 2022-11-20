# Cwiczenie 3

### Zadania

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
