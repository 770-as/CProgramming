#include <unistd.h>
#include <fcntl.h>

int     main(void)                                                    
{
        char    *file = "example";
        int     fd = open(file, O_TRUNC | O_WRONLY);
        if (fd == -1)
                return (-1);
        char    *str = "Blue Gates\n";

        write(fd, str, 11);
        write(fd, str, 11);

        close(fd);
}