//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_ITEM_H
#define ILLATE_ITEM_H

#include <string>

enum ItemType{
    NIL,

    BOOLEAN,
    NUMBER,
    STRING,

    CONTAINER,

    FUNCTION,
    CLASS,
    OBJECT,

    CORE,
};

std::string item_type_str[] = {
        "nill",
        "boolean",
        "number",
        "string",
        "container",
        "function",
        "class",
        "object",
        "core"
};

class Item{
public:
    ItemType type();
    std::string to_string_native();
private:
};


#endif //ILLATE_ITEM_H
