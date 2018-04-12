/*
    simple_note.c
    file descriptor functions: open, close, read, write
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

void usage(char *prog_name, char *filename)
{
    printf("usage: %s <data to add to $s>\n", prog_name, filename);
    exit(0);
}

/* function declarations */
void fatal(char *);
void *ec_malloc(unsigned int);

int main(int argc, char *argv[])
{
    int fd;
    char *buffer;
    char *datafile;
    
    /* allocate memory */
    buffer = (char *)ec_malloc(100);
    datafile = (char *)ec_malloc(20);
    strcpy(datafile, "/tmp/notes");

    if (argc < 2)
        usage(argv[0], datafile);

    /* copy into buffer */
    strcpy(buffer, argv[1]);

    printf("[DEBUG] buffer\t\t@\t%p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile\t@\t%p: \'%s\'\n", datafile, datafile);

    /* add trailing newline */
    strncat(buffer, "\n", 1);

    /* open file                                              */
    /* mode flags must contain at least one of the following: */
    /* O_RDONLY - read-only access                            */
    /* O_WRONLY - write-only access                           */
    /* O_RDWR   - read and write access                       */
    /* other available flags to combine with above:           */
    /* O_APPEND - write to end of file                        */
    /* O_TRUNC  - if file exists, truncate to 0 len           */
    /* O_CREAT  - create file if it doesn't exist             */

    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
    if (fd == -1)
        fatal("in main() while opening file");
    printf("[DEBUG] file descriptor is %d\n", fd);
    /* write data */
    if (write(fd, buffer, strlen(buffer)) == -1)
        fatal("in main() while writing buffer to file");
    /* close file */
    if (close(fd) == -1)
        fatal("in main() while closing file");
    
    printf("[+] note has been saved.\n");
    /* free memory */
    free(buffer);
    free(datafile);
}

void fatal(char *message)
{
    char error_message[100];
    strcpy(error_message, "[-] Fatal Error ");
    strncpy(error_message, message, 83);
    perror(error_message);
    exit(-1);
}

/* an error-checked malloc() wrapper function */
void *ec_malloc(unsigned int size)
{
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL)
        fatal("in ec_malloc() on memory allocation");
    return ptr;
}



















