
#include "get_next_line.h"

char    *ft_strndup(char *s, int n)
{
    int     i;
    char    *res;

    i = 0;
    res = malloc(sizeof(char) * n + 1);
    while (i < n)
    {
        res[i] = s[i];
        i++;
    }
    res[i] = 0;
    return res;
}

char    *get_next_line(int fd)
{
    int     rs;// for read size
    char    *line;
    char    buf[BUFFER_SIZE + 1];

    buf[BUFFER_SIZE] = 0;
    rs = read(fd, buf, BUFFER_SIZE);
    if(rs == 0 || rs == -1)
        return 0;
    line = ft_strndup(buf, rs);
    //return (line);
    //return ("tt");
}

