//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_ITEMCHAIN_H
#define ILLATE_ITEMCHAIN_H

#include "item.h"

namespace items{
    class ItemChain : public items::Item{
    public:
        ItemChain();
        items::ItemType type();
        std::string to_string_native();

        int size();
        std::shared_ptr<Item> first();
        std::shared_ptr<Item> second();
        std::shared_ptr<Item> third();
    private:
    };
};

#endif //ILLATE_ITEMCHAIN_H
