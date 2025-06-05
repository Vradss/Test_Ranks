

//.h

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif

#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);

#endif

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
char *ft_strdup(char *src)
 {
    char *dest = (char *)malloc(sizeof(char ) * (ft_strlen(src) + 1));
    int i = 0;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
 }


char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int buffer_pos;
    static int buffer_read;
    char line[70000];

    int i = 0;

    //comprobacion de errores
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while(1)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd,buffer,BUFFER_SIZE);
            buffer_pos = 0;
            if (buffer_read <= 0)
                break;
        }
        line[i++] = buffer[buffer_pos++];
        //si termino la linea
        if ( line[i -1 ] == '\n')
            break;
    }
    //cerramos line 
    line[i] = '\0';
    if ( i == 0)
        return (NULL);
    return (ft_strdup(line));
}


// #include <fcntl.h> 
// #include <stdio.h> 
// int main()
// {
//     int fd = open("test.txt", O_RDONLY);
//     if (fd < 0)
//         return 1;

//     char *line;

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close (fd);
//     return 0;
// }