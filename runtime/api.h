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

#define NATIVE_SUCCESS 0
#define NATIVE_FAILIURE 1

namespace api {

    // Native functions return a success status as an int and take a Runtime pointer as an argument
    typedef int (*native_func)(std::shared_ptr<Runtime>);

    // Each native function needs to be binded to a string identifier
    typedef struct native_func_bind{
        std::string name;
        native_func func;
    }native_func_bind;

    static std::shared_ptr<Runtime> new_runtime() {
        return std::make_shared<Runtime>();
    }

    // Bind a native library of C functions to the runtime
    static int bind_native_lib(std::shared_ptr<Runtime> runtime, std::string lib_name, std::shared_ptr<native_func_bind[]> lib){
        return NATIVE_SUCCESS;
    }

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