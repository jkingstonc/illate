//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_CORE_H
#define ILLATE_CORE_H

#include <vector>
#include <stack>
#include <chrono>

#include "clr.h"
#include "item.h"
#include "script.h"

#define DEFAULT_DEBUG false
#define IS_DEBUG() this->exec_debug_state->is_debugging

#define GET_OP() this->script->code->at(this->ip)
#define NEXT() this->ip++;

class Runtime;

/**
 * An ExecutionDebugState is used to store information about the execution of a core in debug mode.
 * -> Whether the Core was in debug mode is stored
 * -> The IP value when a breakpoint is hit will be stored
 * */
typedef struct ExecutionDebugState{
    bool is_debugging;
    bool paused;
    uint8_t ip_at_break;
    std::chrono::high_resolution_clock::time_point start_time, end_time;
}ExecutionDebugState;

/**
 * A TraceBack entry will store information about key information about the completion
 * of a core call. This is mostly for debugging and so the core won't need to rely on this.
 * */
typedef struct TraceBack{

}TraceBack;

namespace items{

    // To store local variables in a scope, and any locals above the scope
    typedef struct ScopedLocals{
        std::shared_ptr<ScopedLocals> upper;
        std::shared_ptr<items::Icontainer> locals;
    }ScopedLocals;

    /**
     * NOTE: In cores, variables marked as not local will be assigned to the global namespace
     * */
    class Core : public items::Item{
    public:
        static bool debug_mode;
        // The script that this accesses for code
        std::shared_ptr<Script> script;

        Core();
        Core(std::shared_ptr<Script> script);

        void bind_enviroment(std::shared_ptr<items::Icontainer> enviroment);
        void bind_scoped_locals(std::shared_ptr<ScopedLocals> upper);

        void push(std::shared_ptr<items::Item> item);
        std::shared_ptr<items::Item> pop();
        std::shared_ptr<items::Item> peek();

        std::shared_ptr<ExecutionDebugState> get_exec_debug_state();
        std::shared_ptr<items::Item> explicit_resume_debug();

        /**
         * Inherited items::Item methods
         * */
        items::ItemType type();
        std::string to_string_native();
        std::shared_ptr<items::Item> call();
        // Here arg1 can be a single item or an item chain
        std::shared_ptr<items::Item> call(std::shared_ptr<items::Item> arg1);
        std::shared_ptr<items::Item> call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2);
        std::shared_ptr<items::Item> call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2, std::shared_ptr<items::Item> arg3);

    private:
        std::shared_ptr<ExecutionDebugState> exec_debug_state;

        // Our instruction pointer
        uint32_t ip = 0;
        // The execution stack
        std::stack<std::shared_ptr<items::Item>> exec_stack;
        // Our locals along with upper locals
        std::shared_ptr<ScopedLocals> locals;
        std::shared_ptr<items::Icontainer> enviroment;
        // Run the 'fetch-decode-execute' cycle
        void run_fde();
        /** When we hit a breakpoint, the core will exit. However, it's sate will be saved in memory for
        resuming the fde later */
        void save_debug_state();
        void resume_debug_state();
    };
};

#endif //ILLATE_CORE_H
