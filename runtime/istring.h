//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_ISTRING_H
#define ILLATE_ISTRING_H

#include "item.h"

class Istring : public Item{
public:
    Istring(std::string val);
    ItemType type();
    std::string to_string_native();

    static Istring to_item(std::string val){
        return Istring(val);
    }
private:
    const std::string val;
};

#endif //ILLATE_ISTRING_H
