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
        std::string to_string_native();

        static std::shared_ptr<Item> to_inill(std::string){
            return std::shared_ptr<Inill>();
        }
    private:
    };
};

#endif //ILLATE_NILL_H
