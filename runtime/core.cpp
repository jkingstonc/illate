//
// Created by james on 29/12/2019.
//

#include "core.h"

ItemType type(){
    return ItemType::CORE;
}

std::string Core::to_string_native(){
    return std::string("Core");
}

/**
 * Every Item is callable, it can be called with any amount of arguments
 * */
void Core::call(){
    std::cout << "lol" << std::endl;
};
// Here arg1 can be a single item or an item chain
void Core::call(std::shared_ptr<Item> arg1){};
void Core::call(std::shared_ptr<Item> arg1, std::shared_ptr<Item> arg2){};
void Core::call(std::shared_ptr<Item> arg1, std::shared_ptr<Item> arg2, std::shared_ptr<Item> arg3){};