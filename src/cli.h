#ifndef CLI_H
#define CLI_H

class MY_CLI {
    public:
        MY_CLI(char* line[], * args[][]);

        int parseArgs();
        void clearArgs();
    private:
        int _lineBufSize;
        int _maxNumArgs;
        int _argBufSize;

        char* line;
        char* args;
};

#endif