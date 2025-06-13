#ifndef GRADE_MAP_H
#define GRADE_MAP_H

#define PLUSMINUS_MAPPER "plusminus"
#define PASSFAIL_MAPPER "passfail"
#define STANDARD_MAPPER "standard"

void grade_mapping(const int *scores, int size, char **grades, const char *mapper_strategy);

#endif
