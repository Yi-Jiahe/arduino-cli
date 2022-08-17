#ifndef CLI_H
#define CLI_H

constexpr int kLineBufSize = 128   //Maximum input string length
constexpr int kArgBufSize = 64     //Maximum argument string length
constexpr int kMaxNumArgs = 8      //Maximum number of arguments

extern char line[kLineBufSize];
extern char args[kMaxNumArgs][kArgBufSize];

int parseArgs();
void clearArgs();

#endif