//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_ITEMCHAIN_H
#define ILLATE_ITEMCHAIN_H

#include "item.h"

class ItemChain : public Item{
public:
    ItemType type(){ return CHAIN; }
private:
};

#endif //ILLATE_ITEMCHAIN_H
