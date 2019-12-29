//
// Created by james on 29/12/2019.
//

#include "iint.h"

Iint::Iint(int val) : val(val) {

}

std::string Iint::to_string_native() {
    return std::string(std::to_string(this->val));
}