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

        if (i == INPUT_BUFFER_SIZE - 1 || current == '\n' || current == '\r' || current == '\0')
        {
            inputBuffer[i] = '\0';
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

void removeNewlineAndCarriageReturn(char* line)
{
    int len = strlen(line);
    if (line[len - 2] == '\r')
	line[len - 2] = '\0';
    if (line[len - 1] == '\n')
        line[len - 1] = '\0';
}

int main(int argc, char const *argv[])
{
    buildOpcodeLookupTable();

    const char *fileName =  argv[1];

    printf("File: [%s]\n", fileName);

    FILE* file = fopen(fileName, "r");
    if (file != NULL)
    {
        char line[INPUT_BUFFER_SIZE];
        while (!feof(file))
        {
            if (fgets(line, sizeof(line), file) != NULL)
            {
		removeNewlineAndCarriageReturn(line);
		char* opcode = getValue(line);
                printf("Got value [%s] which has opcode [%s] in hex [%x]\n", line, opcode, strtol(opcode, NULL, 16));
		free(opcode);
           }
        }

        fclose(file);
    }
    else
    {
        printf("No file!\n");
    }


    freeTable();
}

