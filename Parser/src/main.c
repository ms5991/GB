#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "lookup.h"
#define INPUT_BUFFER_SIZE 32


int getInput(char* inputBuffer)
{
    int i = 0;
    int current;
    while (i < INPUT_BUFFER_SIZE)
    {
        current = getchar();

        if (current == EOF)
        {
            return 0;
        }

        if (i == INPUT_BUFFER_SIZE - 1 || current == '\n' || current == '\r')
        {
            inputBuffer[i] = '\0';
            break;
        }
        else if (current == '\0')
        {
            inputBuffer[i] = current;
            break;
        }
        else
        {
            inputBuffer[i] = current;
        }
        i++;
    }

    return 1;
}

char* assembly[500];

void buildOpcodeLookupTable()
{
    char* assemblyBuffer = (char*)malloc(INPUT_BUFFER_SIZE * sizeof(char));
    char* opcodeBuffer = (char*)malloc(INPUT_BUFFER_SIZE * sizeof(char));
    int assemblyCodeRet = 1;
    int opcodeRet = 1;
    int putRet = 1;
    int i = 0;
    while (opcodeRet)
    {
        assemblyCodeRet = getInput(assemblyBuffer);
        opcodeRet = getInput(opcodeBuffer);

        if (assemblyCodeRet && opcodeRet)
        {
            assembly[i] = strdup(assemblyBuffer);
            putRet = putValue(assemblyBuffer, opcodeBuffer);

            if (!putRet)
            {
                printf("ERROR putting in dic!");
                return;
            }

            i++;
        }
    }
}

int main(int argc, char const *argv[])
{
    buildOpcodeLookupTable();

    int i;
    for (i=0;i<500;i++)
    {
        char* opcode = getValue(assembly[i]);
  //      printf("For input [%s] got opcode [%s]\n", assembly[i], opcode);
        free(opcode);
        free(assembly[i]);
    }

    freeTable();
}

