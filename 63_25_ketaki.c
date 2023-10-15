#include<stdio.h>
#include<conio.h>
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 1;
}

int main() {
    int arr[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(arr) / sizeof(arr[0);
    int target = 25;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1) {
        printf("Element %d is not found in the array.\n", target);
    } else {
        printf("Element %d is found at index %d.\n", target, result);
    }

    return 0;
}
