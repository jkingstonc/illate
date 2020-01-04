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
#include "icontainer.h"

class Script{
public:

    // Create a script assuming we haven't defined an enviroment
    Script(std::string filename,
        std::shared_ptr<uint8_t > code) : filename(filename), code(code){}

    // Create a script assuming we have an enviroment
    Script(std::string filename,
            std::shared_ptr<items::Icontainer> enviroment,
            std::shared_ptr<uint8_t > code) : filename(filename), enviroment(enviroment), code(code){}

    // The filename of the script, if a file wasn't provded then the filename will be initialised to "NIL"
    std::string filename;
    // The enviroment that this script uses
    // With subsequent Core calls (nested core calls), environments will be concatenated
    std::shared_ptr<items::Icontainer> enviroment;
    // The code to execute
    std::shared_ptr<uint8_t> code;
private:
};

#endif //ILLATE_SCRIPT_H
