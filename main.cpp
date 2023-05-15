#include "PriorityQueue.h"
#include "ServiceCenterTask.h"
#include "ScheduledMaintenance.h"
#include "WarrantyRepair.h"


int main() {
    PriorityQueue pq;

    ServiceCenterTask* task1 = new ServiceCenterTask("Task 1", "Manufacturer 1", 1);
    ScheduledMaintenance* task2 = new ScheduledMaintenance("Task 2", "Manufacturer 2", 2, "Type 1");
    WarrantyRepair* task3 = new WarrantyRepair("Task 3", "Manufacturer 3", 1, 12);

    pq.push(task1);
    pq.push(task2);
    pq.push(task3);

    pq.display();

    return 0;
}
