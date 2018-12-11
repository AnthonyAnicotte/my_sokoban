/*
** EPITECH PROJECT, 2023
** PSU_my_sokoban_2018
** File description:
** Created by anthonyanicotte,
*/

#include "../include/function.h"
#include "../include/struct.h"
#include <stdio.h>

int error_handling(struct_t *soko)
{
    int return_value = 0;

    return_value += error_handling_sharp_square(soko);
    return_value += same_lines(soko);
    return_value += check_char(soko);
    return_value += many_players(soko);
    return (return_value);
}