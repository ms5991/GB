#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "lookup.h"
#define INPUT_BUFFER_SIZE 32
#define MAX_OPCODE_COUNT 1024


int getOpcodeInput(char* inputBuffer)
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
        // assume the input is well formatted
        assemblyCodeRet = getOpcodeInput(assemblyBuffer);
        opcodeRet = getOpcodeInput(opcodeBuffer);

        if (assemblyCodeRet && opcodeRet)
        {
            assembly[i] = strdup(assemblyBuffer);
            putRet = putValue(assemblyBuffer, opcodeBuffer);

            if (!putRet)
            {
                printf("ERROR putting value in lookup!");
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

int splitStringToBytes(char* str, uint8_t* bytes, int numBytes)
{
    int i;
    for(i=0;i<numBytes;i++)
    {
        char buffer[3];
        buffer[0] = str[2*i];
        buffer[1] = str[2*i+1];
        buffer[2] = '\0';
        bytes[i] = (uint8_t)strtol(buffer, NULL, 16);
#ifdef DEBUG
        printf("Wrote byte [%x]\n", bytes[i]);
#endif
    }

    return numBytes;
}

int main(int argc, char const *argv[])
{
    buildOpcodeLookupTable();

    const char *inputFile =  argv[1];
    const char *outputFile =  argv[2];

    printf("Input inputFilePtr=[%s], output inputFilePtr=[%s]\n", inputFile, outputFile);

    FILE* inputFilePtr = fopen(inputFile, "r");
    uint8_t inputFileInMem[MAX_OPCODE_COUNT];
    uint16_t totalBytes = 0;
    if (inputFilePtr != NULL)
    {
        char line[INPUT_BUFFER_SIZE];
        while (!feof(inputFilePtr))
        {
            if (fgets(line, sizeof(line), inputFilePtr) != NULL)
            {
                removeNewlineAndCarriageReturn(line);
                char* opcodeWithPrefix = getValue(line);

                int len = strlen(opcodeWithPrefix);
                int numBytes = len / 2;
                uint8_t* bytes = (uint8_t*)malloc(numBytes * sizeof(uint8_t));

                splitStringToBytes(opcodeWithPrefix, bytes, numBytes);
                int i;
                for (i=0;i<numBytes;i++)
                {
                    inputFileInMem[totalBytes] = bytes[i];
                    totalBytes++;
                }

                free(bytes);
                free(opcodeWithPrefix);
           }
        }

        fclose(inputFilePtr);

        FILE* outputFilePtr = fopen(outputFile, "w");

        if (outputFilePtr != NULL)
        {
            printf("Writing length [%d]\n", totalBytes);
            fwrite(&totalBytes, sizeof(uint16_t), 1, outputFilePtr);
            int i;
            for (i=0;i<totalBytes;i++)
            {
                printf("Writing value [%x]\n", inputFileInMem[i]);
                fwrite(&inputFileInMem[i], sizeof(uint8_t), 1, outputFilePtr);
            }

            fclose(outputFilePtr);
        }
        else
        {
            printf("No outputFilePtr!\n");
        }

    }
    else
    {
        printf("No inputFilePtr!\n");
    }


    freeTable();
}

