#include <Arduino.h>
#include "cli.h"

MY_CLI::MY_CLI(char* line[], char* args[][]) {
    _lineBufSize = sizeof(line)/sizeof(char);
    _argBufSize = sizeof(args[0])/sizeof(char);
    _maxNumArgs = (sizeof(args)/sizeof(char))/_argBufSize;
    _line = line;
    _args = args;
}

int MY_CLI::parseArgs()
{
    String line_string;

    if (Serial.available())
    {
        line_string = Serial.readStringUntil('\n');
        Serial.println(line_string);
        Serial.print(line_string.length());
        Serial.println(_lineBufSize);
        if (line_string.length() < _lineBufSize)
        {
            line_string.toCharArray(_line, _lineBufSize);

            char *argument;
            int counter = 0;

            argument = strtok(_line, " ");

            while ((argument != NULL))
            {
                if (counter < _maxNumArgs)
                {
                    if (strlen(argument) < _argBufSize)
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

void MY_CLI::clearArgs()
{
    memset(_line, 0, _lineBufSize);
    memset(_args, 0, sizeof(char) * _maxNumArgs * _argBufSize);
}