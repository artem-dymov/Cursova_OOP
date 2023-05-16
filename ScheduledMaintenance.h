#pragma once
#include "ServiceCenterTask.h"
#include <string>

class ScheduledMaintenance : public ServiceCenterTask {
public:
    ScheduledMaintenance(std::string task_description, std::string model_manufacturer, int priority, std::string maintenance_type);
    ~ScheduledMaintenance();

    void display() const override;

    std::string get_maintenance_type() const;
    void set_maintenance_type(std::string maintenance_type);

private:
    std::string maintenance_type;
};

std::istream& operator>>(std::istream& is, ScheduledMaintenance& task);
std::ostream& operator<<(std::ostream& is, ScheduledMaintenance& task);