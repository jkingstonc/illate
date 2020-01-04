//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_CORE_H
#define ILLATE_CORE_H

#include <stack>

#include "item.h"
#include "script.h"

class Runtime;

namespace items{

    // To store local variables in a scope, and any locals above the scope
    typedef struct ScopedLocals{
        std::shared_ptr<ScopedLocals> upper;
        std::shared_ptr<Item[]> locals;
    }ScopedLocals;

    /**
     * NOTE: In cores, variables marked as not local will be assigned to the global namespace
     * */
    class Core : public items::Item{
    public:
        // Store a reference to the runtime
        Runtime* runtime;
        // The script that this accesses for code
        std::shared_ptr<Script> script;

        Core(Runtime* runtime) : runtime(runtime){}
        Core(Runtime* runtime, std::shared_ptr<Script> script) : runtime(runtime), script(script){}

        void bind_scoped_locals(std::shared_ptr<ScopedLocals> upper);

        items::ItemType type();
        std::string to_string_native();

        std::shared_ptr<items::Item> call();
        // Here arg1 can be a single item or an item chain
        std::shared_ptr<items::Item> call(std::shared_ptr<items::Item> arg1);
        std::shared_ptr<items::Item> call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2);
        std::shared_ptr<items::Item> call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2, std::shared_ptr<items::Item> arg3);

    private:
        // Our instruction pointer
        uint32_t ip;
        // The execution stack
        std::stack<Item> exec_stack;
        // Our locals along with upper locals
        std::shared_ptr<ScopedLocals> locals;
    };
};

#endif //ILLATE_CORE_H
