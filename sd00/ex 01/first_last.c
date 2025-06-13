#include"first_last.h"

int find_first_occurrence(int arr[], int size, int target)
{
    int i;
	
	i = 0;
    while (i < size)
    {
        if (arr[i] == target)
            return i;
        i++;
    }
    return -1;
}

int find_last_occurrence(int arr[], int size, int target)
{
    int i;
    int last_position;
	
    last_position = -1;
	i = 0;
    while (i < size)
    {
        if (arr[i] == target)
            last_position = i;
        i++;
    }
    return last_position;
}

void first_last(int arr[], int size, int target, int *first, int *last)
{
    *first = find_first_occurrence(arr, size, target);
    *last = find_last_occurrence(arr, size, target);
}

// #include <stdio.h>
// int main(void)
// {
//     int first, last;

//     // Test 1: target presente più volte
//     int arr1[] = {5, 3, 7, 5, 9, 5};
//     first_last(arr1, 6, 5, &first, &last);
//     printf("Test 1 - Target 5: first = %d, last = %d\n", first, last); // expected: 0, 5

//     // Test 2: target presente una sola volta
//     int arr2[] = {4, 2, 8, 6};
//     first_last(arr2, 4, 8, &first, &last);
//     printf("Test 2 - Target 8: first = %d, last = %d\n", first, last); // expected: 2, 2

//     // Test 3: target assente
//     int arr3[] = {1, 2, 3, 4};
//     first_last(arr3, 4, 9, &first, &last);
//     printf("Test 3 - Target 9: first = %d, last = %d\n", first, last); // expected: -1, -1

//     // Test 4: tutti gli elementi sono uguali al target
//     int arr4[] = {7, 7, 7, 7};
//     first_last(arr4, 4, 7, &first, &last);
//     printf("Test 4 - Target 7: first = %d, last = %d\n", first, last); // expected: 0, 3

//     // Test 5: array vuoto
//     int arr5[] = {};
//     first_last(arr5, 0, 3, &first, &last);
//     printf("Test 5 - Empty array: first = %d, last = %d\n", first, last); // expected: -1, -1

//     return 0;
// }
