//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_IBOOL_H
#define ILLATE_IBOOL_H

#include "item.h"

class Ibool : public Item{
public:
    Ibool(bool val) : val(val){

    }

    ItemType type(){ return BOOLEAN; }

    std::string to_string_native(){
        return (this->val == true) ? std::string("true") : std::string("false");
    }
private:
    const bool val;
};

Ibool to_item(bool val){
    return Ibool(val);
}

#endif //ILLATE_IBOOL_H
