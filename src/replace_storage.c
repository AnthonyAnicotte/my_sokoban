/*
** EPITECH PROJECT, 2023
** PSU_my_sokoban_2018
** File description:
** Created by anthonyanicotte,
*/

#include "../include/struct.h"
#include "../include/function.h"

void replace_storage(struct_t *soko)
{
    int i = 0;
    int j = 0;

    while (soko->buffer[i] != '\0') {
        if (i == soko->storage_pos[j]) {
            if (soko->buffer[i] == ' ')
                soko->buffer[soko->storage_pos[j]] = 'O';
            j++;
        }
        i++;
    }
}