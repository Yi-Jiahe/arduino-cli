#include <Arduino.h>
#include "cli.h"

char line[LINE_BUF_SIZE];
char args[MAX_NUM_ARGS][ARG_BUF_SIZE];

int parseArgs()
{
    String line_string;

    if (Serial.available())
    {
        line_string = Serial.readStringUntil('\n');
        if (line_string.length() < LINE_BUF_SIZE)
        {
            line_string.toCharArray(line, LINE_BUF_SIZE);

            char *argument;
            int counter = 0;

            argument = strtok(line, " ");

            while ((argument != NULL))
            {
                if (counter < MAX_NUM_ARGS)
                {
                    if (strlen(argument) < ARG_BUF_SIZE)
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
    memset(line, 0, LINE_BUF_SIZE);
    memset(args, 0, sizeof(args[0][0]) * MAX_NUM_ARGS * ARG_BUF_SIZE);
}