//
// Created by james on 04/01/2020.
//

//
// Created by james on 04/01/2020.
//

#include "runtime.h"

Runtime::Runtime() {
    this->gc = nullptr;
    this->entry_point = std::make_shared<items::Core>(this);
    this->currently_executing = entry_point;
}