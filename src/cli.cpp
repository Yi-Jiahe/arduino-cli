#include <Arduino.h>
#include "cli.h"

CLI::CLI() {

}

void CLI::do_loop() {
    if (_parseArgs() == 0)
    {
        _clearArgs();
    }
}

int CLI::_parseArgs()
{
    String line_string;

    if (Serial.available())
    {
        line_string = Serial.readStringUntil('\n');
        if (line_string.length() < CLI_LINE_BUF_SIZE)
        {
            line_string.toCharArray(_line, CLI_LINE_BUF_SIZE);

            char *argument;
            int counter = 0;

            argument = strtok(_line, " ");

            while ((argument != NULL))
            {
                if (counter < CLI_MAX_NUM_ARGS)
                {
                    if (strlen(argument) < CLI_ARG_BUF_SIZE)
                    {
                        strcpy(_args[counter], argument);
                        argument = strtok(NULL, " ");
                        counter++;
                    }
                    else
                    {
                        Serial.println("Input string too long.");
                        return 1;
                    }
                }
                else
                {
                    Serial.println("Too many arguments.");
                    return 1;
                }
            }
            return 0;
        }
        else
        {
            Serial.println("Input string too long.");
            return 1;
        }
    }

    return 1;
}

void CLI::_clearArgs()
{
    memset(_line, 0, CLI_LINE_BUF_SIZE);
    memset(_args, 0, sizeof(_args[0][0]) * CLI_MAX_NUM_ARGS * CLI_ARG_BUF_SIZE);
}