//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_CORE_H
#define ILLATE_CORE_H

#include <stack>

#include "item.h"
#include "script.h"

namespace items{
    class Core : public items::Item{
    public:

        Core(std::shared_ptr<Script> script, std::shared_ptr<Icontainer> parent_env) : script(script), parent_env(parent_env){}
        Core(std::shared_ptr<Script> script) : script(script), parent_env(nullptr){}

        items::ItemType type();
        std::string to_string_native();

        std::shared_ptr<items::Item> call();
        // Here arg1 can be a single item or an item chain
        std::shared_ptr<items::Item> call(std::shared_ptr<items::Item> arg1);
        std::shared_ptr<items::Item> call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2);
        std::shared_ptr<items::Item> call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2, std::shared_ptr<items::Item> arg3);

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
};

#endif //ILLATE_CORE_H
