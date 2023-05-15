#include "ServiceCenterTask.h"
#include "ScheduledMaintenance.h"
#include "WarrantyRepair.h"
#include <iostream>

int main() {
    ServiceCenterTask* task1 = new ScheduledMaintenance("Oil Change", "Toyota", "Regular Maintenance");
    ServiceCenterTask* task2 = new WarrantyRepair("Replace Battery", "Apple", 12);

    std::cout << "Scheduled Maintenance Task:" << std::endl;
    task1->display();

    std::cout << std::endl;

    std::cout << "Warranty Repair Task:" << std::endl;
    task2->display();

    delete task1;
    delete task2;

    return 0;
}
