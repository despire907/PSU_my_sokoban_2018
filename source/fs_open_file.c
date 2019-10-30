/*
** EPITECH PROJECT, 2018
** fs_open_file.c
** File description:
** open_file
*/

#include "../include/sokoban.h"

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    return (fd);
}