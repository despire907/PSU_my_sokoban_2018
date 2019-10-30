/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** sokoban
*/

#include "../include/sokoban.h"

int my_strlen(char const *str)
{
    int bobo;

    bobo = 0;
    while (str[bobo] != '\0')
        bobo = bobo + 1;
    return (bobo);
}

int my_popup(char **buf, t_pos *pos, char const *fd)
{
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    int ch;
    while (1) {
        clear();
        my_display(buf);
        ch = getch();
        if (ch == KEY_UP || ch == KEY_DOWN || ch == KEY_LEFT || ch == KEY_RIGHT)
            mouv_p(buf, pos, ch);
        refresh();
        if (ch == ' ')
            fs_print_first_line(fd);
        if (ch == 'q')
            break;
    }
    endwin();
    return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    int papa = 0;

    while (s1[papa] == s2[papa] && s1[papa] && s2[papa])
        ++papa;
    return (s1[papa] - s2[papa]);
}

void fs_print_first_line(char const *filepath)
{
    char **buf;
    int taille_map_y;
    struct stat sb;
    stat(filepath, &sb);
    int size = sb.st_size;
    t_pos *pos;
    pos = malloc(sizeof(t_pos));
    char buffer[size];
    int fd = open(filepath, O_RDONLY);
    int taille_map_x;

    size = read(fd, buffer, size);
    taille_map_x = My_x(filepath);
    taille_map_y = My_y(filepath);
    fd = open(filepath, O_RDONLY);
    buf = my_map(buffer, taille_map_y, taille_map_x, pos);
    my_popup(buf, pos, filepath);
}

int main(int ac, char **av)
{
    if (ac == 2 && !my_strcmp(av[1], "-h")) {
        my_putstr("USAGE\n");
        my_putstr("\t./my_sokoban map\n");
        my_putstr("\nDESCRIPTION\n");
        my_putstr("\tmap  file representing the ");
        my_putstr("warehouse map, containing ‘#’ for walls, \n");
        my_putstr("\t     ‘P’ for the player, ‘X’ for boxes ");
        my_putstr("and ‘O’ for storage locations.\n");
        return (0);
    } else if (ac == 2 && fs_open_file(av[1]) != -1)
        fs_print_first_line(av[1]);
    if (ac != 2)
        my_putstr("If you need help : ./my_sokoban -h\n");
    else if (ac == 2 && fs_open_file(av[1]) == -1)
        my_putstr("No such file or directory.\n");
    return (0);
}
