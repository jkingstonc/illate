//
// Created by james on 04/01/2020.
//

//
// Created by james on 04/01/2020.
//

#include "runtime.h"

Runtime::Runtime() {
    this->trace_back_log = std::make_shared<TraceBackLog>();
    this->gc = nullptr;
    // We don't bind any scoped locals as there are none above us, the scope above is the global scope
    this->entry_point = std::make_shared<items::Core>();
    this->currently_executing = entry_point;
    this->bind_to_core(std::make_shared<items::Core>());
}

void Runtime::bind_to_core(std::shared_ptr<items::Core> core){
    core->bind_trace_back_log(this->trace_back_log);
    core->bind_enviroment(this->enviroment);
}

std::shared_ptr<items::Core> Runtime::get_entry_point(){
    return this->entry_point;
}

std::shared_ptr<items::Core> Runtime::get_currently_executing(){
    return this->currently_executing;
}

void Runtime::bind_enviroment(std::shared_ptr<items::Icontainer> enviroment){
    this->enviroment = enviroment;
}
