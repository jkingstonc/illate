//
// Created by james on 29/12/2019.
//

#include "item.h"

std::string Items::Item::to_string_native(){
    return "Item -> no type";
}

void Items::Item::call(){

}
// Here arg1 can be a single item or an item chain
void Items::Item::call(std::shared_ptr<Items::Item> arg1){

}
void Items::Item::call(std::shared_ptr<Items::Item> arg1, std::shared_ptr<Items::Item> arg2){

}
void Items::Item::call(std::shared_ptr<Items::Item> arg1, std::shared_ptr<Items::Item> arg2, std::shared_ptr<Items::Item> arg3){

}

std::string Items::Item::item_type_str[] = {
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