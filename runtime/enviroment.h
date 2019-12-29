//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_ENVIROMENT_H
#define ILLATE_ENVIROMENT_H

#include <memory>

#include "icontainer.h"
#include "istring.h"

std::shared_ptr<IContainer> gen_env(){
    return std::make_shared<IContainer>();
}

#endif //ILLATE_ENVIROMENT_H
