#include "ServiceCenterTask.h"
#include <iostream>

ServiceCenterTask::ServiceCenterTask(std::string task_description, std::string model_manufacturer)
    : task_description(task_description), model_manufacturer(model_manufacturer) {}

ServiceCenterTask::~ServiceCenterTask() {
    std::cout << "Destroying ServiceCenterTask object" << std::endl;
}

void ServiceCenterTask::display() const {
    std::cout << "Task Description: " << task_description << std::endl;
    std::cout << "Model Manufacturer: " << model_manufacturer << std::endl;
}

std::string ServiceCenterTask::get_task_description() const 
{ 
    return task_description;
}
void ServiceCenterTask::set_task_description(std::string task_description) 
{ 
    this->task_description = task_description; 
}

std::string ServiceCenterTask::get_model_manufacturer() const 
{ 
    return model_manufacturer; 
}

void ServiceCenterTask::set_model_manufacturer(std::string model_manufacturer) 
{ 
    this->model_manufacturer = model_manufacturer; 
}
