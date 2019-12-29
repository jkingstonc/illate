//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_CORE_H
#define ILLATE_CORE_H

#include <memory>
#include <stack>

#include "item.h"
#include "script.h"

class Core : public Item{
public:

    Core(std::shared_ptr<Script> script, std::shared_ptr<IContainer> parent_env) : script(script), parent_env(parent_env){}
    Core(std::shared_ptr<Script> script) : script(script), parent_env(nullptr){}

    void call() override{
        std::cout << "lol" << std::endl;
    };

    // The script that this accesses for code
    std::shared_ptr<Script> script;
    // The parent environment that we need to access
    std::shared_ptr<IContainer> parent_env;

private:
    // Our instruction pointer
    uint32_t ip;
    // The execution stack
    std::stack<Item> exec_stack;
};

#endif //ILLATE_CORE_H
