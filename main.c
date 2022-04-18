#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    char    *gnl_ret;
    int     fd;
    
    fd = open("test", O_RDONLY);
    while(1)
    {
        gnl_ret = get_next_line(fd);
        if (gnl_ret == 0)
            break ;

        printf("%s", gnl_ret);
        printf("--\n");
    }
}
