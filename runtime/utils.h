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

namespace utils{
    static std::shared_ptr<items::Ibool> to_item(bool val){
        return items::Ibool::to_item(val);
    }
    static std::shared_ptr<items::Iint> to_item(int val){
        return items::Iint::to_item(val);
    }
    static std::shared_ptr<items::Idouble> to_item(double val){
        return items::Idouble::to_item(val);
    }
    static std::shared_ptr<items::Istring> to_item(std::string val){
        return items::Istring::to_item(val);
    }
};

#endif //ILLATE_UTILS_H
