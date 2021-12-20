/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 01:04:11 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/29 01:35:55 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct Point
{
	int x;
	int y;
}Point;

Point add(Point a, Point b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

int main()
{
	Point a = {1, 2};
	Point b = {5, 7};
	Point c = add(a, b);
	Point *d = &b;
	printf("%d %d %d %d\n", a.x, b.x, c.x, d->x);
	d->x = 7;
	printf("%d %d %d %d", a.x, b.x, c.x, d->x);
}
