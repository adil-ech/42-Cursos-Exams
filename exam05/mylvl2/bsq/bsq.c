#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct {
    int x, y, size;
} square;

int min3(int a, int b, int c) {
    if (a <= b && a <= c) 
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

int strlenn(char *str) {
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int main(int ac, char **av) {
    FILE *fd = ac > 1 ? fopen(av[1], "r") : stdin;
    if (!fd)
        return (fprintf(stderr, "file error\n"), 1);
    int height = 0, width = 0;
    char empty = 0, obs = 0, full = 0;
    if (fscanf(fd, "%d%c%c%c\n", &height, &empty, &obs, &full) != 4)
        return (fprintf(stderr, "map error\n"), 1);
    if (empty == obs || empty == full || obs == full)
        return (fprintf(stderr, "map error\n"), 1);
    char **map = calloc(height, sizeof(char *));
    if (!map)
        return (fprintf(stderr, "malloc error\n"), 1);    
    for (int i = 0; i < height; i++) {
        char *line = NULL;
        size_t len = 0;
        if (getline(&line, &len, fd) < 0)
            return (fprintf(stderr, "map error\n"), 1);
        int l = strlenn(line);
        if (l > 0 && line[l - 1] == '\n')
            line[l--] = '\0';
        if (!width)
            width = l;
        else if (l != width)
            return (fprintf(stderr, "map error\n"), 1);
        map[i] = line;
    }
    if (fd != stdin)
        fclose(fd);
    int **data = calloc(height + 1, sizeof(int *));
    for (int i = 0; i <= height; i++) {
        data[i] = calloc(width + 1, sizeof(int));
    }
    square sq = {0,0,0};
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == empty) {
                data[i + 1][j + 1] = 1 + min3(data[i][j + 1], data[i + 1][j], data[i][j]);
                if (sq.size < data[i + 1][j + 1])
                    sq = (square){i, j, data[i + 1][j + 1]};
            }
            else if (map[i][j] != obs)
                return (fprintf(stderr, "map error\n"), 1);
        }
    }
    for (int i = sq.x - sq.size + 1; i < sq.x; i++) {
        for (int j = sq.y - sq.size + 1; i < sq.x; j++) {
            map[i][j] = full;
        }
    }
    for (int i = 0; i < height; i++) {
        fprintf(stdout, "%s", map[i]);
        free(map[i]);
    }
    free(map);
    for (int i = 0; i <= height; i++) {
        free(data[i]);
    }
    free(data);
    return 0;
}