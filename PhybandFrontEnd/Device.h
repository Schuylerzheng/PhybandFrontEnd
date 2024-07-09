#pragma once

#include <string>
#include <vector>
#include "DeviceStats.h"

struct Device
{
	std::string name;
	std::string model;
	std::string ID;
};

int Connect(std::string deviceName, std::string deviceID);
int Disconnect(std::string deviceName, std::string deviceID);
std::vector<DeviceStats> GetInfo(std::string deviceName, std::string deviceID);