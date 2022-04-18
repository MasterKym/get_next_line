
#include "get_next_line.h"

int     ft_strlen(char *s){
    int i;

    i = 0;
    if (!s){
        return 0;
    }
    while(s[i]){
        i++;
    }
    return i;
}

char    *concat(char *s1, char *s2){
    int i;
    int s1l;
    int s2l;
    char    *cat;

    s1l = ft_strlen(s1);
    s2l = ft_strlen(s2);

    cat = malloc (sizeof(char) * (s1l + s2l + 1));
    if (!cat){
        return (0);
    }
    i = 0;
    while(i < s1l){
        cat[i] = s1[i];
        i++;
    }
    while(i < s1l + s2l){
        cat[i] = s2[i - s1l];
        i++;
    }
    cat[i] = 0;
    return cat;
}

char    *substr(char *s, int start, int end){
    int i;
    int len;

    if (start < 0 || end < start || end > ft_strlen(s)){
        return (0);
    }
    char *ret = malloc (sizeof(char) * ( end - start + 1 + 1));
    if (!ret){
        return (0);
    }
    i = 0;
    len = end - start + 1;
    while (i < len){
        ret[i] = s[start + i];
        i++;
    }
    ret[i] = 0;
    return (ret);
}
char    *get_next_line(int fd)
{
    int     rs;// for read size, how much has been read by the `read` function
    static char    *line;
    char    buf[BUFFER_SIZE + 1];
    int i;

    buf[BUFFER_SIZE] = 0;
    while(1){
        rs = read(fd, buf, BUFFER_SIZE);
        if (rs == 0 || rs == -1){
            return (0);
        }
        // check if newline is read
        i = -1;
        while(++i < BUFFER_SIZE){
            if(buf[i] == '\n'){
                break;
            }
        }
        if (i != BUFFER_SIZE){// means NL has been found
            line = concat(line, substr(buf, 0, i));
            return (line);
            // You need to reset line to empty string here !
        } else {
            line = concat(line, buf);
        }
    }
}


/*
// Algo
- read BUFFER_SIZE bytes into buf
- loop over buf
    - if it contains newline copy all the characters up to and including new line to var `line`
        -- copy the rest of the buf into rest
        -- return concat(rest, line)
    - if doesn't contain, rest = concat(rest, buf)

*/