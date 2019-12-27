//
// Created by james on 27/12/2019.
//

/*
 * A script is an encapsulation of a program to execute, it can be a compiled file or a single line of
 * bytecode instructions.
 * */

#ifndef ILLATE_SCRIPT_H
#define ILLATE_SCRIPT_H

#include <cstdint>
#include <memory>

#include "item.h"

class Script{
public:
    Script(std::string filename, std::shared_ptr<Item> constants, std::shared_ptr<uint8_t > code) : filename(filename), constants(constants), code(code){}

    // The filename of the script, if a file wasn't provded then the filename will be initialised to "NIL"
    std::string filename;
    // The constants used in execution
    std::shared_ptr<Item> constants;
    // The code to execute
    std::shared_ptr<uint8_t > code;
private:
};

#endif //ILLATE_SCRIPT_H
