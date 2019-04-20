#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "lookup.h"
#define INPUT_BUFFER_SIZE 32
#define MAX_OPCODE_COUNT 1024

// gets input from stdin to build the opcode table
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

void buildOpcodeLookupTable()
{
    // buffers for loading file contents
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
            // put the value in the lookup
            putRet = putValue(assemblyBuffer, opcodeBuffer);

            if (!putRet)
            {
                printf("ERROR putting value in lookup!");
                return;
            }

            i++;
        }
    }

    // free input buffers
    free(assemblyBuffer);
    free(opcodeBuffer);
}

// checks the last two characters of the line and 
// replaces \r and \n with \0
void removeNewlineAndCarriageReturn(char* line)
{
    int len = strlen(line);
    if (line[len - 2] == '\r')
        line[len - 2] = '\0';
    if (line[len - 1] == '\n')
        line[len - 1] = '\0';
}

// returns an array of uint8_t as represented by str
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
    // create the assembly to opcode lookup table
    buildOpcodeLookupTable();

    // assembly file
    const char *inputFile =  argv[1];

    // binary file
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
            // get the next line of assembly from the file
            if (fgets(line, sizeof(line), inputFilePtr) != NULL)
            {
                // get rid of \n and \r
                removeNewlineAndCarriageReturn(line);

                // get the opcode from the lookup
                char* opcodeWithPrefix = getValue(line);

                // get the bytes represented by this opcode string
                int len = strlen(opcodeWithPrefix);
                int numBytes = len / 2;
                uint8_t* bytes = (uint8_t*)malloc(numBytes * sizeof(uint8_t));
                splitStringToBytes(opcodeWithPrefix, bytes, numBytes);

                // put the uint8_t into mem
                int i;
                for (i=0;i<numBytes;i++)
                {
                    inputFileInMem[totalBytes] = bytes[i];
                    totalBytes++;
                }

                // free memory
                free(bytes);
                free(opcodeWithPrefix);
           }
        }

        fclose(inputFilePtr);

        FILE* outputFilePtr = fopen(outputFile, "w");

        if (outputFilePtr != NULL)
        {
            printf("Writing length [%d]\n", totalBytes);

            // write the length as uint16_t
            fwrite(&totalBytes, sizeof(uint16_t), 1, outputFilePtr);
            int i;
            for (i=0;i<totalBytes;i++)
            {
                printf("Writing value [%x]\n", inputFileInMem[i]);

                // write each byte to the file
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

