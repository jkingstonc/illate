//
// Created by james on 04/01/2020.
//

#ifndef ILLATE_IBYTE_H
#define ILLATE_IBYTE_H

#include "inum.h"

namespace items {
    class Ibyte : public Inum{
        bool equal(std::shared_ptr<Item> rhs){return false;}
        std::string to_string_native(){return std::string("Byte");}
        const uint8_t val;
    };
};

#endif //ILLATE_IBYTE_H