#include "average.h"

int calculate_valid_sum(const int *arr, int size, int *valid_count)
{
    int i;
    int sum;
    
	i = 0;
	sum = 0;
	*valid_count = 0;
    while (i < size)
    {
        if (is_valid_score(arr[i]))
        {
            sum += arr[i];
            (*valid_count)++;
        }
        i++;
    }
    return (sum);
}

int is_valid_score(int score)
{
    return (score >= 0 && score <= 100);
}

float average(const int *arr, int size)
{
    int valid_count;
    int sum;
	
	sum = calculate_valid_sum(arr, size, &valid_count);
    if (valid_count == 0)
        return 0.0f;
    
    return ((float)sum / valid_count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int arr1[] = {90, -1, 105, 80, 100};  // solo 90, 80, 100 sono validi
// 	int arr2[] = {-10, 150, 200};         // tutti invalidi
// 	int arr3[] = {50, 50, 50};            // tutti validi

// 	float avg1 = average(arr1, 5);
// 	float avg2 = average(arr2, 3);
// 	float avg3 = average(arr3, 3);

// 	printf("Average 1: %.2f\n", avg1);  // dovrebbe stampare 90.00
// 	printf("Average 2: %.2f\n", avg2);  // dovrebbe stampare 0.00
// 	printf("Average 3: %.2f\n", avg3);  // dovrebbe stampare 50.00
// 	return 0;
// }