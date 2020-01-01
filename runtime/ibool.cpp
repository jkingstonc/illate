//
// Created by james on 29/12/2019.
//

#include "ibool.h"

items::Ibool::Ibool(bool val) : val(val) {
}

items::ItemType items::Ibool::type(){
    return items::ItemType::BOOLEAN;
}

std::string items::Ibool::to_string_native(){
    return (this->val == true) ? std::string("true") : std::string("false");
}