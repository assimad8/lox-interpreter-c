# clox — A Bytecode Interpreter for Lox

A complete bytecode virtual machine implementation of the Lox programming language,
written in C and based on the book *Crafting Interpreters* by Robert Nystrom.

## Overview

This project is an educational implementation of a bytecode interpreter for the
Lox programming language. The goal is to deeply understand:

- Language design
- Parsing and compilation
- Bytecode virtual machines
- Memory management and garbage collection
- Interpreter performance techniques

The implementation follows the architecture and progression of
*Crafting Interpreters*, with additional structure, testing, and documentation.

## Implemented Features

- Bytecode virtual machine
- Stack-based execution model
- String objects with interning and hashing
- Open-addressed hash tables
- Global variables
- Variable declarations and reads
- Expression and print statements
- Runtime error handling

## Project Structure

clox/
├── include/     # Public headers
    ├── common.h     → shared macros, config, platform helpers
    ├── chunk.h      → bytecode chunk interface
    ├── compiler.h   → parser + bytecode emitter
    ├── debug.h      → disassembler
    ├── memory.h     → allocation + GC
    ├── object.h     → heap object definitions
    ├── scanner.h    → tokenizer
    ├── table.h      → hash tables
    ├── value.h      → Value representation
    └── vm.h         → virtual machine API
├── src/         # Implementation files
    ├── main.c       → program entry + REPL + file runner
    ├── chunk.c      → bytecode storage
    ├── compiler.c  → parser + compiler
    ├── debug.c     → bytecode disassembly
    ├── memory.c    → allocator + GC (later)
    ├── object.c    → strings, functions, closures, classes
    ├── scanner.c   → lexical analysis
    ├── table.c     → hash tables
    ├── value.c     → Value utilities
    └── vm.c        → interpreter loop + opcode execution
├── main.c # Program entry point
├── build/ # Object files (generated)
├── bin/ # Final executable (generated)
│   └── clox
└── Makefile # Build system

- `scanner`   — Lexical analysis
- `compiler`  — Parsing and bytecode emission
- `vm`        — Bytecode execution engine
- `object`    — Heap-allocated objects (strings, functions, etc.)
- `table`     — Hash table implementation
- `memory`    — Allocation and garbage collection

## ⚙️ Build System

Requirements:
- GCC or Clang
- Make

---

The project uses a professional Makefile with:

- Separate `build/` and `bin/` directories  
- Debug and release builds  
- Automatic directory creation  
- Clean and rebuild targets  

### 🔹 Debug Build (default)

Includes debug symbols and no optimization:

```bash
make

###🔹 Build the interpreter:

```sh
make debug

---

## 6. Run Instructions

Very important.

```md
## Run
make run

Run a Lox script:

```sh
./clox file.lox


---
## Release Build (optimized)

```sh
make release

---
## Start the interactive REPL

Executable will be located in:

```sh
./bin/clox

## Clean build artifacts
```sh
make clean
## Full Rebuild
```sh
make rebuild

## 7. Example Program

Shows the language works.

```md
## Example

```lox
var message = "Hello, world!";
print message;

## Output:
```sh
Hello, world!

## Purpose

This project focuses on mastering:

- Lexical scanning
- Pratt parsing
- Bytecode generation
- Virtual machine execution
- Manual memory management in C
- Hash tables and collision handling
- String interning
- Global variable systems
- Compiler and VM architecture

## Current Status

Implemented up to:

    Hash tables

    String interning

    Global variables

    Statements

    Declarations

    Reading variables

Planned next steps:

    Variable assignment

    Local variables

    Scope resolution

    Control flow

    Functions and closures

## Roadmap

Planned features:

- Local variables and lexical scoping
- Functions and closures
- Upvalues
- Garbage collection
- Classes and instances
- Method dispatch
- Native functions

## References

- Robert Nystrom — *Crafting Interpreters*
  https://craftinginterpreters.com/
- All language design and architecture credit goes to the author.

## 👤 Author

Imad Lakhbizi
Self-taught systems and language learner
Focused on compilers, interpreters, and low-level programming

## License

This project is for educational purposes.  
Original language and design by Robert Nystrom.

