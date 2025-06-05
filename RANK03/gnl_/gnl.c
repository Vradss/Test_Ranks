
#include "gnl.h"

int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return i;
}

char    *ft_strdup(char *src)
{
    char *res = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
    int i = 0;
    while(src[i])
    {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    return res;
}



char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE]; //guardamos archivo
    static int buffer_pos; // posicion donde estamos
    static int buffer_read; //cantidad de bytes leidos en la ultima llamada
    char line[70000]; //aqui iremos armando las lineas
    
    int i = 0;

    //control de error
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    
    while (1)
    {
        if (buffer_pos >= buffer_read) //si la posicion esta en 6 y lo que he leido llega hasta posicion 4, tengo que volver a leer
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if (buffer_read <= 0)
                break;
        }
        line[i++] = buffer[buffer_pos++];
        if (line [i - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if ( i == 0)
        return NULL;
    return(ft_strdup(line));
}


int main(void)
{
    int fd = open("test.txt", O_RDONLY); // Abre el archivo en solo lectura
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // ya incluye \n si lo hay
        free(line);         // liberar memoria si usas malloc/strdup
    }

    close(fd);
    return (0);
}
