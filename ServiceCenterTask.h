#pragma once
#include <string>
#include <iostream>


class ServiceCenterTask {
public:
    ServiceCenterTask(std::string task_description, std::string model_manufacturer, int priority);
    virtual ~ServiceCenterTask();
    virtual void display() const;
    std::string get_task_description() const;
    void set_task_description(std::string task_description);
    std::string get_model_manufacturer() const;
    void set_model_manufacturer(std::string model_manufacturer);
    int get_priority() const;
    void set_priority(int priority);

protected:
    std::string task_description;
    std::string model_manufacturer;
    int priority;
};

// Оголошення оператора << як незалежної функції
std::ostream& operator<<(std::ostream& os, const ServiceCenterTask& task);
// Оголошення оператора >> як незалежної функції
std::istream& operator>>(std::istream& is, ServiceCenterTask& task);
