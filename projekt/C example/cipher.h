#ifndef CIPHER_H_INCLUDED
#define CIPHER_H_INCLUDED

#include "lcg.h"
#include <ctype.h>
#include <string.h>

void cipher(unsigned long long key, unsigned long long m, unsigned long long a,
            unsigned long long c, char *s) {
  int i;
  int randomNums[256];

  linearCongruentialMethod(key, m, a, c, randomNums, 256);
  for (i = 0; i < strlen(s); i++) {

    key = randomNums[i];

    s[i] = toupper(s[i]);
    if ((s[i] >= 'A') && (s[i] <= 'Z'))
      s[i] = 65 + (s[i] - 65 + key % 26) % 26;
  }
}

void decipher(unsigned long long key, unsigned long long m,
              unsigned long long a, unsigned long long c, char *s) {
  int i;
  int randomNums[256];

  linearCongruentialMethod(key, m, a, c, randomNums, 256);
  for (i = 0; i < strlen(s); i++) {
    key = randomNums[i];

    s[i] = toupper(s[i]);
    if ((s[i] >= 'A') && (s[i] <= 'Z'))
      s[i] = 65 + (s[i] - 65 - key % 26 + 26) % 26;
  }
}

#endif // SZYFR_H_INCLUDED
