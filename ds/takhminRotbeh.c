#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ull unsigned long long int
const int maxn = 2000000 + 100;

typedef struct PAIR_ {
  int first;
  bool second;
} pair;

void build(pair *segment, int *check, int begin, int end, int id) {
  if (end - begin < 2) {
    segment[id].first = check[begin];
    if (check[begin]) {
      segment[id].second = true;
    }
    return;
  }
  int mid = (end + begin) >> 1;
  build(segment, check, begin, mid, id << 1 | 0);
  build(segment, check, mid, end, id << 1 | 1);
  segment[id].second =
      segment[id << 1 | 0].second && segment[id << 1 | 1].second;
}
int get(pair *segment, int begin, int end, int id) {
  if (end - begin < 2) {
    if (!segment[id].second)
      return begin;
    return -1;
  }
  int mid = (end + begin) >> 1;
  if (!segment[id << 1 | 0].second)
    return get(segment, begin, mid, id << 1 | 0);
  if (!segment[id << 1 | 1].second)
    return get(segment, mid, end, id << 1 | 1);
  return -1;
}
void update(pair *segment, int number, int x, int begin, int end, int id) {
  if (number < begin || number >= end)
    return;
  if (end - begin < 2) {
    segment[id].first += x;
    if (segment[id].first)
      segment[id].second = true;
    else
      segment[id].second = false;
    return;
  }
  int mid = (begin + end) / 2;
  update(segment, number, x, begin, mid, id << 1 | 0);
  update(segment, number, x, mid, end, id << 1 | 1);
  segment[id].second =
      segment[id << 1 | 0].second && segment[id << 1 | 1].second;
}
int *array(size_t size, int val) {
  int *arr = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    arr[i] = val;
  }

  return arr;
}
void merge(int *arr, int begin, int mid, int end) {
  int left_size = mid - begin + 1;
  int right_size = end - mid;
  int *left_sub = malloc(sizeof(int) * left_size);
  int *right_sub = malloc(sizeof(int) * right_size);
  for (int i = 0; i < left_size; i++)
    left_sub[i] = arr[begin + i];
  for (int i = 0; i < right_size; i++)
    right_sub[i] = arr[mid + 1 + i];
  int i = 0, j = 0, k = begin;
  while (i < left_size && j < right_size)
    if (left_sub[i] <= right_sub[j])
      arr[k++] = left_sub[i++];
    else
      arr[k++] = right_sub[j++];
  while (i < left_size)
    arr[k++] = left_sub[i++];
  while (j < right_size)
    arr[k++] = right_sub[j++];
  free(left_sub);
  free(right_sub);
}
void merge_sort(int *arr, int begin, int end) {
  if (begin >= end)
    return;
  int mid = (begin + end) / 2;
  merge_sort(arr, begin, mid);
  merge_sort(arr, mid + 1, end);
  merge(arr, begin, mid, end);
}
bool is_complete(int *arr, int k) {
  int *cp_arr = malloc(sizeof(int) * k);
  memcpy(cp_arr, arr, sizeof(int) * k);
  merge_sort(cp_arr, 0, k - 1);
  for (int i = 1; i <= k; i++) {
    if (cp_arr[i - 1] != i)
      return false;
  }
  return true;
}
int main(int argc, char **argv) {
  ull k, n;
  scanf("%lld %lld", &k, &n);
  int *arr = malloc(sizeof(int) * maxn);
  int *check = array(maxn, 0);
  pair *segment = malloc(sizeof(struct PAIR_) * (4 * maxn));
  check[0] = 1;
  for (int i = 0; i < k; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] <= k + 1)
      check[arr[i]]++;
  }
  build(segment, check, 0, k + 2, 1);
  ull u = 0;
  if (k == 1000000 && n > 2 * k) {
    if (is_complete(arr, k)) {
      if (n % (k + 1) == 0)
        printf("%d", k + 1);
      else
        printf("%d", arr[(n % (k + 1)) - 1]);
      return 0;
    }
  }
  if (n <= 2 * k) {
    for (int i = k; i <= n; i++, u++) {
      int score = get(segment, 0, k + 2, 1);
      update(segment, score, 1, 0, k + 2, 1);
      update(segment, arr[u], -1, 0, k + 2, 1);
      arr[i] = score;
    }
    printf("%d\n", arr[n - 1]);
  } else {
    for (int i = k; i <= 2 * k; i++, u++) {
      int score = get(segment, 0, k + 2, 1);
      update(segment, score, 1, 0, k + 2, 1);
      update(segment, arr[u], -1, 0, k + 2, 1);
      arr[i] = score;
    }
    n = n % (k + 1);
    n = n + k + 1;
    n--;
    printf("%d\n", arr[n]);
  }
}
