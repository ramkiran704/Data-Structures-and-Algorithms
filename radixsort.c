#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void radixSort(int arr[], int n) {
    int output[100];  // temporary array
    int count[10];
    int max = getMax(arr, n);
    int exp = 1; // digit place (1s, 10s, 100s...)

    while (max / exp > 0) {
        // initialize count array to 0
        for (int i = 0; i < 10; i++)
            count[i] = 0;

        // count how many numbers have each digit
        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        // cumulative count (position info)
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // build output array (stable sort)
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // copy back to original array
        for (int i = 0; i < n; i++)
            arr[i] = output[i];

        exp *= 10; // move to next digit
    }
}

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    radixSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}