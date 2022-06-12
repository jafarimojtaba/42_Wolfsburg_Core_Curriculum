/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ber_to_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:06:02 by mjafari           #+#    #+#             */
/*   Updated: 2022/06/06 19:51:47 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int col;
static int row;

char **read_row_col(int fd)
{
    char **arr;
    char *tmp;
    int i;
        
    tmp = get_next_line(fd);
    col = ft_strlen(tmp) - 1;
    while (tmp)
    {
        row++;
        free(tmp);
        tmp = get_next_line(fd);
    }
    arr = (char **)malloc((col + 1) * sizeof(char *));
    i = 0;
    while (i < col)
    {
        arr[i] = (char *)malloc((row + 1) * sizeof(char));
        i++;
    }
    close(fd);
    return arr;
}

void map_to_arr(int fd, char **arr)
{
    char *str;
    char *tmp;
    int i;
    int j;
    static int pc;
        static int ec;
    static int cc;

    str = get_next_line(fd);
    i = 0;
    
    while (i < row)
    {
        tmp = str;
        j = 0;
        while (j < col)
        {
            if (!(ft_strchr("10PEC\n", *str)))
            {
                printf("ERROR\nber file includes some invalid character!\n");
                exit(0);
            }
            if (*str == 'P')
                pc++;
            if (*str == 'C')
                cc++;
            if (*str == 'E')
                ec++;
            if (*str != '\n')
                arr[i][j] = *str;
            str++;
            j++;
        }
        
        free(tmp);
        str = get_next_line(fd);
        i++;
    }
    
    if (pc > 1 || ec == 0 || cc == 0)
    {
        printf("ERROR\nber file includes more than one player or no Exit or no Collectible!\n");
        exit(0);
    }
}

char **convert_ber_to_arr(char *file)
{
    char **arr;
    int fd;
    fd = open(file, O_RDONLY);
    arr = read_row_col(fd);
    fd = open(file, O_RDONLY);
    map_to_arr(fd, arr);
    // printf("row=%d col =%d\n", row, col);
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         printf("%c ", arr[i][j]);
    //     }
    //     printf("\n");
    // }
    return (arr);
}