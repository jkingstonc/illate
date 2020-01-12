//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_IBOOL_H
#define ILLATE_IBOOL_H

#include "item.h"

namespace items{
    class Ibool : public items::Item{
    public:
        Ibool(bool val);
        items::ItemType type();
        std::string to_string_native();

        static std::shared_ptr<Ibool> to_item(bool val){
            return std::make_shared<Ibool>(val);
        }
        const bool val;
    };
};

#endif //ILLATE_IBOOL_H
