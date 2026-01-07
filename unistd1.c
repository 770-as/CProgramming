#include <unistd.h>
/*This header provides access to the Portable Operating System Interface (POSIX), which includes functions for low-level I/O operations like open(), close(), and write().*/
#include <fcntl.h>
/*This header defines file control options, such as O_CREAT, O_RDWR, and O_APPEND, used with the open() function.*/
#include <stdio.h>
/*This header is the standard input/output library. It contains functions like printf() for formatted output to the console.*/
#include <string.h>

int     main(int argc, char **argv)
{
        if (argc < 3)/*The program expects at least three arguments: the program name (argv[0]), the filename (argv[1]), and at least one string to write (argv[2]).*/
                return (printf("Nothing to be done, exiting...\n"));

        char    *file = argv[1];/*This line creates a character pointer file and assigns it the string from the second command-line argument, which is expected to be the filename.*/
        int     i = 2;
        int     fd = open(file, O_CREAT | O_RDWR | O_APPEND);
/*This line attempts to open or create the file specified by file*open() is a system call that opens a file. The 
second argument, O_CREAT | O_RDWR | O_APPEND, combines three flags using the bitwise OR operator (|).
O_CREAT: Creates the file if it doesn't exist.
O_RDWR: Opens the file for both reading and writing.
O_APPEND: Appends new data to the end of the file instead of overwriting existing content.*/
        if (fd == -1)/*This checks if the file failed to open. open() returns -1 on failure.*/
                return (printf("failed to open the file!\n"));

        while (i < argc)
        {
                write(fd, argv[i], strlen(argv[i]));
                write(fd, “\n”, 1);
                i++;
        }
/*This starts a loop that continues as long as the index i is less than the total number of command-line arguments.
write(fd, argv[i], strlen(argv[i]));: This line writes data to the file. write() is a system call that writes to a
file descriptor. fd is the file descriptor. argv[i] is the string to be written. strlen(argv[i]) gets the length 
of the string, so write knows how many bytes to write. write(fd, “\n”, 1);: This line writes a single newline 
character (\n) to the file. This ensures each argument is on a new line.*/
        close(fd);                                                              
        return (printf("Updated file: %s\n", file));                            
}

