/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** sokoban
*/

#include "../include/sokoban.h"

int My_x(char const *filepath)
{
    int size = 1;
    char buffer[size];
    int fd = open(filepath, O_RDONLY);
    int taille_map_x = 0;

    while (buffer[0] != '\n') {
        read(fd, buffer, size);
        taille_map_x++;
    }
    close (fd);
    return (taille_map_x - 1);
}

int My_y(char const *filepath)
{
    int size = 1;
    char buffer[size];
    int fd = open(filepath, O_RDONLY);
    int taille_map_y = 0;

    while (size != 0) {
        size = read(fd, buffer, size);
        if (buffer[0] == '\n') {
            taille_map_y++;
        }
    }
    close (fd);
    return (taille_map_y + 1);
}

t_pos *coord_of_p(int i, int j, t_pos *pos)
{
    pos->x = i;
    pos->y = j;
    return (pos);
}

char **my_map(char *buffer, int taille_map_y, int taille_map_x, t_pos *pos)
{
    int count = 0;
    char **tab;
    int i = 0;
    int j = 0;
    tab = malloc(sizeof(char*) * taille_map_y);
    while (j != taille_map_y) {
        i = 0;
        tab[j] = malloc(sizeof(char) * taille_map_x);
        while (i != taille_map_x) {
            tab[j][i] = buffer[count];
            if (tab[j][i] == 'P')
                pos = coord_of_p(i, j, pos);
            i++;
            count++;
        }
        j++;
        count++;
    }
    tab[j] = NULL;
    return (tab);
}

void my_display(char **buf)
{
    int i = 0;
    int x = 0;
    int y = 0;

    while (buf[i] != NULL) {
        mvprintw(y, x, "%s\n", buf[i]);
        y++;
        i++;
    }
}