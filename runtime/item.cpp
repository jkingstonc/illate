//
// Created by james on 29/12/2019.
//

#include "item.h"

std::string items::Item::item_type_str[] = {
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

std::shared_ptr<items::Item> items::Item::call() {
    return nullptr;
}