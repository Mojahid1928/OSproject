#include "core.hpp"
#include <iostream>
#include <stdexcept>

CoreSystem::CoreSystem()
{
    std::cout << "Core System Initialized." << std::endl;
}

CoreSystem::~CoreSystem()
{
    std::cout << "Core System Shutdown." << std::endl;
}

bool CoreSystem::initializeDevice(const std::string &deviceId)
{
    if (isValidDevice(deviceId))
    {
        std::cout << "Device " << deviceId << " is already initialized." << std::endl;
        return false;
    }

    // Create and initialize a new device
    Device newDevice;
    newDevice.id = deviceId;
    newDevice.status = DeviceStatus::INITIALIZED;
    newDevice.data = {};

    devices[deviceId] = newDevice;
    log("Device " + deviceId + " initialized.");
    return true;
}

std::string CoreSystem::readDevice(const std::string &deviceId, int size)
{
    if (!isValidDevice(deviceId))
    {
        throw std::runtime_error("Device " + deviceId + " not found.");
    }

    Device &device = devices[deviceId];
    if (device.status != DeviceStatus::INITIALIZED)
    {
        throw std::runtime_error("Device " + deviceId + " is not initialized.");
    }

    if (size <= 0 || size > device.data.size())
    {
        throw std::runtime_error("Invalid read size for device " + deviceId);
    }

    // Simulate reading data
    std::string result(device.data.begin(), device.data.begin() + size);
    log("Read " + std::to_string(size) + " bytes from device " + deviceId);
    return result;
}

bool CoreSystem::writeDevice(const std::string &deviceId, const std::string &data)
{
    if (!isValidDevice(deviceId))
    {
        throw std::runtime_error("Device " + deviceId + " not found.");
    }

    Device &device = devices[deviceId];
    if (device.status != DeviceStatus::INITIALIZED)
    {
        throw std::runtime_error("Device " + deviceId + " is not initialized.");
    }

    // Simulate writing data
    device.data.insert(device.data.end(), data.begin(), data.end());
    log("Wrote " + std::to_string(data.size()) + " bytes to device " + deviceId);
    return true;
}

DeviceStatus CoreSystem::getDeviceStatus(const std::string &deviceId)
{
    if (!isValidDevice(deviceId))
    {
        throw std::runtime_error("Device " + deviceId + " not found.");
    }
    return devices[deviceId].status;
}

bool CoreSystem::closeDevice(const std::string &deviceId)
{
    if (!isValidDevice(deviceId))
    {
        std::cout << "Device " << deviceId << " not found." << std::endl;
        return false;
    }

    Device &device = devices[deviceId];
    if (device.status == DeviceStatus::CLOSED)
    {
        std::cout << "Device " << deviceId << " is already closed." << std::endl;
        return false;
    }

    // Close the device
    device.status = DeviceStatus::CLOSED;
    log("Device " + deviceId + " closed.");
    return true;
}

bool CoreSystem::isValidDevice(const std::string &deviceId) const
{
    return devices.find(deviceId) != devices.end();
}

void CoreSystem::log(const std::string &message) const
{
    std::cout << "[CoreSystem] " << message << std::endl;
}