/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:21:42 by mjafari           #+#    #+#             */
/*   Updated: 2021/08/05 00:52:28 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line.c"

int main(void)
{
    char *str;
    int fd = open("test.txt", O_RDONLY);
    for (size_t i = 0; i < 10; i++)
    {
        /* code */
        str = get_next_line(fd);
        printf("%s", str);
    }
    return 0;
}