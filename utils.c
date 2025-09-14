/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:00:12 by azhuri            #+#    #+#             */
/*   Updated: 2025/09/13 23:05:06 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/*
 * write_number: writes single digit and optionally space/newline.
 * We avoid stdio; build tiny buffer and write.
 */

/* write a grid (4x4) stored as int[16] row-major */
void	print_grid(int *grid)
{
	int		r;
	int		c;
	char	ch;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			ch = (char)('0' + grid[r * 4 + c]);
			write(1, &ch, 1);
			if (c < 3)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

/* helper: check if 'val' already in row */
int	used_in_row(int *grid, int row, int val)
{
	int	c;

	c = 0;
	while (c < 4)
	{
		if (grid[row * 4 + c] == val)
			return (1);
		c++;
	}
	return (0);
}

/* helper: check if 'val' already in col */
int	used_in_col(int *grid, int col, int val)
{
	int	r;

	r = 0;
	while (r < 4)
	{
		if (grid[r * 4 + col] == val)
			return (1);
		r++;
	}
	return (0);
}

/*

	* count_visible_row_from_left: for specific row index compute visible skyscrapers
 */
int	count_visible_row_from_left(int *grid, int row)
{
	int	max;
	int	count;
	int	c;
	int	v;

	max = 0;
	count = 0;
	c = 0;
	while (c < 4)
	{
		v = grid[row * 4 + c];
		if (v > max)
		{
			max = v;
			count++;
		}
		c++;
	}
	return (count);
}

/*
 * count_visible_row_from_right
 */
int	count_visible_row_from_right(int *grid, int row)
{
	int	max;
	int	count;
	int	c;
	int	v;

	max = 0;
	count = 0;
	c = 3;
	while (c >= 0)
	{
		v = grid[row * 4 + c];
		if (v > max)
		{
			max = v;
			count++;
		}
		c--;
	}
	return (count);
}

/*
 * count_visible_col_from_top
 */
int	count_visible_col_from_top(int *grid, int col)
{
	int	max;
	int	count;
	int	r;
	int	v;

	max = 0;
	count = 0;
	r = 0;
	while (r < 4)
	{
		v = grid[r * 4 + col];
		if (v > max)
		{
			max = v;
			count++;
		}
		r++;
	}
	return (count);
}

/*
 * count_visible_col_from_bottom
 */
int	count_visible_col_from_bottom(int *grid, int col)
{
	int	max;
	int	count;
	int	r;
	int	v;

	max = 0;
	count = 0;
	r = 3;
	while (r >= 0)
	{
		v = grid[r * 4 + col];
		if (v > max)
		{
			max = v;
			count++;
		}
		r--;
	}
	return (count);
}
