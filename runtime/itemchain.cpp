//
// Created by james on 29/12/2019.
//

#include "itemchain.h"

ItemChain::ItemChain() {

}

Items::ItemType ItemChain::type(){
    return Items::ItemType::CHAIN;
}

std::string ItemChain::to_string_native(){
    return std::string("ItemChain");
}