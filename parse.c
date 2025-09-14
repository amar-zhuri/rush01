/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 22:59:49 by azhuri            #+#    #+#             */
/*   Updated: 2025/09/13 22:59:56 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/*
 * parse_clues:
 * Parse input string of 16 space-separated digits (1..4).
 * Return pointer to heap array of 16 ints or NULL on error.
 *
 * Only uses while loops; does manual parsing to avoid strtok/sscanf.
 */
int	*parse_clues(char *s)
{
	int		*arr;
	int		i;
	char	*p;
	int		val;

	arr = (int *)malloc(sizeof(int) * 16);
	if (!arr)
		return (NULL);
	i = 0;
	p = s;
	while (i < 16)
	{
		/* skip spaces */
		while (*p == ' ')
			p++;
		if (*p < '1' || *p > '4')
		{
			free(arr);
			return (NULL);
		}
		val = *p - '0';
		p++;
		/* after number either space or end, accept single-digit only */
		if (*p != ' ' && *p != '\0')
		{
			free(arr);
			return (NULL);
		}
		arr[i] = val;
		i++;
		/* skip spaces between numbers */
		while (*p == ' ')
			p++;
		if (*p == '\0' && i < 16)
		{
			free(arr);
			return (NULL);
		}
	}
	/* ensure there's no extra garbage after exact 16 values */
	while (*p == ' ')
		p++;
	if (*p != '\0')
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
