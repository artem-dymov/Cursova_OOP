#include "ScheduledMaintenance.h"
#include <iostream>

ScheduledMaintenance::ScheduledMaintenance(std::string task_description, std::string model_manufacturer, std::string maintenance_type)
    : ServiceCenterTask(task_description, model_manufacturer), maintenance_type(maintenance_type) {}

ScheduledMaintenance::~ScheduledMaintenance() {
    std::cout << "Destroying ScheduledMaintenance object" << std::endl;
}

void ScheduledMaintenance::display() const {
    ServiceCenterTask::display();
    std::cout << "Maintenance Type: " << maintenance_type << std::endl;
}

std::string ScheduledMaintenance::get_maintenance_type() const 
{ 
    return maintenance_type; 
}

void ScheduledMaintenance::set_maintenance_type(std::string maintenance_type) 
{
    this->maintenance_type = maintenance_type; 
}