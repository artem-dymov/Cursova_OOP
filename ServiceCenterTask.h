#pragma once
#include <string>

class ServiceCenterTask {
public:
    ServiceCenterTask(std::string task_description, std::string model_manufacturer);
    virtual ~ServiceCenterTask();

    virtual void display() const;

    std::string get_task_description() const;
    void set_task_description(std::string task_description);

    std::string get_model_manufacturer() const;
    void set_model_manufacturer(std::string model_manufacturer);

protected:
    std::string task_description;
    std::string model_manufacturer;
};
