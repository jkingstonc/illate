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

typedef struct ScriptInfo{
    std::string filename;
}ScriptInfo;

class Script{
public:

    Script(std::shared_ptr<std::vector<uint8_t>> code) : code(code){
        this->info.filename = std::string("not a file :(");
    }

    Script(std::string filename, std::shared_ptr<std::vector<uint8_t>> code) : code(code){
        this->info.filename = filename;
    }

    ScriptInfo info;
    // The code to execute
    std::shared_ptr<std::vector<uint8_t>> code;

    // Number of locals in this script
    int local_count;
private:
    // Take the serialized globals/locals and load them into items::Item format
    void deserialize_globals();
    void deserialize_locals();
};

#endif //ILLATE_SCRIPT_H
