//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_ENVIROMENT_H
#define ILLATE_ENVIROMENT_H

#include <memory>

#include "icontainer.h"
#include "istring.h"

std::shared_ptr<Icontainer> gen_env(){
    return std::make_shared<Icontainer>();
}

#endif //ILLATE_ENVIROMENT_H
