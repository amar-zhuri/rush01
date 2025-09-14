/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:01:18 by azhuri            #+#    #+#             */
/*   Updated: 2025/09/13 23:01:25 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/*
 * Recursive backtracking search for 4x4.
 * - grid: malloc'd int[16], 0 means empty
 * - clues: int[16]
 *
 * We use position index (0..15) and recursion.
 * Return 1 if solution printed (first solution), 0 otherwise.
 *
 * Only while loops are used.
 */

/* forward declarations from other files */
int			check_clues_partial(int *grid, int *clues);
int			check_final_clues(int *grid, int *clues);
void		print_grid(int *grid);

static int	place_try(int *grid, int pos, int *clues)
{
	int	row;
	int	col;
	int	v;
	int	res;

	if (pos == 16)
	{
		/* grid full: verify final clues and print if ok */
		if (check_final_clues(grid, clues))
		{
			print_grid(grid);
			return (1);
		}
		return (0);
	}
	row = pos / 4;
	col = pos % 4;
	if (grid[pos] != 0)
		return (place_try(grid, pos + 1, clues));
	v = 1;
	while (v <= 4)
	{
		/* check uniqueness in row/col */
		if (!used_in_row(grid, row, v) && !used_in_col(grid, col, v))
		{
			grid[pos] = v;
			/* early pruning */
			if (check_clues_partial(grid, clues))
			{
				res = place_try(grid, pos + 1, clues);
				if (res)
					return (1); /* found solution, propagate up */
			}
			grid[pos] = 0;
		}
		v++;
	}
	return (0);
}

int	solve_and_print(int *clues)
{
	int	*grid;
	int	i;
	int	ok;

	grid = (int *)malloc(sizeof(int) * 16);
	if (!grid)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (i < 16)
	{
		grid[i] = 0;
		i++;
	}
	ok = place_try(grid, 0, clues);
	if (!ok)
	{
		write(1, "Error\n", 6);
	}
	free(grid);
	return (ok);
}
