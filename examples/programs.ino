#include <Arduino.h>
#include "cli.h"

/* ---------------------- Programs ---------------------------*/
/*

*/

// Provide a description on how to use the tool here.
void printHelp()
{
    Serial.println("ping");
    Serial.println("add a b");
}

void pong()
{
    Serial.println("pong");
}

void add(int a, float b)
{
    Serial.print(a);
    Serial.print(" + ");
    Serial.print(b);
    Serial.print(" = ");
    Serial.println(a + b);
}

/* --------------------- Setup & Main loop --------------------*/

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    if (parseArgs() == 0)
    {
        if (strcmp(args[0], "ping") == 0)
        {
            pong();
        }
        else if (strcmp(args[0], "add") == 0)
        {
            add(atoi(args[1]), atof(args[2]));
        }
        else
        {
            Serial.println("No matching commands");
            printHelp();
        }

        clearArgs();
    }

    // Other tasks can also be run while no programs are running
}