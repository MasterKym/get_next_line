#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    char    *gnl_ret;
    int     fd;
    int     count;
    
    fd = open("test", O_RDONLY);
    count = 1;
    while(1)
    {
        gnl_ret = get_next_line(fd);
        if (gnl_ret == 0)
            break ;
        //printf("%s", "\n");
        //printf("%s", "call number:");
        //printf("%d", count);
        //printf("%s", "==>|");
        printf("%s", gnl_ret);
        count++;
    }
}
