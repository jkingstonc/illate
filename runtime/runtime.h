//
// Created by james on 04/01/2020.
//

#ifndef ILLATE_RUNTIME_H
#define ILLATE_RUNTIME_H

#include <memory>
#include "gc.h"
#include "item.h"
#include "ibyte.h"

// A runtime encapsulates everything needed to embedd Illate into an application

class Runtime {
public:
    items::Ibyte status;

    Runtime();
private:
    std::shared_ptr<GarbageCollector> gc;
    // The entry point should be a Core item that is first initialised on startup
    std::shared_ptr<items::Item> entry_point;
};


#endif //ILLATE_RUNTIME_H
