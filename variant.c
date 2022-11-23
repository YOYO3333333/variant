#include "variant.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
size_t my_strlen(const char *s)
{
    const char *st;
    for (st = s; *st; ++st)
    {
        continue;
    }
    return (st - s);
}
int my_strcmp(const char *s1, const char *s2)
{
    size_t len1 = my_strlen(s1);
    size_t len2 = my_strlen(s2);
    if (len1 > len2)
    {
        for (size_t i = 0; i < len2; i++)
        {
            if (s1[i] == s2[i])
                continue;
            else if (s1[i] < s2[i])
                return -1;
            else if (s1[i] > s2[i])
                return 1;
        }
        return 1;
    }
    if (len1 < len2)
    {
        for (size_t i = 0; i < len1; i++)
        {
            if (s1[i] == s2[i])
                continue;
            else if (s1[i] < s2[i])
                return -1;
            else if (s1[i] > s2[i])
                return 1;
        }
        return -1;
    }
    if (len1 == len2)
    {
        for (size_t i = 0; i < len1; i++)
        {
            if (s1[i] == s2[i])
                continue;
            else if (s1[i] < s2[i])
                return -1;
            else if (s1[i] > s2[i])
                return 1;
        }
    }
    return 0;
}
void variant_display(const struct variant *e)
{
    if (e->type == TYPE_INT)
        printf("%d\n", e->value.int_v);
    else if (e->type == TYPE_CHAR)
        printf("%c\n", e->value.char_v);
    if (e->type == TYPE_STRING)
        printf("%s\n", e->value.str_v);
}
bool variant_equal(const struct variant *left, const struct variant *right)
{
    if ((right == NULL) && (left == NULL))
        return true;
    if ((right == NULL) && (left != NULL))
        return false;
    if ((right != NULL) && (left == NULL))
        return false;
    int c;
    if (left->type == right->type)
        switch (left->type)
        {
        case TYPE_INT:
            return (left->value.int_v == right->value.int_v);
        case TYPE_FLOAT:
            return (left->value.float_v == right->value.float_v);
        case TYPE_CHAR:
            return (left->value.char_v == right->value.char_v);
        case TYPE_STRING:
            c = my_strcmp(left->value.str_v, right->value.str_v);
            if (c == 0)
                return true;
            return false;
        }
    return false;
}
int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    const struct variant x = { .type = type, .value = value };
    for (size_t i = 0; i < len; i++)
    {
        if (variant_equal(&array[i], &x))
            return i;
    }
    return -1;
}
float variant_sum(const struct variant *array, size_t len)
{
    float sum = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (array[i].type == TYPE_INT)
        {
            sum = sum + array[i].value.int_v;
        }
        else if (array[i].type == TYPE_FLOAT)
        {
            sum = sum + array[i].value.float_v;
        }
    }
    return sum;
}
