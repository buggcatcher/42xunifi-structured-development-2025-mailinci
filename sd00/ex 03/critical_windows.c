#include "critical_windows.h"

int calculate_window_sum(const int *readings, int start_pos)
{
    int sum = 0;
    int i = 0;

    while (i < 5)
    {
        sum += readings[start_pos + i];
        i++;
    }
    return sum;
}

int count_values_above_70(const int *readings, int start_pos)
{
    int count = 0;
    int i = 0;

    while (i < 5)
    {
        if (readings[start_pos + i] >= 70)
            count++;
        i++;
    }
    return count;
}

int has_value_over_150(const int *readings, int start_pos)
{
    int i = 0;

    while (i < 5)
    {
        if (readings[start_pos + i] > 150)
            return 1;
        i++;
    }
    return 0;
}

int is_critical_window(const int *readings, int start_pos)
{
    int count70 = count_values_above_70(readings, start_pos);
    int over150 = has_value_over_150(readings, start_pos);
    int sum = calculate_window_sum(readings, start_pos);
    float average = (float)sum / 5.0f;

    return (count70 >= 3 && !over150 && average >= 90.0f);
}

int count_critical_windows(const int *readings, int size)
{
    int count = 0;
    int i = 0;

    while (i <= size - 5)
    {
        if (is_critical_window(readings, i))
            count++;
        i++;
    }
    return count;
}

// int main() {
//     int readings[] = {95, 100, 85, 70, 90, 120, 100, 95, };
//     int size = sizeof(readings) / sizeof(readings[0]);

//     int result = count_critical_windows(readings, size);
//     printf("Numero di finestre critiche: %d\n", result);
//     return 0;
// }