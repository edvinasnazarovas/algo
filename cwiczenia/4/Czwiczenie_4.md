# Zadania z twierdzenia rekurencji uniwersalnej

### Obliczyć następne rekurencji, w których $T(1) = 1\ i\ T(n)\ dla\ n\geq 2\ wynosi:$

- $T(n) = 3T(n/2)+n?$
- $T(n) = 3T(n/2)+n^2?$
- $T(n) = 8T(n/2)+n^3?$
- $T(n) = 4T(n/3)+n?$
- $T(n) = 4T(n/3) + n^2?$
- $T(n) = 9T(n/3) + n^2?$

## $T(n) = 3T(n/2)+n?$

$$
\begin{flalign}
& a = 3 &\\
& b = 2 &\\
& k = 0 &\\
& p = 0 &\\
& b^k = 2 &\\
& Case\ 1\ =\ T(n) = \theta(n^{log_b a}) &\\
& log_b a = log_2 3 = 1.58 &\\
\end{flalign}
$$

## $T(n) = 3T(n/2)+n^2?$


