//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_NILL_H
#define ILLATE_NILL_H

#include "item.h"

namespace items{
    class Inill : public items::Item{
    public:
        Inill();
        items::ItemType type();
        bool equal(std::shared_ptr<Item> rhs);
        std::string to_string_native();
    private:
    };
    static std::shared_ptr<Item> to_inill(){
        return std::make_shared<Inill>();
    }
};

#endif //ILLATE_NILL_H
