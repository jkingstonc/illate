//
// Created by james on 29/12/2019.
//

#include "icontainer.h"

items::Icontainer::Icontainer() {
}

items::ItemType items::Icontainer::type(){
    return items::ItemType::CONTAINER;
}
bool items::Icontainer::equal(std::shared_ptr<Item> rhs){
    return false;
}
std::string items::Icontainer::to_string_native(){
    return std::string("Container");
}

items::Iint items::Icontainer::size(){
    return items::Iint(this->values.size());
}

void items::Icontainer::null_grow(int index){
    // If the index is greater than the container size, pad with INil's
    while(index >= this->keys.size()){
        this->keys.push_back(std::make_shared<items::Inill>());
        this->values.push_back(std::make_shared<items::Inill>());
    }
}

std::shared_ptr<items::Item> items::Icontainer::get(int by_index){
    if(by_index < this->values.size()){
        return this->values.at(by_index);
    }
    return items::to_inill();
}
std::shared_ptr<items::Item> items::Icontainer::get(std::shared_ptr<Item> by_reference){
    // Compare the pointer values rather than the raw values
    for(int i = 0; i<this->keys.size(); i++){
        if(this->keys.at(i)->equal(by_reference))
            return this->values.at(i);
    }
    return items::to_inill();
}

void items::Icontainer::raw_set(int index, std::shared_ptr<items::Item> key, std::shared_ptr<items::Item> value){
    this->keys.at(index) = key;
    this->values.at(index) = value;
}
void items::Icontainer::set(int by_index, std::shared_ptr<items::Item> new_value){
    this->null_grow(by_index);
    this->values.at(by_index) = new_value;
}
void items::Icontainer::set(std::shared_ptr<items::Item> by_reference, std::shared_ptr<items::Item> new_value){
    // Compare the pointer values rather than the raw values
    for(int i = 0; i<this->keys.size(); i++){
        if(this->keys.at(i) == by_reference)
            this->values.at(i) = new_value;
    }
}

void items::Icontainer::put(int by_index, std::shared_ptr<items::Item> new_value){
    this->null_grow(by_index);
    this->values.at(by_index) = new_value;
}
void items::Icontainer::put(std::shared_ptr<items::Item> by_reference, std::shared_ptr<items::Item> new_value){
    this->keys.push_back(by_reference);
    this->values.push_back(new_value);
}