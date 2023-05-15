#include "WarrantyRepair.h"
#include <iostream>

WarrantyRepair::WarrantyRepair(std::string task_description, std::string model_manufacturer, int warranty_period)
    : ServiceCenterTask(task_description, model_manufacturer), warranty_period(warranty_period) {}

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