#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grade_map.h"

const char* get_plusminus_grade(int score)
{
    if (score >= 97) return "A+";
    if (score >= 93) return "A";
    if (score >= 90) return "A-";
    if (score >= 87) return "B+";
    if (score >= 83) return "B";
    if (score >= 80) return "B-";
    if (score >= 77) return "C+";
    if (score >= 73) return "C";
    if (score >= 70) return "C-";
    if (score >= 67) return "D+";
    if (score >= 63) return "D";
    if (score >= 60) return "D-";
    return "F";
}

const char* get_passfail_grade(int score)
{
    if (score >= 60) return "P";
    return "F";
}

const char* get_standard_grade(int score)
{
    if (score >= 90) return "A";
    if (score >= 80) return "B";
    if (score >= 70) return "C";
    if (score >= 60) return "D";
    return "F";
}

void grade_mapping(const int *scores, int size, char **grades, const char *mapper_strategy)
{
    int i = 0;
    const char *grade;

    while (i < size)
    {
        if (strcmp(mapper_strategy, PLUSMINUS_MAPPER) == 0)
            grade = get_plusminus_grade(scores[i]);
        else if (strcmp(mapper_strategy, PASSFAIL_MAPPER) == 0)
            grade = get_passfail_grade(scores[i]);
        else if (strcmp(mapper_strategy, STANDARD_MAPPER) == 0)
            grade = get_standard_grade(scores[i]);
        else
            grade = get_plusminus_grade(scores[i]);

        grades[i] = malloc(strlen(grade) + 1);
        if (grades[i])
            strcpy(grades[i], grade);

        i++;
    }
}



// int main()
// {
//     int scores[] = {98, 85, 72, 55, 91, 67, 88, 76, 94, 45};
//     int size = sizeof(scores) / sizeof(scores[0]);
//     char **grades = malloc(size * sizeof(char*));
//     int i;
    
//     printf("Testing Plus/Minus Mapping:\n");
//     printf("Score -> Grade\n");
//     printf("--------------\n");
    
//     grade_mapping(scores, size, grades, PLUSMINUS_MAPPER);
    
//     for (i = 0; i < size; i++) {
//         printf("%3d   -> %s\n", scores[i], grades[i]);
//         free(grades[i]); // Free allocated memory
//     }
    
//     printf("\nTesting Pass/Fail Mapping:\n");
//     printf("Score -> Grade\n");
//     printf("--------------\n");
    
//     grade_mapping(scores, size, grades, PASSFAIL_MAPPER);
    
//     for (i = 0; i < size; i++) {
//         printf("%3d   -> %s\n", scores[i], grades[i]);
//         free(grades[i]); // Free allocated memory
//     }
    
//     printf("\nTesting Standard Mapping:\n");
//     printf("Score -> Grade\n");
//     printf("--------------\n");
    
//     grade_mapping(scores, size, grades, STANDARD_MAPPER);
    
//     for (i = 0; i < size; i++) {
//         printf("%3d   -> %s\n", scores[i], grades[i]);
//         free(grades[i]); // Free allocated memory
//     }
    
//     free(grades);
//     return 0;
// }