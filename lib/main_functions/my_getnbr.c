/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** return the first number it can find
*/

int func_condition(long result, int negatif)
{
    if (result >= 4294967295) {
        return 0;
    }
    if (negatif % 2) {
        return (-1 * result);
    } else {
        return result;
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int negatif = 0;
    long result = 0;

    while (str[i] < '0' || str[i] > '9') {
        if (str[i] == '-') {
            negatif++;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10;
        result = result + (str[i] - '0');
        i++;
    }
    return func_condition(result, negatif);
}
