//
// Created by james on 01/01/2020.
//

#ifndef ILLATE_LOADER_H
#define ILLATE_LOADER_H

#include "script.h"

/**
 * This class is responsible for loading data into containers ready to run.
 * Used to load iasm, load cores, load enviroments etc.
 * */
class Loader{
public:
    // Load a series of bytes into Script format
    static std::shared_ptr<Script> load_bytes();
    // Load an iasm file into Script format
    static std::shared_ptr<Script> load_iasm();
private:
};

#endif //ILLATE_LOADER_H
