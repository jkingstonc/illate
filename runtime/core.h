//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_CORE_H
#define ILLATE_CORE_H

#include <stack>

#include "item.h"
#include "script.h"

class Core : public Item{
public:

    Core(std::shared_ptr<Script> script, std::shared_ptr<Icontainer> parent_env) : script(script), parent_env(parent_env){}
    Core(std::shared_ptr<Script> script) : script(script), parent_env(nullptr){}

    ItemType type();
    std::string to_string_native();

    void call();
    // Here arg1 can be a single item or an item chain
    void call(std::shared_ptr<Item> arg1);
    void call(std::shared_ptr<Item> arg1, std::shared_ptr<Item> arg2);
    void call(std::shared_ptr<Item> arg1, std::shared_ptr<Item> arg2, std::shared_ptr<Item> arg3);

    // The script that this accesses for code
    std::shared_ptr<Script> script;
    // The parent environment that we need to access
    std::shared_ptr<Icontainer> parent_env;

private:
    // Our instruction pointer
    uint32_t ip;
    // The execution stack
    std::stack<Item> exec_stack;
};

#endif //ILLATE_CORE_H
