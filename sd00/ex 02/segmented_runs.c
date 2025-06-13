#include"segmented_runs.h"

int find_next_separator(const int *arr, int size, int start_pos)
{
    int i;
	
	i = start_pos;
    while (i < size)
    {
        if (arr[i] == -1)
            return i;
        i++;
    }
    return size;
}

int are_three_consecutive(int a, int b, int c)
{
    return (a + 1 == b && b + 1 == c);
}

int has_consecutive_sequence(const int *arr, int start, int end_exclusive)
{
    int i;
	
	i = start;
    while (i + 2 < end_exclusive)
    {
        if (are_three_consecutive(arr[i], arr[i + 1], arr[i + 2]))
            return 1;
        i++;
    }
    return 0;
}

int is_valid_segment(const int *arr, int start, int end_exclusive)
{
    int length = end_exclusive - start;

    if (length < 3)
        return 0;

    return has_consecutive_sequence(arr, start, end_exclusive);
}

int count_segments(const int *arr, int size)
{
    int count = 0;
    int current_start = 0;

    while (current_start < size)
    {
        int current_end = find_next_separator(arr, size, current_start);

        if (is_valid_segment(arr, current_start, current_end))
            count++;

        current_start = current_end + 1;
    }
    return count;
}


// #include <stdio.h>
// int main() {
//     // Test 1: esempio dell'esercizio
//     int arr1[] = {2, 3, 4, -1, 5, 6, -1, 1, 2, 3, 4};
//     int size1 = sizeof(arr1)/sizeof(arr1[0]);
//     printf("Test 1: %d (expected: 2)\n", count_segments(arr1, size1));

//     // Test 2: segmento con sequenza all'inizio
//     int arr2[] = {1, 2, 3, -1, 4, 5};
//     int size2 = sizeof(arr2)/sizeof(arr2[0]);
//     printf("Test 2: %d (expected: 1)\n", count_segments(arr2, size2));

//     // Test 3: segmento con sequenza alla fine
//     int arr3[] = {-1, 5, 6, 7, 8};
//     int size3 = sizeof(arr3)/sizeof(arr3[0]);
//     printf("Test 3: %d (expected: 1)\n", count_segments(arr3, size3));

//     // Test 4: nessuna sequenza di 3
//     int arr4[] = {1, 2, -1, 3, 4, -1, 5, 1};
//     int size4 = sizeof(arr4)/sizeof(arr4[0]);
//     printf("Test 4: %d (expected: 0)\n", count_segments(arr4, size4));

//     // Test 5: sequenza non consecutiva
//     int arr5[] = {1, 3, 5, -1, 2, 3, 4};
//     int size5 = sizeof(arr5)/sizeof(arr5[0]);
//     printf("Test 5: %d (expected: 1)\n", count_segments(arr5, size5));

//     // Test 6: array vuoto
//     int arr6[] = {};
//     int size6 = 0;
//     printf("Test 6: %d (expected: 0)\n", count_segments(arr6, size6));

//     // Test 7: solo separatori
//     int arr7[] = {-1, -1, -1};
//     int size7 = sizeof(arr7)/sizeof(arr7[0]);
//     printf("Test 7: %d (expected: 0)\n", count_segments(arr7, size7));

//     // Test 8: ultimo segmento senza sentinella
//     int arr8[] = {1, 2, 3, 4, -1, 5, 6, 7, 8};
//     int size8 = sizeof(arr8)/sizeof(arr8[0]);
//     printf("Test 8: %d (expected: 2)\n", count_segments(arr8, size8));

//     return 0;
// }
