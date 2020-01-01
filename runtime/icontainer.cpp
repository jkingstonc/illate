//
// Created by james on 29/12/2019.
//

#include "icontainer.h"

items::Icontainer::Icontainer() {

}

items::ItemType items::Icontainer::type(){
    return items::ItemType::CONTAINER;
}
std::string items::Icontainer::to_string_native(){
    return std::string("Container");
}