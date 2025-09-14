/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:59:23 by azhuri            #+#    #+#             */
/*   Updated: 2025/09/13 23:03:36 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>

/* parse.c */
int		*parse_clues(char *s);

/* solver.c */
int		solve_and_print(int *clues);

/* utils.c */
void	print_grid(int *grid);
int		used_in_row(int *grid, int row, int val);
int		used_in_col(int *grid, int col, int val);
int		count_visible_row_from_left(int *grid, int row);
int		count_visible_row_from_right(int *grid, int row);
int		count_visible_col_from_top(int *grid, int col);
int		count_visible_col_from_bottom(int *grid, int col);

#endif
