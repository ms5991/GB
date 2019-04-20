#ifndef _TEST

#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "mem.h"

uint8_t* loadRom(const char* fileName, uint16_t* size)
{
    int i;

    // open the input file
    FILE* fp = fopen(fileName, "r");
    uint8_t* rom = NULL;
    if (fp != NULL)
    {
        // the first sizeof(uint16_t) bytes are the size of the rom
        fread(size, sizeof(uint16_t), 1, fp);

        // allocate the memory to read input from file
        rom = (uint8_t*)malloc(*size * sizeof(uint8_t));

        // read size bytes from the file
        for (i=0;i<*size;i++)
        {
            uint8_t value;
            fread(&value, sizeof(uint8_t), 1, fp);
            rom[i] = value;
        }
        fclose(fp);
    }

    return rom;
}


int main(int argc, char const *argv[])
{
    cpu_t c;
    mem_t m;

    // assume this is valid for now
    const char *fileName =  argv[1];

    printf("File: [%s]\n", fileName);

    // get the rom from file
    uint16_t size;
    uint8_t* rom = loadRom(fileName, &size);

    // put rom in memory
    initMem(&m, rom, size);

    // init the cpu
    initCpu(&c);

    free(rom);

#ifdef DEBUG 
    printf("Got rom size [%d]\n", size);
    dumpMem(&m, size);
#endif

    int i;
    for (i=0;i<size;i++)
    {
        // execute!
        executeOpcode(fetchEightBitMem(&m, readAndAdvancePC(&c)), &c, &m);
        printFlags(&c);
        printRegs(&c);
    }

    return 0;
}

#endif




