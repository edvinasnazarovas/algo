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
& T(n) = \theta (n^{log_b a}) &\\
\end{flalign}
$$

$$odp.: T(n) = \theta (n^{1.58})$$

## $T(n) = 3T(n/2)+n^2?$

$$
\begin{flalign}
& a = 3 &\\
& b = 2 &\\
& k = 2 &\\
& p = 0 &\\
& b^k = 4 &\\
& a < b^k &\\
& Case\ 3\ =\ T(n) = \theta(n^k log^p n) &\\
& T(n) = \theta (n^2log^0n) &\\
\end{flalign}
$$

$$odp.:\ T(n) = \theta (n^2)$$

## $T(n) = 8T(n/2)+n^3?$

$$
\begin{flalign}
& a = 8 &\\
& b = 2 &\\
& k = 3 &\\
& p = 0 &\\
& b^k = 8 &\\
& a = b^k &\\
& Case\ 2\ =\ T(n) = θ (n^{log_b a}.log^{p+1}n) &\\
& T(n) = \theta (n^{log_2 8}.log^{0 + 1}n) &\\
\end{flalign}
$$

$$odp.:\ T(n) = \theta (n^3logn)$$

## $T(n) = 4T(n/3)+n?$

$$
\begin{flalign}
& a = 4 &\\
& b = 3 &\\
& k = 0 &\\
& p = 0 &\\
& b^k = 8 &\\
& a > b^k &\\
& Case\ 1\ =\ T(n) = \theta (n^{log_b a}) &\\
& T(n) = \theta (n^{log_3 4}) &\\
\end{flalign}
$$

$$odp.:\ T(n) = \theta (n^1.26)$$

## $T(n) = 4T(n/3) + n^2?$

$$
\begin{flalign}
& a = 4 &\\
& b = 3 &\\
& k = 2 &\\
& p = 0 &\\
& b^k = 9 &\\
& a < b^k &\\
& Case\ 3\ =\ T(n) = \theta (n^k log^p n) &\\
& T(n) = \theta (n^2 log^0 n) &\\
\end{flalign}
$$

$$odp.:\ T(n) = \theta (n^2)$$

## $T(n) = 9T(n/3) + n^2?$

$$
\begin{flalign}
& a = 9 &\\
& b = 3 &\\
& k = 2 &\\
& p = 0 &\\
& b^k = 9 &\\
& a = b^k &\\
& Case\ 2\ =\ T(n) = θ (n^{log_b a}.log^{p+1}n) &\\
& T(n) = \theta (n^{log_3 9}.log^{0+1}n) &\\
& T(n) = \theta (n^2.log^1 n) &\\
\end{flalign}
$$

$$odp.:\ T(n) = \theta (n^2 logn)$$
