//
// Created by james on 29/12/2019.
//

#ifndef ILLATE_UTILS_H
#define ILLATE_UTILS_H

#include <memory>

#include "ibool.h"
#include "iint.h"
#include "idouble.h"
#include "istring.h"

namespace Utils{
    static std::shared_ptr<Ibool> to_item(bool val){
        return Ibool::to_item(val);
    }
    static std::shared_ptr<Iint> to_item(int val){
        return Iint::to_item(val);
    }
    static std::shared_ptr<Idouble> to_item(double val){
        return Idouble::to_item(val);
    }
    static std::shared_ptr<Istring> to_item(std::string val){
        return Istring::to_item(val);
    }
};

#endif //ILLATE_UTILS_H
