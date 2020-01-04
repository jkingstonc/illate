//
// Created by james on 04/01/2020.
//

#ifndef ILLATE_API_H
#define ILLATE_API_H

#include "runtime.h"

#include "ibool.h"
#include "iint.h"
#include "idouble.h"
#include "istring.h"

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
    typedef int (*native_func)(std::shared_ptr<Runtime>);

    // Each native function needs to be binded to a string identifier
    typedef struct native_func_bind{
        std::string name;
        native_func func;
    }native_func_bind;



    /**
     * Runtime related functions
     * */
    static std::shared_ptr<Runtime> new_runtime() {return std::make_shared<Runtime>();}

    static std::shared_ptr<items::Item> safe_call(std::shared_ptr<Runtime> runtime){return nullptr;}

    // Load the environment with globals and optionally the standard library to the runtime
    static RUNTIME_STATUS load_env(std::shared_ptr<Runtime> runtime, STD_LIB_OPTIONS options){return RUNTIME_SUCCESS;}

    // Load a script into a runtime via a script name
    static RUNTIME_STATUS load_script(std::shared_ptr<Runtime> runtime, std::string script){ return RUNTIME_SUCCESS;}
    // Load a fragment of code into a runtime via raw bytes
    static RUNTIME_STATUS load_fragment(std::shared_ptr<Runtime> runtime, std::byte bytecode[]){ return RUNTIME_SUCCESS;}

    static std::shared_ptr<items::Item> get_global(std::shared_ptr<Runtime> runtime, std::string identifier){return nullptr;}
    static void set_global(std::shared_ptr<Runtime> runtime, std::string identifier, items::Item item);

    static void push_stack(std::shared_ptr<Runtime> runtime, items::Item item){}
    static std::shared_ptr<items::Item> pop_stack(std::shared_ptr<Runtime> runtime, items::Item item){return nullptr;}
    static std::shared_ptr<items::Item> peek_stack(std::shared_ptr<Runtime> runtime, items::Item item){return nullptr;}





    /**
     * Library related functions
     * */
    // Bind a native library of C functions to the runtime
    static int bind_native_lib(std::shared_ptr<Runtime> runtime, std::string lib_name, std::shared_ptr<native_func_bind[]> lib){
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