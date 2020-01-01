//
// Created by james on 29/12/2019.
//

#include "istring.h"

items::Istring::Istring(std::string val) : val(val){

}

items::ItemType items::Istring::type(){
    return items::ItemType::STRING;
}

std::string items::Istring::to_string_native(){
    return this->val;
}