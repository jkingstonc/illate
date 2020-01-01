//
// Created by james on 29/12/2019.
//

#include "idouble.h"

items::Idouble::Idouble(double val) : val(val){

}

std::string items::Idouble::to_string_native() {
    return std::string(std::to_string(this->val));
}
bool items::Idouble::to_bool_native(){
    return (this->val>0) ? true : false;
}
std::uint8_t items::Idouble::to_byte_native(){
    return (uint8_t)this->val;
}
int items::Idouble::to_int_native(){
    return (int)this->val;
}
double items::Idouble::to_double_native(){
    return this->val;
}