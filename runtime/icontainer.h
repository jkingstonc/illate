//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_ICONTAINER_H
#define ILLATE_ICONTAINER_H

#include "item.h"
#include "istring.h"

namespace items{
    class Icontainer : public items::Item{
    public:
        Icontainer();
        ItemType type();
        std::string to_string_native();

        std::shared_ptr<Item> get(int by_index);
        std::shared_ptr<Item> get(std::shared_ptr<Item> by_reference);
        std::shared_ptr<Item> get(Item by_value);

        std::shared_ptr<Item> set(int by_index, std::shared_ptr<Item> new_value);
        std::shared_ptr<Item> set(std::shared_ptr<Item> by_reference, std::shared_ptr<Item> new_value);
        std::shared_ptr<Item> set(Item by_value, std::shared_ptr<Item> new_value);

        std::shared_ptr<Item> put(int by_index, std::shared_ptr<Item> new_value);
        std::shared_ptr<Item> put(std::shared_ptr<Item> by_reference, std::shared_ptr<Item> new_value);
        std::shared_ptr<Item> put(Item by_value, std::shared_ptr<Item> new_value);
    private:
    };
};

#endif //ILLATE_ICONTAINER_H
