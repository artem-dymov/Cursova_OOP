#include "PriorityQueue.h"
#include "ServiceCenterTask.h"
#include "ScheduledMaintenance.h"
#include "WarrantyRepair.h"


void menu(PriorityQueue& queue) {
    std::string file_name = "queue.txt";
    int choice = -1;
    while (choice != 0) {
        std::cout << "Menu:\n";
        std::cout << "1. Create ScheduledMaintenance object\n";
        std::cout << "2. Create WarrantyRepair object\n";
        std::cout << "3. View contents of container\n";
        std::cout << "4. Sort objects\n";
        std::cout << "5. Delete first object.\n";
        std::cout << "6. Clear all container\n";
        std::cout << "7. Load objects from file\n";
        std::cout << "8. Save objects to file\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            system("cls");
            ScheduledMaintenance* new_scheduled_maintenance = new ScheduledMaintenance("", "", 0, "");
            std::cout << "Enter ScheduledMaintenance object data:\n";
            std::cin >> *new_scheduled_maintenance;
            queue.push(new_scheduled_maintenance);
            break;
        }
        case 2: {
            system("cls");
            WarrantyRepair* new_warranty_repair = new WarrantyRepair("", "", 0, 0);
            std::cout << "Enter WarrantyRepair object data:\n";
            std::cin >> *new_warranty_repair;
            queue.push(new_warranty_repair);
            break;
        }
        case 3: {
            system("cls");
            std::cout << "Contents of container:\n";
            queue.display();
            break;
        }
        case 4: {
            system("cls");
            // queue.sort();
            std::cout << "Objects sorted.\n";
            break;
        }
        case 5: {
            system("cls");
            queue.pop();
            break;
        }
        case 6: {
            system("cls");
            queue.clear();
            break;
        }
        case 7: {
            system("cls");
            queue.deserialize(file_name);
            break;
        }
        case 8: {
            system("cls");
            queue.serialize(file_name);
            break;
        }
        case 0: {
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        system("pause");
    }
}


int main() {
    PriorityQueue* queue = new PriorityQueue();
    menu(*queue);
    delete queue;
    return 0;
}

