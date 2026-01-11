#include <stdio.h>

#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm;

static void resetStack()
{
    vm.stackTop = vm.stack;
};

void initVM()
{
    resetStack();
}

void freeVM()
{
}

void push(Value value)
{
    *vm.stackTop++ = value;
}

Value pop()
{
    return *--vm.stackTop;
}

static InterpretResult run()
{
    #define READ_BYTE() (*vm.ip++)
    #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
    #define BINARY_OP(op) \
        do {\
            double b = pop();\
            double a = pop();\
            push(a op b);\
        }while(false)

    for (;;) {
        int offset = (int)(vm.ip - vm.chunk->code);
    
    #ifdef DEBUG_TRACE_EXECUTION
        if (offset < vm.chunk->count) {
            printf("            ");
            for(Value* slot = vm.stack; slot < vm.stackTop; slot++) {
                printf("[");
                printValue(*slot);
                printf("]");
            }
            printf("\n");

            disassembleInstruction(vm.chunk, offset);
        }
    #endif
    
        // Stop if we're at the end
        if (offset >= vm.chunk->count) break;
    
        uint8_t instruction = READ_BYTE();
    
        switch (instruction) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                push(constant);
                break;
            }
            case OP_ADD: {
                BINARY_OP(+);
                break;
            }
            case OP_SUBTRACT: {
                BINARY_OP(-);
                break;
            }
            case OP_MULTIPLY: {
                BINARY_OP(*);
                break;
            }
            case OP_DIVIDE: {
                BINARY_OP(/);
                break;
            }
            case OP_NEGATE: {
                push(-pop());
                break;
            }
            case OP_RETURN: {
                printValue(pop());
                printf("\n");
                return INTERPRET_OK;
            }
            default:
                fprintf(stderr, "Unknown opcode %d at offset %d\n", instruction, offset);
                return INTERPRET_RUNTIME_ERROR;
        }
    }
    

    #undef READ_BYTE
    #undef READ_CONSTANT
    #undef BINARY_OP

    return INTERPRET_OK;
}

InterpretResult interpret(Chunk *chunk)
{
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}
