//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_ITEM_H
#define ILLATE_ITEM_H

#include <iostream>
#include <string>

enum ItemType{
    NIL,
    CHAIN,

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
        "chain",
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
    virtual std::string to_string_native(){return nullptr;}

    /**
     * Every Item is callable, it can be called with any amount of arguments
     * */
    virtual void call(){};
    // Here arg1 can be a single item or an item chain
    virtual void call(std::shared_ptr<Item> arg1){};
    virtual void call(std::shared_ptr<Item> arg1, std::shared_ptr<Item> arg2){};
    virtual void call(std::shared_ptr<Item> arg1, std::shared_ptr<Item> arg2, std::shared_ptr<Item> arg3){};


private:
};


#endif //ILLATE_ITEM_H
