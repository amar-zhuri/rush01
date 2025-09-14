#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* ==== helper functions ==== */
int count_visible_row_from_left(int *grid, int row)
{
    int max = 0, count = 0, c = 0, v;
    while (c < 4)
    {
        v = grid[row * 4 + c];
        if (v > max) { max = v; count++; }
        c++;
    }
    return count;
}

int count_visible_row_from_right(int *grid, int row)
{
    int max = 0, count = 0, c = 3, v;
    while (c >= 0)
    {
        v = grid[row * 4 + c];
        if (v > max) { max = v; count++; }
        c--;
    }
    return count;
}

int count_visible_col_from_top(int *grid, int col)
{
    int max = 0, count = 0, r = 0, v;
    while (r < 4)
    {
        v = grid[r * 4 + col];
        if (v > max) { max = v; count++; }
        r++;
    }
    return count;
}

int count_visible_col_from_bottom(int *grid, int col)
{
    int max = 0, count = 0, r = 3, v;
    while (r >= 0)
    {
        v = grid[r * 4 + col];
        if (v > max) { max = v; count++; }
        r--;
    }
    return count;
}

/* ==== main checker ==== */
int main(int argc, char **argv)
{
    int clues[16];
    int grid[16];
    int i, r, c, v;

    if (argc != 2)
    {
        write(1, "Usage: ./checker \"16 clues\"\n", 29);
        return 1;
    }
    /* parse clues */
    char *p = argv[1];
    i = 0;
    while (i < 16)
    {
        while (*p == ' ') p++;
        if (*p < '1' || *p > '4') { write(1, "Error\n", 6); return 0; }
        clues[i] = *p - '0';
        p++;
        while (*p == ' ') p++;
        i++;
    }

    /* read grid from stdin */
    i = 0;
    while (i < 16)
    {
        if (scanf("%d", &grid[i]) != 1) { write(1, "Error\n", 6); return 0; }
        if (grid[i] < 1 || grid[i] > 4) { write(1, "Error\n", 6); return 0; }
        i++;
    }

    /* check uniqueness in rows/cols */
    r = 0;
    while (r < 4)
    {
        int seen[5] = {0};
        c = 0;
        while (c < 4)
        {
            v = grid[r*4+c];
            if (seen[v]) { write(1,"Error\n",6); return 0; }
            seen[v] = 1;
            c++;
        }
        r++;
    }
    c = 0;
    while (c < 4)
    {
        int seen[5] = {0};
        r = 0;
        while (r < 4)
        {
            v = grid[r*4+c];
            if (seen[v]) { write(1,"Error\n",6); return 0; }
            seen[v] = 1;
            r++;
        }
        c++;
    }

    /* check all clues */
    i = 0;
    while (i < 4)
    {
        if (count_visible_col_from_top(grid,i)!=clues[i]) { write(1,"Error\n",6); return 0; }
        if (count_visible_col_from_bottom(grid,i)!=clues[4+i]) { write(1,"Error\n",6); return 0; }
        i++;
    }
    i = 0;
    while (i < 4)
    {
        if (count_visible_row_from_left(grid,i)!=clues[8+i]) { write(1,"Error\n",6); return 0; }
        if (count_visible_row_from_right(grid,i)!=clues[12+i]) { write(1,"Error\n",6); return 0; }
        i++;
    }

    write(1,"OK\n",3);
    return 0;
}
