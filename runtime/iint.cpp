//
// Created by james on 29/12/2019.
//

#include "iint.h"

items::Iint::Iint(int val) : val(val) {

}

std::string items::Iint::to_string_native() {
    return std::string(std::to_string(this->val));
}
bool items::Iint::to_bool_native(){
    return (this->val>0) ? true : false;
}
std::uint8_t items::Iint::to_byte_native(){
    return (uint8_t)this->val;
}
int items::Iint::to_int_native(){
    return this->val;
}
double items::Iint::to_double_native(){
    return (double)this->val;
}