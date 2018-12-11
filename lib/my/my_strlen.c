/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** task3
*/

int my_strlen(char const *str)
{
    int nbr;

    nbr = 0;
    while (str[nbr] != '\0') {
    nbr++;
    }
    return (nbr);
}
