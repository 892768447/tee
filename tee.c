#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>

#define MAXLENGTH 1024

int main(int argc, char *argv[])
{
    int opt, n, fd;
    int A_FLAG = 0;
    int T_FLAG = O_TRUNC;
    char buffer[MAXLENGTH+1];
    while((opt = getopt(argc, argv, "a")) != -1) {
        if(opt == '?') {
            printf("Error, incorrect arguments");
            return 0;
        }
        else {
            A_FLAG = O_APPEND;
            T_FLAG = 0;
        }
    }

    fd = open(argv[optind], O_WRONLY | O_CREAT | A_FLAG | T_FLAG, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    while((n = read(STDIN_FILENO, buffer, MAXLENGTH) != -1)) {
        buffer[n] = '\0';
        write(fd, buffer, MAXLENGTH);
    }

    return 0;
}
