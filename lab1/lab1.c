//
// Created by s317869 on 13/03/23.
//
#include <stdio.h>
#include <unistd.h>

#define N 1024

int main(int argc, char *argv[]){

    char c;
    int fd, fd2, not_end;
    char line[N];
    int position = 0;

    FILE *file = fopen(argv[1], "r");

    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    while(fscanf, (file, "%d%ld%s%s%d", &student_d.id, &student_d.rn,
            student_d.n, student_d.s, &student_d.mark) != EOF) {
#if 0
        fprintf (stdout, "%d %ld %s %s %d\n", student_d.id, student_d.rn,
                 student_d.n, student_d.s, student_d.mark);
    }

    //printf("Usage: %s, %s, %s<filename>\n", argv[1], argv[2], argv[3]);

    close(fd);
    close(fd2);
    return 1;
}