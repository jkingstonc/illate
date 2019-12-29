//
// Created by james on 29/12/2019.
//

#include "idouble.h"

Idouble::Idouble(double val) : val(val){

}

std::string Idouble::to_string_native() {
    return std::string(std::to_string(this->val));
}