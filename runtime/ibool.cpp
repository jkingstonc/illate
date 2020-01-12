//
// Created by james on 29/12/2019.
//

#include "ibool.h"

items::Ibool::Ibool(bool val) : val(val) {
}

items::ItemType items::Ibool::type(){
    return items::ItemType::BOOLEAN;
}

bool items::Ibool::equal(std::shared_ptr<items::Item> rhs){
    return false;
}

std::string items::Ibool::to_string_native(){
    return (this->val == true) ? std::string("true") : std::string("false");
}