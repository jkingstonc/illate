//
// Created by james on 29/12/2019.
//

#include "nill.h"

Inill::Inill(){

}

ItemType Inill::type(){
    return ItemType::NIL;
}

std::string Inill::to_string_native(){
    return std::string("nill");
}