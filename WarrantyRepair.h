#pragma once
#include "ServiceCenterTask.h"
#include <string>

class WarrantyRepair : public ServiceCenterTask {
public:
    WarrantyRepair(std::string task_description, std::string model_manufacturer, int priority, int warranty_period);
    ~WarrantyRepair();

    void display() const override;

    int get_warranty_period() const;
    void set_warranty_period(int warranty_period);

private:
    int warranty_period;
};

std::istream& operator<<(std::istream& os, const WarrantyRepair& task);
std::ostream& operator<<(std::ostream& os, const WarrantyRepair& task);
