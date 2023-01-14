/*
 * Nazwa pliku: Zadanie_4.c
 * Autor: Edvinas
 * Data: 2023-01-14
 * Opis: Obliczyc funkcja y = ax^2 znaczenia, gdy a - stałe, x jest wybierany z tablicy X(n), wyniiki funkcji zapisywac Y(n)
 */

#include <stdio.h>

int main(void) {
    double a, x[10], y[10];
    int n, i;

    printf("Wprowadz stala a: ");
    scanf("%lf", &a);
    printf("Wprowadz liczbe elementow tablicy X: ");
    scanf("%d", &n);

    printf("Wprowadz elementy tablicy X: \n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    for (i = 0; i < n; i++) {
        y[i] = a * x[i] * x[i];
    }

    printf("Tablica Y:\n");
    for (i = 0; i < n; i++) {
        printf("%lf\n", y[i]);
    }

    return 0;
}
