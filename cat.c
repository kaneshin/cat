/*
 * file:        cat.c
 * maintainer:  Shintaro Kaneko <kaneshin0120@gmail.com>
 * Last Change: 28-Mar-2013.
 */

#include "cat.h"

#include <stdio.h>
#include <stdlib.h>

#include "concatenate.h"

int
main(int argc, char* argv[])
{
    int i;

    if (argc < 2)
    {
        fprintf(stderr, "%s: file name not given\n", argv[0]);
        exit(1);
    }
    for (i = 1; i < argc; ++i)
    {
        concatenate(argv[i]);
    }
    exit(0);
}

