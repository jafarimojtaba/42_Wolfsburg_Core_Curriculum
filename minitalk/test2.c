/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:05:53 by mjafari           #+#    #+#             */
/*   Updated: 2021/12/31 00:18:03 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void server_m(int t)
{
	static int r;
	static int j;

	r = r << 1;
	r = r | t;
	if (++j == 8)
		write(1, &r, 1);
}

int main()
{
	int c = 'A';
	int t;
	int i = 8;

	while (i > 0)
	{
		t = c >> --i;
		server_m(t & 1);
	}
}