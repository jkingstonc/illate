//
// Created by james on 04/01/2020.
//

#ifndef ILLATE_API_H
#define ILLATE_API_H

#include <iostream>

#include "runtime.h"

#include "ibool.h"
#include "iint.h"
#include "idouble.h"
#include "istring.h"

#define RUNTIME_PTR std::shared_ptr<Runtime>

typedef int NATIVE_STATUS;
#define NATIVE_SUCCESS 0
#define NATIVE_FAILIURE 1

typedef int RUNTIME_STATUS;
#define RUNTIME_SUCCESS 0
#define RUNTIME_FAILIURE 1

typedef int STD_LIB_OPTIONS;
#define NO_LIB 0
#define STD_LIB 1

typedef int EXECUTION_STATUS;
#define EXECUTION_SUCCESS 0
#define EXECUTION_FAILIURE 1

namespace api {

    // Native functions return a success status as an int and take a Runtime pointer as an argument
    typedef int (*native_func)(RUNTIME_PTR);

    // Each native function needs to be binded to a string identifier
    typedef struct native_func_bind{
        std::string name;
        native_func func;
    }native_func_bind;



    /**
     * Runtime related functions
     * */
    static RUNTIME_PTR new_runtime() {return std::make_shared<Runtime>();}

    static void set_debug(RUNTIME_PTR runtime, bool debug){runtime->set_debug(debug);}

    static std::shared_ptr<items::Item> safe_call(RUNTIME_PTR runtime){
        // We need to check if this is actually a core
        // Get the current execution stack in use and attempt to pop a 'callable' from it
        std::shared_ptr<items::Item> core_to_call = runtime->get_currently_executing()->pop();
        return core_to_call->call();
    }

    static std::shared_ptr<items::Item> debug_call(RUNTIME_PTR runtime){
        // We need to check if this is actually a core
        // Get the current execution stack in use and attempt to pop a 'callable' from it
        std::shared_ptr<items::Item> core_to_call = runtime->get_currently_executing()->peek();
        return core_to_call->call();
    }

    // Used for explicitly returning from breakpoints
    static std::shared_ptr<items::Item> resume_call(RUNTIME_PTR runtime){
        return std::dynamic_pointer_cast<items::Core>(runtime->get_currently_executing()->peek())->explicit_resume_debug();
    }

    static void push_stack(RUNTIME_PTR runtime, std::shared_ptr<items::Item> item){
        runtime->get_currently_executing()->push(item);
    }
    static std::shared_ptr<items::Item> pop_stack(RUNTIME_PTR runtime){
        return runtime->get_currently_executing()->pop();
    }
    static std::shared_ptr<items::Item> peek_stack(RUNTIME_PTR runtime){return nullptr;}

    // Load the environment with globals and optionally the standard library to the runtime
    static RUNTIME_STATUS load_env(RUNTIME_PTR runtime, STD_LIB_OPTIONS options){
        runtime->bind_enviroment(std::make_shared<items::Icontainer>());
        return RUNTIME_SUCCESS;
    }

    // Load a script into a runtime via a script name
    static RUNTIME_STATUS load_script(RUNTIME_PTR runtime, std::string filename){
        // First make a script object
        std::shared_ptr<std::vector<uint8_t>> code = std::make_shared<std::vector<uint8_t>>(std::vector<uint8_t >({
            0, 3, 0, 2
        }));
        std::shared_ptr<Script> script = std::make_shared<Script>(filename, code);
        // Make a core and bind it to the script
        std::shared_ptr<items::Core> core = std::make_shared<items::Core>(script);
        // Push the core to the stack to be called
        push_stack(runtime, core);
        return RUNTIME_SUCCESS;
    }
    // Load a fragment of code into a runtime via raw bytes
    static RUNTIME_STATUS load_fragment(RUNTIME_PTR runtime, uint8_t bytecode[]){ return RUNTIME_SUCCESS;}

    static std::shared_ptr<items::Item> get_global(RUNTIME_PTR runtime, std::string identifier){return nullptr;}
    static void set_global(RUNTIME_PTR runtime, std::string identifier, items::Item item);






    /**
     * Library related functions
     * */
    // Bind a native library of C functions to the runtime
    static int bind_native_lib(RUNTIME_PTR runtime, std::string lib_name, std::shared_ptr<native_func_bind[]> lib){
        return NATIVE_SUCCESS;
    }





    /**
     * Item related functions
     * */
    static std::shared_ptr<items::Ibool> to_item(bool val) {
        return items::Ibool::to_item(val);
    }

    static std::shared_ptr<items::Iint> to_item(int val) {
        return items::Iint::to_item(val);
    }

    static std::shared_ptr<items::Idouble> to_item(double val) {
        return items::Idouble::to_item(val);
    }

    static std::shared_ptr<items::Istring> to_item(std::string val) {
        return items::Istring::to_item(val);
    }
};

#endif //ILLATE_API_H