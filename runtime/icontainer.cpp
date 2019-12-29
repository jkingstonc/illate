//
// Created by james on 29/12/2019.
//

#include "icontainer.h"

Icontainer::Icontainer() {

}

ItemType Icontainer::type(){
    return ItemType::CONTAINER;
}
std::string Icontainer::to_string_native(){
    return std::string("Container");
}