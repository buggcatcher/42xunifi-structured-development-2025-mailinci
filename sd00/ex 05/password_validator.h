#ifndef PASSWORD_VALIDATOR_H
#define PASSWORD_VALIDATOR_H

#define VALID 0
#define INVALID 1

#define MIN_PASSWORD_LENGTH 8
#define SPECIAL_CHARS "@#$%*&"

int is_uppercase(char c);
int is_lowercase(char c);
int is_digit(char c);
int is_special_char(char c);
int str_len(const char *str);
int str_cmp(const char *str1, const char *str2);
int has_upper(const char *str);
int has_lower(const char *str);
int has_digit(const char *str);
int has_special(const char *str);
int has_min_length(const char *str, int min_len);
int passwords_differ(const char *new_pw, const char *curr_pw);

int validate_password(const char *new_pw, const char *curr_pw);

#endif