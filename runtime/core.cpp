//
// Created by james on 29/12/2019.
//

#include "core.h"

void items::Core::bind_enviroment(std::shared_ptr<items::Icontainer> enviroment){
    this->enviroment = enviroment;
}
void items::Core::bind_scoped_locals(std::shared_ptr<items::ScopedLocals> upper){
    this->locals = upper;
    // Initialise our own local array to the size of the ammount of locals we have
    this->locals->locals = std::make_shared<items::Icontainer>();
}

std::shared_ptr<items::Item> items::Core::pop(){
    std::shared_ptr<items::Item> top = this->exec_stack.top();
    this->exec_stack.pop();
    return top;
}

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