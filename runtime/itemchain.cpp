//
// Created by james on 29/12/2019.
//

#include "itemchain.h"

ItemChain::ItemChain() {

}

ItemType ItemChain::type(){
    return ItemType::CHAIN;
}

std::string ItemChain::to_string_native(){
    return std::string("ItemChain");
}