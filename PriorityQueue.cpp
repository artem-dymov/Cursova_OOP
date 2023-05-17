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
    for (int i = size - 1; i > 0; i--) {
        if (tasks[i]->get_priority() < tasks[i - 1]->get_priority()) {
            std::swap(tasks[i], tasks[i - 1]);
        }
    }

}

ServiceCenterTask* PriorityQueue::top() const {
    return tasks[0];
}


void PriorityQueue::pop() {
    delete tasks[0];
    for (int i = 0; i < size - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    size--;
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


int PriorityQueue::parent(int i) const {
    return (i - 1) / 2;
}

int PriorityQueue::left(int i) const {
    return 2 * i + 1;
}

int PriorityQueue::right(int i) const {
    return 2 * i + 2;
}

void PriorityQueue::heapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < size && tasks[l]->get_priority() < tasks[smallest]->get_priority()) {
        smallest = l;
    }
    if (r < size && tasks[r]->get_priority() < tasks[smallest]->get_priority()) {
        smallest = r;
    }
    if (smallest != i) {
        std::swap(tasks[i], tasks[smallest]);
        heapify(smallest);
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