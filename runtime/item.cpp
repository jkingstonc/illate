//
// Created by james on 29/12/2019.
//

#include "item.h"

std::string Item::to_string_native(){
    return "Item -> no type";
}

void Item::call(){

}
// Here arg1 can be a single item or an item chain
void Item::call(std::shared_ptr<Item> arg1){

}
void Item::call(std::shared_ptr<Item> arg1, std::shared_ptr<Item> arg2){

}
void Item::call(std::shared_ptr<Item> arg1, std::shared_ptr<Item> arg2, std::shared_ptr<Item> arg3){

}

std::string Item::item_type_str[] = {
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