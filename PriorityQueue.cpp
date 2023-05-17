#include <iostream>
#include <stdexcept>
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() : capacity(10), size(0) {
    tasks = new ServiceCenterTask * [capacity];
}

PriorityQueue::~PriorityQueue() {
    for (int i = 0; i < size; i++) {
        delete tasks[i];
    }
    delete[] tasks;
}

void PriorityQueue::push(ServiceCenterTask* task) {
    if (size == capacity) {
        resize();
    }
    tasks[size] = task;
    size++;
}

ServiceCenterTask* PriorityQueue::top() const {
    if (size == 0) {
        throw std::runtime_error("PriorityQueue is empty");
    }
    return tasks[0];
}

void PriorityQueue::pop() {
    try
    {
        if (size == 0) {
            throw (size);
        }

        delete tasks[0];
        size--;
        tasks[0] = tasks[size];
    }
    catch (int size)
    {
        std::cout << "Container is empty." << std::endl;
    }
}


bool PriorityQueue::empty() const {
    return size == 0;
}

void PriorityQueue::resize() {
    capacity *= 2;
    ServiceCenterTask** newTasks = new ServiceCenterTask * [capacity];
    for (int i = 0; i < size; i++) {
        newTasks[i] = tasks[i];
    }
    delete[] tasks;
    tasks = newTasks;
}

void PriorityQueue::sort() {
    for (int i = 1; i < size; ++i) {
        ServiceCenterTask* key = tasks[i];
        int j = i - 1;
        while (j >= 0 && tasks[j]->get_priority() > key->get_priority()) {
            tasks[j + 1] = tasks[j];
            --j;
        }
        tasks[j + 1] = key;
    }
}
// Метод серіалізації об'єктів та збереження даних об'єктів у файл
void PriorityQueue::serialize(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing");
    }

    file << size << '\n';

    for (int i = 0; i < size; ++i) {
        ServiceCenterTask* task = tasks[i];
        WarrantyRepair* warranty_repair = dynamic_cast<WarrantyRepair*>(task);
        ScheduledMaintenance* scheduled_maintenance = dynamic_cast<ScheduledMaintenance*>(task);

        if (warranty_repair != nullptr) {
            file << "WarrantyRepair\n";
            file << warranty_repair->get_task_description() << '\n';
            file << warranty_repair->get_model_manufacturer() << '\n';
            file << warranty_repair->get_priority() << '\n';
            file << warranty_repair->get_warranty_period() << '\n';
        }
        else if (scheduled_maintenance != nullptr) {
            file << "ScheduledMaintenance\n";
            file << scheduled_maintenance->get_task_description() << '\n';
            file << scheduled_maintenance->get_model_manufacturer() << '\n';
            file << scheduled_maintenance->get_priority() << '\n';
            file << scheduled_maintenance->get_maintenance_type() << '\n';
        }
        else {
            throw std::runtime_error("Unknown task type");
        }
    }

    file.close();
}

// Метод десеріалізації об'єктів та зчитування даних об'єктів з файлу
void PriorityQueue::deserialize(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for reading");
    }

    while (!empty()) {
        pop();
    }

    int new_size;
    file >> new_size;

    for (int i = 0; i < new_size; ++i) {
        std::string task_type;
        std::string task_description;
        std::string model_manufacturer;
        int priority;

        file >> task_type;
        getline(file, task_description);
        getline(file, task_description);
        getline(file, model_manufacturer);
        file >> priority;

        if (task_type == "WarrantyRepair") {
            int warranty_period;
            file >> warranty_period;

            WarrantyRepair* warranty_repair = new WarrantyRepair(task_description, model_manufacturer, priority, warranty_period);
            push(warranty_repair);
        }
        else if (task_type == "ScheduledMaintenance") {
            std::string maintenance_type;
            getline(file, maintenance_type);
            getline(file, maintenance_type);

            ScheduledMaintenance* scheduled_maintenance = new ScheduledMaintenance(task_description, model_manufacturer, priority, maintenance_type);
            push(scheduled_maintenance);
        }
        else {
            throw std::runtime_error("Unknown task type");
        }
    }

    file.close();
}

void PriorityQueue::clear() {
    while (!empty()) {
        pop();
    }
}

int PriorityQueue::get_size()
{
    return size;
}


void PriorityQueue::print_tasks() {
    for (int i = 0; i < size; i++) {
        std::cout << "\n" << typeid(*tasks[i]).name() << std::endl;
        std::cout << *tasks[i] << std::endl;
    }
}

void PriorityQueue::display() const {
    for (int i = 0; i < size; i++) {
        tasks[i]->display();
        std::cout << std::endl;
    }
}

int PriorityQueue::countWarrantyRepairsByManufacturer(const std::string& manufacturer) const {
    int count = 0;

    for (int i = 0; i < size; i++) {
        WarrantyRepair* wr = dynamic_cast<WarrantyRepair*>(tasks[i]);
        if (wr != nullptr && wr->get_model_manufacturer() == manufacturer) {
            count++;
        }
    }

    return count;
}