#include <stdio.h>

int binarySearch(int arr[], int size, int x) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int linearSearch(int arr[], int size, int x) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == x) {
      return i;
    }
  }

  return -1;
}

int main() {
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int arr[size];

  printf("Enter the elements of the array: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  int choice;
  do {
    printf("\nMenu:\n");
    printf("1. Binary Search\n");
    printf("2. Linear Search\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int x;
    int result;

    switch (choice) {
      case 1:
        printf("Enter the element to search for: ");
        scanf("%d", &x);

        result = binarySearch(arr, size, x);

        if (result == -1) {
          printf("Element not found\n");
        } else {
          printf("Element found at index: %d\n", result);
        }

        break;

      case 2:
        printf("Enter the element to search for: ");
        scanf("%d", &x);

        result = linearSearch(arr, size, x);

        if (result == -1) {
          printf("Element not found\n");
        } else {
          printf("Element found at index: %d\n", result);
        }

        break;

      case 3:
        printf("Exiting...\n");
        break;

      default:
        printf("Invalid choice. Please enter a valid option (1, 2, or 3)\n");
    }
  } while (choice != 3);

  return 0;
}
