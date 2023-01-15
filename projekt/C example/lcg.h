#ifndef LCG_H_INCLUDED
#define LCG_H_INCLUDED

void linearCongruentialMethod(int Xo, int m, int a, int c, int randomNums[],
                              int noOfRandomNums) {
  randomNums[0] = Xo;

  for (int i = 1; i < noOfRandomNums; i++) {
    randomNums[i] = ((randomNums[i - 1] * a) + c) % m;
  }
}

#endif // LCG_H_INCLUDED
