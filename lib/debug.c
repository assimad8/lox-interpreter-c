#include <stdio.h>
#include "debug.h"
#include "value.h"

/* Private helpers */
static int simpleInstruction(const char* name, int offset);
static int constantInstruction(const char* name, Chunk* chunk, int offset);

/* Public API */
void disassembleChunk(Chunk* chunk, const char* name) {
    printf("== %s ==\n", name);

    for (int offset = 0; offset < chunk->count; )
        offset = disassembleInstruction(chunk, offset);
        
}

int disassembleInstruction(Chunk* chunk, int offset) {
    printf("%04d  ", offset);

    if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1]) {
        printf("    | ");
    } else {
        printf("%4d ", chunk->lines[offset]);
    }

    uint8_t instruction = chunk->code[offset];

    switch (instruction) {
        case OP_CONSTANT: {
            uint8_t constantIndex = chunk->code[offset + 1];
            printf("%-16s %4d '", "OP_CONSTANT", constantIndex);
            printValue(chunk->constants.values[constantIndex]);
            printf("'\n");
            return offset + 2;
        }
        case OP_NEGATE:{
            return simpleInstruction("OP_NEGATE",offset);
        }
        case OP_RETURN:{
            printf("OP_RETURN\n");
            return offset + 1;
        }
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}

/* Private helpers */
static int simpleInstruction(const char* name, int offset) {
    printf("%s\n", name);
    return offset + 1;
}

static int constantInstruction(const char* name, Chunk* chunk, int offset) {
    uint8_t constantIndex = chunk->code[offset + 1];

    // Print instruction, index, and value
    printf("%-16s %4d '", name, constantIndex);
    printValue(chunk->constants.values[constantIndex]);
    printf("'\n");

    return offset + 2;

}
