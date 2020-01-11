//
// Created by james on 04/01/2020.
//

#ifndef ILLATE_RUNTIME_H
#define ILLATE_RUNTIME_H

#include <memory>
#include "gc.h"
#include "item.h"
#include "ibyte.h"
#include "core.h"

// A runtime encapsulates everything needed to embed Illate into an application

class Runtime {
public:

    Runtime();

    void bind_to_core(std::shared_ptr<items::Core> core);

    std::shared_ptr<items::Core> get_entry_point();
    std::shared_ptr<items::Core> get_currently_executing();

    void bind_enviroment(std::shared_ptr<items::Icontainer> enviroment);

private:

    std::shared_ptr<TraceBackLog> trace_back_log;

    std::shared_ptr<GarbageCollector> gc;
    /**
     * The entry point is the first core that is used for the runtime.
     * When we load the first (if only) script, we will push the Core object onto this entry point's stack.
     * */
    std::shared_ptr<items::Core> entry_point;
    /**
     * We keep a reference to the Core that we are currently executing so we can reference it's data from the native interface
     * */
    std::shared_ptr<items::Core> currently_executing;

    std::shared_ptr<items::Icontainer> enviroment;
};


#endif //ILLATE_RUNTIME_H
