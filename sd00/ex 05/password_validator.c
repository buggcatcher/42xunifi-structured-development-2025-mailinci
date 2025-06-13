#include "password_validator.h"
#include<stdio.h>

int is_uppercase(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int is_lowercase(char c)
{
    return (c >= 'a' && c <= 'z');
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_special_char(char c)
{
    int i = 0;
    const char *special = SPECIAL_CHARS;
    
    while (special[i] != '\0')
    {
        if (c == special[i])
            return 1;
        i++;
    }
    return 0;
}

int str_len(const char *str)
{
    int len = 0;
    
    if (str == 0)
        return 0;
    
    while (str[len] != '\0')
        len++;
    return len;
}

int str_cmp(const char *str1, const char *str2)
{
    int i;

    if (str1 == NULL && str2 == NULL)
        return 0;
    if (str1 == NULL || str2 == NULL)
        return 1;

    i = 0;
    while (str1[i] && str2[i])
    {
        if (str1[i] != str2[i])
            return 1;
        i++;
    }
    if (str1[i] != str2[i])
        return 1;
    return 0;
}

int has_upper(const char *str)
{
    int i = 0;
    
    if (str == 0)
        return 0;
    
    while (str[i] != '\0')
    {
        if (is_uppercase(str[i]))
            return 1;
        i++;
    }
    return 0;
}

int has_lower(const char *str)
{
    int i = 0;
    
    if (str == 0)
        return 0;
    
    while (str[i] != '\0')
    {
        if (is_lowercase(str[i]))
            return 1;
        i++;
    }
    return 0;
}

int has_digit(const char *str)
{
    int i = 0;
    
    if (str == 0)
        return 0;
    
    while (str[i] != '\0') \
    {
        if (is_digit(str[i]))
            return 1;
        i++;
    }
    return 0;
}

int has_special(const char *str)
{
    int i = 0;
    
    if (str == 0)
        return 0;
    
    while (str[i] != '\0')
    {
        if (is_special_char(str[i]))
            return 1;
        i++;
    }
    return 0;
}

int has_min_length(const char *str, int min_len)
{
    return str_len(str) >= min_len;
}

int passwords_differ(const char *new_pw, const char *curr_pw)
{
    return str_cmp(new_pw, curr_pw) != 0;
}

int validate_password(const char *new_pw, const char *curr_pw)
{
    if (new_pw == 0)
        return INVALID;
    
    if (!has_min_length(new_pw, MIN_PASSWORD_LENGTH))
        return INVALID;   
    if (!has_upper(new_pw))
        return INVALID;
    if (!has_lower(new_pw))
        return INVALID;
    if (!has_digit(new_pw))
        return INVALID;
    if (!has_special(new_pw))
        return INVALID;
    if (!passwords_differ(new_pw, curr_pw))
        return INVALID;
    
    return VALID;
}

// int main(int argc, char **argv)
// {
//     int result;
    
//     if (argc != 2)
//     {
//         printf("Usage: %s <password>\n", argv[0]);
//         return 1;
//     }
    
//     result = validate_password(argv[1], "");
    
//     if (result == VALID)
//         printf("valid\n");
//     else
//         printf("invalid\n");
    
//     return 0;
// }