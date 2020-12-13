#include <stdio.h>
#include "../code/sort.h"

int arr[30000];

int main(int argc, char const* argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    threequick(arr, 0, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}