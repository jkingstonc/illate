//
// Created by james-laptop on 05/01/2020.
//

#ifndef ILLATE_CLR_H
#define ILLATE_CLR_H

namespace {
    enum Opcodes {
        DEBUG,

        NOP,
        END,
        PAUSE,

        /**
         * Will load a value from the current constant scope onto the stack
         * */
        LD_CONST,
        /**
         * Will load a variable from a higher scope (global or local). When a var is used, we identify it by
         * our local "var table" to get its identifier, we then use this identifier as a key in the runtime environment
         * */
        LD_VAR,
        LD_LOC,
        /**
         * Will set a variable value from a higher scope (global or local). When a var is used, we identify it by
         * our local "var table" to get its identifier, we then use this identifier as a key in the runtime environment
         * */
        SET_VAR,
        SET_LOC,

        ADD,
        SUB,
        MUL,
        DIV,
        MOD,
        REM,
        POW,
        NEG,

        AND,
        OR,
        NOT,

        GOTO,
        EQ,
        LT,
        GT,

        CALL,
        RETURN,

        CHAIN_VALS,             // Will take items on the stack and populate them into a chain

        MAKE,                   // Create a signature for a function or class that is defined in the constants table
        INSTANCE,               // Create an instance of an object
        INSTANCE_CONTAINER,     // Creates a new instance of a container
    };
};
#endif //ILLATE_CLR_H
