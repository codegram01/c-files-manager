
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void fatal(const char *mess)
{
    if(errno == 0) {
        printf("%s\n", mess);
    } else {
        perror(mess);
    }

    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        fatal("Enter command. Ex: read, write, ...");
    }

    const char *command = argv[1];
    if(strcmp(command, "read") == 0)
    {
        if (argc == 2)
        {
            fatal("file path require");
        }
        const char *filePath = argv[2];

        FILE *file = fopen(filePath, "r");
        
        if(file == NULL)
        {
            fatal("Can't open file");
        }
        char c;
        while((c = getc(file)) != EOF)
        {
            putchar(c);
        }

    } else if(strcmp(command, "write") == 0)
    {
        if (argc == 2)
        {
            fatal("file path require");
        }
        const char *filePath = argv[2];

        FILE *file = fopen(filePath, "w");
        
        if(file == NULL)
        {
            fatal("Can't open file");
        }

        if (argc == 3)
        {
            fatal("content path require");
        }
        const char *content = argv[3];

        if(fputs(content, file) == EOF) {
            fatal("Can't write file");
        }

    } else if(strcmp(command, "remove") == 0)
    {
        if (argc == 2)
        {
            fatal("file path require");
        }
        const char *filePath = argv[2];

        if(remove(filePath) != 0)
        {
            fatal("Can't remove file");
        }

    } else if(strcmp(command, "move") == 0)
    {
        if (argc == 2)
        {
            fatal("old path require");
        }
        const char *oldPath = argv[2];

        if (argc == 3)
        {
            fatal("new path require");
        }
        const char *newPath = argv[3];

        if(rename(oldPath, newPath) != 0)
        {
            fatal("Can't move");
        }
    }

    return 0;
}
