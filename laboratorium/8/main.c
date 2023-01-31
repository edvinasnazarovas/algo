#include <stdio.h>
#include <limits.h>
#include <math.h>

int n, V;
int coin[100];
int ans = INT_MAX;
int selectedCoins[100];

void minCoins(int i, int sum, int cnt, int selected[]) {
  if (cnt < ans && sum == V) {
    ans = cnt;
    for (int j = 0; j < cnt; j++) selectedCoins[j] = selected[j];
    return;
  }
  if (i >= n || sum > V || cnt >= ans) return;
  
  selected[cnt] = coin[i];
  minCoins(i + 1, sum + coin[i], cnt + 1, selected);
  minCoins(i + 1, sum, cnt, selected);
}

int main() {
  scanf("%d", &n);
  scanf("%d", &V);
  
  for (int i = 0; i < n; i++) scanf("%d", &coin[i]);
  
  int selected[100];
  minCoins(0, 0, 0, selected);
  if (ans == INT_MAX) {
    printf("No solution found\n");
    return 0;
  }
  printf("No. of coins: %d\n", ans);
  printf("Selected coins: ");
  for (int i = 0; i < ans; i++) printf("%d ", selectedCoins[i]);
  printf("\n");
  return 0;
}
