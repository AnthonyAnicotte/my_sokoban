/*
** EPITECH PROJECT, 2023
** PSU_my_sokoban_2018
** File description:
** Created by anthonyanicotte,
*/

#include "../include/function.h"
#include "../include/struct.h"

void space_bar(struct_t *soko)
{
    int i;
    soko->position_p = soko->position_p_bis;
    for (i = 0; soko->buffer_bis[i] != '\0'; i++)
        soko->buffer[i] = soko->buffer_bis[i];
    clear_print_and_refresh(soko);
}