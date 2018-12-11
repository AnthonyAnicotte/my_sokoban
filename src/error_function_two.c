/*
** EPITECH PROJECT, 2023
** PSU_my_sokoban_2018
** File description:
** Created by anthonyanicotte,
*/

#include "../include/struct.h"
#include "../include/function.h"

int storage_boxes(struct_t *soko)
{
    int pos = 0;
    int i = 0;
    int boxes = 0;
    int storages = 0;

    while (soko->buffer[i] != '\0')
    {
        if (soko->buffer[i] == 'X')
            boxes++;
        if (soko->buffer[i] == 'O') {
            storages++;
            soko->storage_pos[pos] = i;
            pos++;
        }
        i++;
    }
    if (boxes != storages || boxes == 0)
        return (1);
    else
        return (0);
}