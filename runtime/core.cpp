//
// Created by james on 29/12/2019.
//

#include "core.h"


items::Core::Core(){
}

items::Core::Core(std::shared_ptr<Script> script){
    this->script = script;
}

items::ItemType type(){
    return items::ItemType::CORE;
}

std::string items::Core::to_string_native(){
    return std::string("Core");
}

/**
 * Every Item is callable, it can be called with any amount of arguments
 * */
std::shared_ptr<items::Item> items::Core::call(){
    this->run_fde();
    return nullptr;
}
// Here arg1 can be a single item or an item chain
std::shared_ptr<items::Item> items::Core::call(std::shared_ptr<items::Item> arg1){return nullptr;};
std::shared_ptr<items::Item> items::Core::call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2){return nullptr;};
std::shared_ptr<items::Item> items::Core::call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2, std::shared_ptr<items::Item> arg3){return nullptr;};


void items::Core::bind_trace_back_log(std::shared_ptr<TraceBackLog> trace_back_log){
    this->trace_back_log = trace_back_log;
}
void items::Core::bind_enviroment(std::shared_ptr<items::Icontainer> enviroment){
    this->enviroment = enviroment;
}
void items::Core::bind_scoped_locals(std::shared_ptr<items::ScopedLocals> upper){
    this->locals = upper;
    // Initialise our own local array to the size of the amount of locals we have
    this->locals->locals = std::make_shared<items::Icontainer>();
}

void items::Core::push(std::shared_ptr<items::Item> item){
    this->exec_stack.push(item);
}

std::shared_ptr<items::Item> items::Core::pop(){
    R_ASSERT(this->exec_stack.size(), "Exec stack is empty!");
    std::shared_ptr<items::Item> top = this->exec_stack.top();
    this->exec_stack.pop();
    return top;
}

std::shared_ptr<items::Item> items::Core::peek(){
    R_ASSERT(this->exec_stack.size(), "Exec stack is empty!");
    return this->exec_stack.top();
}
void items::Core::run_fde() {
    R_ASSERT(this->script->code, "Script contains no code!");
    // If we are in debug mode, we should record the current time for timing
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;
    if(TRACEBACK_MODE()){
        start_time = std::chrono::high_resolution_clock::now();
    }
    bool running = true;
    uint8_t op;
    R_INFO("fde start");
    while(running){
        op = GET_OP();
        std::vector<uint8_t> args;
        NEXT();
        switch(op){
            case Opcodes::DEBUG: R_INFO("CORE DEBUG OP :)"); break;
            case Opcodes::NOP: break;
            case Opcodes::END: running=false; break;
            case Opcodes::PAUSE: {
                // Execute INT 3 asm for kernel to exec a breakpoint
                break;
            }
            case Opcodes::LD_CONST: break;
            case Opcodes::LD_VAR: break;
            case Opcodes::LD_LOC: break;
            case Opcodes::SET_VAR: break;
            case Opcodes::SET_LOC: break;
            case Opcodes::ADD: break;
            case Opcodes::SUB: break;
            case Opcodes::MUL: break;
            case Opcodes::DIV: break;
            case Opcodes::MOD: break;
            case Opcodes::REM: break;
            case Opcodes::POW: break;
            case Opcodes::NEG: break;
            case Opcodes::AND: break;
            case Opcodes::OR: break;
            case Opcodes::NOT: break;
            case Opcodes::GOTO: break;
            case Opcodes::EQ: break;
            case Opcodes::LT: break;
            case Opcodes::GT: break;
            case Opcodes::CALL: {
                std::shared_ptr<items::Item> next_entry = this->peek();
                break;
            }
            case Opcodes::RETURN: break;
            case Opcodes::CHAIN_VALS: break;
            case Opcodes::MAKE: break;
            case Opcodes::INSTANCE: break;
            case Opcodes::INSTANCE_CONTAINER: break;
            default: break;
        }
    }
    if(TRACEBACK_MODE()){
        end_time = std::chrono::high_resolution_clock::now();
        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time-start_time);
        // Push the traceback to the runtime's log
        this->trace_back_log->log.push_back(duration);
        std::cout << duration.count()/1000000 << std::endl;
    }
    R_INFO("ending fde...");
}