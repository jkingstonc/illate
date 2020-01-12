//
// Created by james on 29/12/2019.
//

#include "itemchain.h"

items::ItemChain::ItemChain() {

}

items::ItemType items::ItemChain::type(){
    return items::ItemType::CHAIN;
}

bool items::ItemChain::equal(std::shared_ptr<Item> rhs){
    return false;
}

std::string items::ItemChain::to_string_native(){
    return std::string("ItemChain");
}