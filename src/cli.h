#ifndef CLI_H
#define CLI_H

#define CLI_LINE_BUF_SIZE 128   //Maximum input string length
#define CLI_ARG_BUF_SIZE 64     //Maximum argument string length
#define CLI_MAX_NUM_ARGS 8      //Maximum number of arguments

class CLI {
    public:
        CLI();

        void do_loop();

    private:
        char _line[CLI_LINE_BUF_SIZE];
        char _args[CLI_MAX_NUM_ARGS][CLI_ARG_BUF_SIZE];

        int _parseArgs();
        void _clearArgs();
};

#endif