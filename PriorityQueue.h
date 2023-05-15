#pragma once
#include "ServiceCenterTask.h"
#include "WarrantyRepair.h"

class PriorityQueue {
public:
    PriorityQueue();
    ~PriorityQueue();

    void push(ServiceCenterTask* task);
    ServiceCenterTask* top() const;
    void pop();
    bool empty() const;
    void display() const;
    int countWarrantyRepairsByManufacturer(const std::string& manufacturer) const;

private:
    ServiceCenterTask** tasks;
    int capacity;
    int size;

    int parent(int i) const;
    int left(int i) const;
    int right(int i) const;
    void heapify(int i);
    void resize();
};





