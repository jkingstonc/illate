//
// Created by james on 29/12/2019.
//

#include "itemchain.h"

items::ItemChain::ItemChain() {

}

items::ItemType items::ItemChain::type(){
    return items::ItemType::CHAIN;
}

std::string items::ItemChain::to_string_native(){
    return std::string("ItemChain");
}