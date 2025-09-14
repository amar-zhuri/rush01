#include "rush01.h"

int	check_clues_partial(int *grid, int *clues)
{
	int	r;
	int	c;
	int	all_filled;
	int	val;

	r = 0;
	while (r < 4)
	{
		all_filled = 1;
		c = 0;
		while (c < 4)
		{
			if (grid[r * 4 + c] == 0)
			{
				all_filled = 0;
				break ;
			}
			c++;
		}
		if (all_filled)
		{
			val = count_visible_row_from_left(grid, r);
			if (val != clues[8 + r])
				return (0);
			val = count_visible_row_from_right(grid, r);
			if (val != clues[12 + r])
				return (0);
		}
		r++;
	}
	c = 0;
	while (c < 4)
	{
		all_filled = 1;
		r = 0;
		while (r < 4)
		{
			if (grid[r * 4 + c] == 0)
			{
				all_filled = 0;
				break ;
			}
			r++;
		}
		if (all_filled)
		{
			val = count_visible_col_from_top(grid, c);
			if (val != clues[c])
				return (0);
			val = count_visible_col_from_bottom(grid, c);
			if (val != clues[4 + c])
				return (0);
		}
		c++;
	}
	return (1);
}

int	check_final_clues(int *grid, int *clues)
{
	int	i;
	int	v;

	i = 0;
	while (i < 4)
	{
		v = count_visible_col_from_top(grid, i);
		if (v != clues[i])
			return (0);
		v = count_visible_col_from_bottom(grid, i);
		if (v != clues[4 + i])
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		v = count_visible_row_from_left(grid, i);
		if (v != clues[8 + i])
			return (0);
		v = count_visible_row_from_right(grid, i);
		if (v != clues[12 + i])
			return (0);
		i++;
	}
	return (1);
}
