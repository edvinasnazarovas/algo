/*
 * Nazwa pliku: match.h
 * Autor: Edvinas
 * Data: 2023-01-23
 * Opis: Realizacja pseudokodu z cwiczen i algorytmów dopasowania wzorców z wykładu 6
 */

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LETTERS 26
#define MAX_WORDS 50
#define MAX_CHARS 256
#define q 11

void naiveSearch(char *text, char *pattern) {
    int n = (int)strlen(text);
    int m = (int)strlen(pattern);
    int i, j;
    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            printf("\n pattern found at index %d", i);
    }
}

void searchRabinKarp(char *text, char *pattern) {
    int i, j;
    int n = (int)strlen(text);
    int m = (int)strlen(pattern);
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * MAX_CHARS) % q;

    for (i = 0; i < m; i++) {
        p = (MAX_CHARS * p + pattern[i]) % q;
        t = (MAX_CHARS * t + text[i]) % q;
    }

    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                printf("\n pattern found at index %d", i);
        }

        if (i < n - m) {
            t = (MAX_CHARS * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
}

void badCharHeuristic(char *str, int size, int badchar[MAX_CHARS]) {
    int i;
    for (i = 0; i < MAX_CHARS; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void boyerMoore(char *txt, char *pat) {
    int m = (int)strlen(pat);
    int n = (int)strlen(txt);
    int badchar[MAX_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j])
            j--;
        if (j < 0) {
            printf("\n pattern occurs at shift = %d", s);
            s += (s + m < n) ? m - badchar[(int)txt[s + m]] : 1;
        } else
            s += (int)fmax(1, j - badchar[(int)txt[s + j]]);
    }
}

void computeLPSArray(char *pat, int M, int *lps) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *pat, char *txt) {
    int M = (int)strlen(pat);
    int N = (int)strlen(txt);

    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

// Znaleźć i skasować same długie słowo w tekście.
void deleteLongestWord(char *text) {
  char longestWord[100] = "";
  char tempWord[100] = "";
  int i, j, textLength, longestWordLength, tempWordLength;

  textLength = strlen(text);
  longestWordLength = 0;

  for (i = 0; i < textLength; i++) {
    if (text[i] != ' ' && text[i] != '.') {
      tempWord[j] = text[i];
      j++;
    } else {
      tempWord[j] = '\0';
      tempWordLength = strlen(tempWord);
      if (tempWordLength > longestWordLength) {
        longestWordLength = tempWordLength;
        strcpy(longestWord, tempWord);
      }
      j = 0;
      memset(tempWord, 0, sizeof(tempWord));
    }
  }

  printf("Slowo: %s\n", longestWord);

  char *p = strstr(text, longestWord);
  if (p) {
    int len = strlen(longestWord);
    memmove(p, p + len, strlen(p + len) + 1);
  }

  printf("Rezultat: %s\n", text);
}

// Znaleźć ile jest liczb w tekście.
int countNumbers(char *text) {
  int count = 0;
  int i;
  for (i = 0; text[i] != '\0'; i++) {
    if (isdigit(text[i])) {
      count++;
    }
  }
  return count;
}

// Znaleźć te same litery w dwoch wzorach.
void findCommonLetters(char *pattern1, char *pattern2) {
  int len1 = (int)strlen(pattern1);
  int len2 = (int)strlen(pattern2);
  bool hashset[MAX_LETTERS] = {false};
  bool printed[MAX_LETTERS] = {false};
  int i;

  for (i = 0; i < len1; i++) {
    int index = pattern1[i] - 'a';
    hashset[index] = true;
  }

  printf("Common letters: ");
  for (i = 0; i < len2; i++) {
    int index = pattern2[i] - 'a';
    if (hashset[index] && !printed[index]) {
      printf("%c ", pattern2[i]);
      printed[index] = true;
    }
  }
  printf("\n");
}

// Wyprowadzić wszystkie nie powtarzające się słowa.
void extractNonRepeatingWords(char *text) {
  int len = (int)strlen(text);
  char words[MAX_WORDS][50];
  int wordCount = 0;
  int i, j;

  for (i = 0; i < len; i++) {
    j = 0;
    while (i < len && text[i] != ' ') {
      words[wordCount][j++] = text[i++];
    }
    words[wordCount][j] = '\0';
    wordCount++;
  }

  bool hashset[MAX_WORDS] = {false};

  for (i = 0; i < wordCount; i++) {
    if (!hashset[i]) {
      int k;
      for (k = i + 1; k < wordCount; k++) {
        if (strcmp(words[i], words[k]) == 0) {
          hashset[i] = true;
          break;
        }
      }
      if (!hashset[i])
        printf("%s, ", words[i]);
    }
  }

  printf("\n");
}

// Sprawdzic czy słowo jest anagram.
bool isAnagram(char *word1, char *word2) {
  int len1 = (int)strlen(word1);
  int len2 = (int)strlen(word2);

  if (len1 != len2) {
    return false;
  }

  int letters1[MAX_CHARS] = {0};
  int i;
  for (i = 0; i < len1; i++) {
    letters1[(int)word1[i]]++;
  }

  int letters2[256] = {0};
  for (i = 0; i < len2; i++) {
    letters2[(int)word2[i]]++;
  }

  for (i = 0; i < 256; i++) {
    if (letters1[i] != letters2[i]) {
      return false;
    }
  }

  return true;
}
