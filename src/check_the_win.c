/*
** EPITECH PROJECT, 2023
** PSU_my_sokoban_2018
** File description:
** Created by anthonyanicotte,
*/

#include "../include/struct.h"
#include "../include/function.h"

int check_the_win(struct_t *soko)
{
    int i = 0;
    int j = 0;

    while (soko->buffer[i] != '\0') {
        if (i == soko->storage_pos[j]) {
            if (soko->buffer[soko->storage_pos[j]] == 'X')
                j++;
            else
                return (1);
        }
        i++;
    }
    return (0);
}