/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** compare the value of two strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int result;

    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            result = s1[i] - s2[i];
            return (result);
        }
    }
    return (0);
}
