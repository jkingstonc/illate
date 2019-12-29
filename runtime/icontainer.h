//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_ICONTAINER_H
#define ILLATE_ICONTAINER_H

#include "item.h"
#include "istring.h"

class Icontainer : public Item{
public:
    Icontainer();
    ItemType type();
    std::string to_string_native();
private:
};

#endif //ILLATE_ICONTAINER_H
