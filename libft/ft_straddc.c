#include "libft.h"

char *ft_stradd_first_c(char c)
{
    char *temp;

    temp = (char *)malloc(sizeof(char) * 2);
    if (!temp)
    {
        free(temp);
        return (0);
    }
    temp[0] = c;
    temp[1] = 0;
    return (temp);
}

char *ft_stradd_c(char *str, char c)
{
    char    *temp;
    int     i;

    i = 0;
    if (!c)
        return (0);
    if (!str)
        return (ft_stradd_first_c(c));
    temp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
    if (!temp)
    {
        free(str);
        return (0);
    }
    while (str[i])
    {
        temp[i] = str[i];
        i++;
    }
    free(str);
    temp[i++] = c;
    temp[i] = 0;
    return (temp);
}