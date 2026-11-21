#include <stdio.h>
void bubble_sort(int a[], int n, long *cmp, long *swaps) {
    *cmp = *swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int changed = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            (*cmp)++;
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                (*swaps)++; changed = 1;
            }
        }
        if (!changed) break;
    }
}
void selection_sort(int a[], int n, long *cmp, long *swaps) {
    *cmp = *swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            (*cmp)++;
            if (a[j] < a[min]) min = j;
        }
        if (min != i) {
            int t = a[i]; a[i] = a[min]; a[min] = t; (*swaps)++;
        }
    }
}
void insertion_sort(int a[], int n, long *cmp, long *shifts) {
    *cmp = *shifts = 0;
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0) {
            (*cmp)++;
            if (a[j] <= key) break;
            a[j + 1] = a[j]; (*shifts)++; j--;
        }
        a[j + 1] = key;
    }
}
int main(void) {
    int x[] = {5, 2, 4, 1, 3};
    int n = (int)(sizeof x / sizeof x[0]);
    long c, s;
    bubble_sort(x, n, &c, &s);
    printf("Bubble: "); for (int i=0;i<n;i++) printf("%d ",x[i]);
    printf("comparisons=%ld swaps=%ld\\n",c,s);
    return 0;
}
