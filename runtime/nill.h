//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_NILL_H
#define ILLATE_NILL_H

#include "item.h"

class Inill : public Item{
public:
    Inill();
    ItemType type();
    std::string to_string_native();

    static Item to_inill(std::string){
        return Inill();
    }
private:
};

#endif //ILLATE_NILL_H
