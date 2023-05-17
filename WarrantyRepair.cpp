#include "WarrantyRepair.h"
#include <iostream>

WarrantyRepair::WarrantyRepair(std::string task_description, std::string model_manufacturer, int priority, int warranty_period)
    : ServiceCenterTask(task_description, model_manufacturer, priority), warranty_period(warranty_period) {}

WarrantyRepair::~WarrantyRepair() {
    std::cout << "Destroying WarrantyRepair object" << std::endl;
}

void WarrantyRepair::display() const {
    ServiceCenterTask::display();
    std::cout << "Warranty Period: " << warranty_period << std::endl;
}

int WarrantyRepair::get_warranty_period() const 
{ 
    return warranty_period; 
}

void WarrantyRepair::set_warranty_period(int warranty_period) 
{ 
    this->warranty_period = warranty_period; 
}

std::ostream& operator<<(std::ostream& os, WarrantyRepair& task)
{
	os << "Task description: " << task.get_task_description() << std::endl;
	os << "Model manufacturer: " << task.get_model_manufacturer() << std::endl;
	os << "Priority: " << task.get_priority() << std::endl;
	os << "Warranty period: " << task.get_warranty_period() << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, WarrantyRepair& task)
{
	std::string task_description, model_manufacturer;
	int priority, warranty_period;

	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Input task description: ";
	getline(is, task_description);

	std::cout << "Input model manufacturer: ";
	getline(is, model_manufacturer);

	std::cout << "Input priority: ";
	is >> priority;
	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Input warranty_period: ";
	is >> (is, warranty_period);

	task.set_task_description(task_description);
	task.set_model_manufacturer(model_manufacturer);
	task.set_priority(priority);
	task.set_warranty_period(warranty_period);

	return is;
}