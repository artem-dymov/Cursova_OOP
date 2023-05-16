#include <iostream>
#include "ServiceCenterTask.h"

ServiceCenterTask::ServiceCenterTask(std::string task_description, std::string model_manufacturer, int priority)
	: task_description(task_description), model_manufacturer(model_manufacturer), priority(priority) {}

ServiceCenterTask::~ServiceCenterTask()
{}

void ServiceCenterTask::display() const 
{
	std::cout << "Task Description: " << task_description << std::endl;
	std::cout << "Model Manufacturer: " << model_manufacturer << std::endl;
	std::cout << "Priority: " << priority << std::endl;
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

void ServiceCenterTask::set_model_manufacturer(std::string model_manufacturer) {
	this->model_manufacturer = model_manufacturer;
}

int ServiceCenterTask::get_priority() const
{
	return priority;
}

void ServiceCenterTask::set_priority(int priority)
{
	this->priority = priority;
}

std::ostream& operator<<(std::ostream& os, const ServiceCenterTask& task)
{
	os << "Task description: " << task.get_task_description() << std::endl;
	os << "Model manufacturer: " << task.get_model_manufacturer() << std::endl;
	os << "Priority: " << task.get_priority() << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, ServiceCenterTask& task)
{
	std::string task_description, model_manufacturer;
	int priority;
	std::cout << "Input task description: ";
	getline(is, task_description);
	std::cout << "Input model manufacturer: ";
	getline(is, model_manufacturer);
	std::cout << "Input priority: ";
	is >> priority;
	task.set_task_description(task_description);
	task.set_model_manufacturer(model_manufacturer);
	task.set_priority(priority);
	return is;
}