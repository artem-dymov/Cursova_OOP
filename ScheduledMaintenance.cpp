#include "ScheduledMaintenance.h"
#include <iostream>

ScheduledMaintenance::ScheduledMaintenance(std::string task_description, std::string model_manufacturer, int priority, std::string maintenance_type)
    : ServiceCenterTask(task_description, model_manufacturer, priority), maintenance_type(maintenance_type) {}

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

std::ostream& operator<<(std::ostream& os, const ScheduledMaintenance& task)
{
	os << "Task description: " << task.get_task_description() << std::endl;
	os << "Model manufacturer: " << task.get_model_manufacturer() << std::endl;
	os << "Priority: " << task.get_priority() << std::endl;
	os << "Maintenance type: " << task.get_maintenance_type() << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, ScheduledMaintenance& task)
{
	std::string task_description, model_manufacturer, maintenance_type;
	int priority;
	std::cout << "Input task description: ";
	getline(is, task_description);

	std::cout << "Input model manufacturer: ";
	getline(is, model_manufacturer);

	std::cout << "Input priority: ";
	is >> priority;

	std::cout << "Input maintenance type: ";
	getline(is, maintenance_type);

	task.set_task_description(task_description);
	task.set_model_manufacturer(model_manufacturer);
	task.set_priority(priority);
	task.set_maintenance_type(maintenance_type);

	return is;
}