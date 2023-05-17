#pragma once
#include <iostream>
#include <fstream>
#include "ServiceCenterTask.h"
#include "WarrantyRepair.h"
#include "ScheduledMaintenance.h"

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

    // Метод серіалізації об'єктів та збереження даних об'єктів у файл
    void serialize(const std::string& filename) const;

    // Метод десеріалізації об'єктів та зчитування даних об'єктів з файлу
    void deserialize(const std::string& filename);

    void clear();

    int get_size();
    void print_tasks();
    void sort();

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


