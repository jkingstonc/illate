//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_ENVIROMENT_H
#define ILLATE_ENVIROMENT_H

#include <memory>

#include "icontainer.h"
#include "istring.h"

#define PLATFORM Windows

std::shared_ptr<IContainer> gen_env(){
    return std::make_shared<IContainer>(to_item(std::string("windows")));
}

#endif //ILLATE_ENVIROMENT_H
