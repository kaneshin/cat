/*
 * file:        concatenate.c
 * maintainer:  Shintaro Kaneko <kaneshin0120@gmail.com>
 * Last Change: 28-Mar-2013.
 */

#include "concatenate.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

static void die(const char *s);

void
concatenate(const char *path)
{
    int n, file;
    unsigned char buf[BUFFER_SIZE];

    if ((file = open(path, O_RDONLY)) < 0)
        die(path);
    for (n = read(file, buf, sizeof(buf)); n != 0 ;n = read(file, buf, sizeof(buf)))
    {
        if (n < 0)
            die(path);
        if (write(STDOUT_FILENO, buf, n) < 0)
            die(path);
    }
    if (close(file) < 0)
        die(path);
}

static void
die(const char *s)
{
    perror(s);
    exit(1);
}

