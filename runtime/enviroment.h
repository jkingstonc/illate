//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_ENVIROMENT_H
#define ILLATE_ENVIROMENT_H

#include <memory>

#include "icontainer.h"
#include "istring.h"

// Generates the initial environment variables for startup
std::shared_ptr<items::Icontainer> gen_env(){
    return std::make_shared<items::Icontainer>();
}

// When changing variable scopes, we have to bind the items from the previous scope to the current scope
std::shared_ptr<items::Icontainer> bind_item_scopes(){
    return std::make_shared<items::Icontainer>();
}

#endif //ILLATE_ENVIROMENT_H
