/*
** EPITECH PROJECT, 2023
** PSU_my_sokoban_2018
** File description:
** Created by anthonyanicotte,
*/

#include "../include/struct.h"
#include "../include/function.h"
#include <stdio.h>

int many_players(struct_t *soko)
{
    int i = 0;
    int player = 0;

    while (soko->buffer[i] != '\0') {
        if (soko->buffer[i] == 'P') {
            player++;
            i++;
        } else
            i++;
    }
    if (player != 1)
        return (1);
    return (0);
}

int check_char(struct_t *soko)
{
    int i = 0;

    while (soko->buffer[i] != '\0') {
        if (soko->buffer[i] != ' ' && soko->buffer[i] != '#' &&
            soko->buffer[i] != '\n' && soko->buffer[i] != 'X' &&
            soko->buffer[i] != 'O' && soko->buffer[i] != 'P')
            return (1);
        else
            i++;
    }
    return (0);
}

int same_lines(struct_t *soko)
{
    int lines_columns = soko->lines * soko->columns;

    if (soko->lines != (lines_columns / soko->columns))
        return (1);
    else
        return (0);
}

int error_handling_two(struct_t *soko)
{
    int cpt = 1;
    int i = 0;
    int j = soko->columns - 2;

    while (cpt < soko->lines) {
        if (soko->buffer[i] == '#' && soko->buffer[j] == '#') {
            i += (soko->columns);
            j += (soko->columns);
            cpt++;
        } else
            return (1);
    }
    return (0);
}

int error_handling_sharp_square(struct_t *soko)
{
    int cpt = 0;
    int return_value;
    int i = 0;
    int k = soko->map_size - soko->columns;

    while (cpt < soko->columns - 1) {
        if (soko->buffer[i] == '#' && soko->buffer[k] == '#') {
            i++;
            k++;
            cpt++;
        } else
            return (1);
    }
    return_value = error_handling_two(soko);
    if (return_value == 1)
        return (1);
    else
        return (0);
}