//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_ISTRING_H
#define ILLATE_ISTRING_H

#include "item.h"

class Istring : public Item{
public:
    Istring(std::string str) : str(str){
    }

    ItemType type(){ return STRING; }

    using Item::to_string_native;
    std::string to_string_native(){
        return this->str;
    }

private:
    const std::string str;
};

Istring to_item(std::string str){
    return Istring(str);
}

#endif //ILLATE_ISTRING_H
