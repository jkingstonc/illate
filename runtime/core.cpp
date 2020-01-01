//
// Created by james on 29/12/2019.
//

#include "core.h"

items::ItemType type(){
    return items::ItemType::CORE;
}

std::string items::Core::to_string_native(){
    return std::string("Core");
}

/**
 * Every Item is callable, it can be called with any amount of arguments
 * */
std::shared_ptr<items::Item> items::Core::call(){return nullptr;};
// Here arg1 can be a single item or an item chain
std::shared_ptr<items::Item> items::Core::call(std::shared_ptr<items::Item> arg1){return nullptr;};
std::shared_ptr<items::Item> items::Core::call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2){return nullptr;};
std::shared_ptr<items::Item> items::Core::call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2, std::shared_ptr<items::Item> arg3){return nullptr;};