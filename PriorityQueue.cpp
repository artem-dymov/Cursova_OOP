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
    int i = size;
    size++;
    while (i > 0 && tasks[parent(i)]->get_priority() > tasks[i]->get_priority()) {
        std::swap(tasks[parent(i)], tasks[i]);
        i = parent(i);
    }
}

ServiceCenterTask* PriorityQueue::top() const {
    if (size == 0) {
        throw std::runtime_error("PriorityQueue is empty");
    }
    return tasks[0];
}

void PriorityQueue::pop() {
    if (size == 0) {
        throw std::runtime_error("PriorityQueue is empty");
    }
    delete tasks[0];
    size--;
    tasks[0] = tasks[size];
    heapify(0);
}

bool PriorityQueue::empty() const {
    return size == 0;
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

void PriorityQueue::resize() {
    capacity *= 2;
    ServiceCenterTask** newTasks = new ServiceCenterTask * [capacity];
    for (int i = 0; i < size; i++) {
        newTasks[i] = tasks[i];
    }
    delete[] tasks;
    tasks = newTasks;
}
