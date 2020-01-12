//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_ICONTAINER_H
#define ILLATE_ICONTAINER_H

#include <vector>

#include "item.h"
#include "istring.h"
#include "iint.h"
#include "nill.h"

namespace items{
    class Icontainer : public items::Item{
    public:
        Icontainer();
        ItemType type();
        bool equal(std::shared_ptr<Item> rhs);
        std::string to_string_native();


        Iint size();
        void null_grow(int index);

        std::shared_ptr<Item> get(int by_index);
        std::shared_ptr<Item> get(std::shared_ptr<Item> by_reference);
        std::shared_ptr<Item> get(Item by_value);

        void raw_set(int index, std::shared_ptr<Item> key, std::shared_ptr<Item> value);
        void set(int by_index, std::shared_ptr<Item> new_value);
        void set(std::shared_ptr<Item> by_reference, std::shared_ptr<Item> new_value);

        void append(std::shared_ptr<items::Item> new_value);
        void append(std::shared_ptr<items::Item> by_reference, std::shared_ptr<items::Item> new_value);

        void insert(int by_index, std::shared_ptr<Item> value);
        void insert(int by_index, std::shared_ptr<Item> key, std::shared_ptr<Item> value);

        void remove(int by_index);
        void remove(std::shared_ptr<items::Item> by_reference);
    private:
        std::vector<std::shared_ptr<items::Item>> keys, values;
    };
};

#endif //ILLATE_ICONTAINER_H
