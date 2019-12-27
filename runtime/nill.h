//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_NILL_H
#define ILLATE_NILL_H

#include "item.h"

class Inill : public Item{
public:
    ItemType type(){
        return NIL;
    }
    std::string to_string_native(){
        return std::string("nill");
    }
private:
};

Item to_inill(std::string){
    return Inill();
}

#endif //ILLATE_NILL_H
