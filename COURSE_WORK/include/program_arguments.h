#ifndef PROGRAM_ARGUMENTS_H
#define PROGRAM_ARGUMENTS_H

#include <getopt.h>
#include <stdio.h>

typedef struct ProgramArguments
{
    double eps1;
    double eps2;
    int test_mode;
    double test_a;
    double test_b;
} ProgramArguments;

void PrintHelp();

int ParseArguments(const int argc, char* argv[], ProgramArguments* arguments);

#endif
