#include <Arduino.h>
#include "cli.h"

char line[kLineBufSize];
char args[kMaxNumArgs][kArgBufSize];

int parseArgs()
{
    String line_string;

    if (Serial.available())
    {
        line_string = Serial.readStringUntil('\n');
        if (line_string.length() < kLineBufSize)
        {
            line_string.toCharArray(line, kLineBufSize);

            char *argument;
            int counter = 0;

            argument = strtok(line, " ");

            while ((argument != NULL))
            {
                if (counter < kMaxNumArgs)
                {
                    if (strlen(argument) < kArgBufSize)
                    {
                        strcpy(args[counter], argument);
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

void clearArgs()
{
    memset(line, 0, kLineBufSize);
    memset(args, 0, sizeof(args[0][0]) * kMaxNumArgs * kArgBufSize);
}