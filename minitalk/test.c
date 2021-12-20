/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:24:45 by mjafari           #+#    #+#             */
/*   Updated: 2021/12/20 23:11:15 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void server(int bit)
{
  static int arr[8];
  static int i;
  static int c;
  if (i == 0)
    i = 8;
  arr[--i] = bit;
  if (i == 0)
  {
    c = 0;
    while (i < 8)
    {
      c = c << 1;
      c = c | arr[i];
      i++;
    }
    write(1, &c, 1);
  }
}

int main(void)
{
    char *str = "üöäسلامchetori";
    char c = str[0];
    int i = 7;
    while (*str)
    {
        c = *str;
        i = 7;
        while (i > -1)
        {
            if (c & 1)
                server(1);
            else
                server(0);
            c = c >> 1;
            i--;
        }
        str++;
    }
    return (0);
}
