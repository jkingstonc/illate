//
// Created by james on 29/12/2019.
//

#include "core.h"

bool items::Core::debug_mode = DEFAULT_DEBUG;

items::Core::Core(){
    this->exec_debug_state = std::make_shared<ExecutionDebugState>();
    this->exec_debug_state->is_debugging = items::Core::debug_mode;
    this->exec_debug_state->paused = false;
}

items::Core::Core(std::shared_ptr<Script> script){
    this->exec_debug_state = std::make_shared<ExecutionDebugState>();
    this->exec_debug_state->is_debugging = items::Core::debug_mode;
    this->exec_debug_state->paused = false;
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
    // First check if we are having to resume the core
    if(IS_DEBUG()){
        if(this->exec_debug_state->paused){
            this->resume_debug_state();
        }
    }
    this->run_fde();
    return nullptr;
}
// Here arg1 can be a single item or an item chain
std::shared_ptr<items::Item> items::Core::call(std::shared_ptr<items::Item> arg1){return nullptr;};
std::shared_ptr<items::Item> items::Core::call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2){return nullptr;};
std::shared_ptr<items::Item> items::Core::call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2, std::shared_ptr<items::Item> arg3){return nullptr;};

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
    std::shared_ptr<items::Item> top = this->exec_stack.top();
    this->exec_stack.pop();
    return top;
}

std::shared_ptr<items::Item> items::Core::peek(){
    return this->exec_stack.top();
}

std::shared_ptr<ExecutionDebugState> items::Core::get_exec_debug_state(){
    return this->exec_debug_state;
}

void items::Core::run_fde() {

    R_ASSERT(this->script->code, "Script contains no code!");

    // If we are in debug mode, we should record the current time for timing
    if(IS_DEBUG()){
        this->exec_debug_state->start_time = std::chrono::high_resolution_clock::now();
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
                if(IS_DEBUG()){
                    // Save the state of the runtime
                    save_debug_state();
                    running=false;
                }
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
            case Opcodes::CALL: break;
            case Opcodes::RETURN: break;
            case Opcodes::CHAIN_VALS: break;
            case Opcodes::MAKE: break;
            case Opcodes::INSTANCE: break;
            case Opcodes::INSTANCE_CONTAINER: break;
            default: break;
        }
    }
    if(IS_DEBUG()){
        this->exec_debug_state->end_time = std::chrono::high_resolution_clock::now();
    }
    R_INFO("ending fde...");
}

void items::Core::save_debug_state(){
    R_INFO("Hit breakpoint, saving state.");
    this->exec_debug_state->paused = true;
    this->exec_debug_state->ip_at_break = this->ip;
}

void items::Core::resume_debug_state(){
    R_INFO("Resuming core state.");
    // Restore the instruction pointer
    this->exec_debug_state->paused = false;
    this->ip = this->exec_debug_state->ip_at_break;
}

std::shared_ptr<items::Item> items::Core::explicit_resume_debug(){
    this->resume_debug_state();
    this->run_fde();
    return nullptr;
}