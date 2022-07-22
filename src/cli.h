#ifndef CLI_H
#define CLI_H

#define LINE_BUF_SIZE 128   //Maximum input string length
#define ARG_BUF_SIZE 64     //Maximum argument string length
#define MAX_NUM_ARGS 8      //Maximum number of arguments

extern char line[LINE_BUF_SIZE];
extern char args[MAX_NUM_ARGS][ARG_BUF_SIZE];

int parseArgs();
void clearArgs();

#endif