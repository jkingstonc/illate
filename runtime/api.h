//
// Created by james on 04/01/2020.
//

#ifndef ILLATE_API_H
#define ILLATE_API_H

#include "ibool.h"
#include "iint.h"
#include "idouble.h"
#include "istring.h"

namespace api {

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