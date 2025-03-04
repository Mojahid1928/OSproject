#ifndef CORE_HPP
#define CORE_HPP

#include <string>
#include <unordered_map>
#include <vector>

// Device status enumeration
enum class DeviceStatus
{
    CLOSED,
    INITIALIZED,
    BUSY,
    ERROR
};

// Device structure
struct Device
{
    std::string id;
    DeviceStatus status;
    std::vector<char> data;
};

// Core system class
class CoreSystem
{
public:
    // Constructor and Destructor
    CoreSystem();
    ~CoreSystem();

    // Device operations
    bool initializeDevice(const std::string &deviceId);
    std::string readDevice(const std::string &deviceId, int size);
    bool writeDevice(const std::string &deviceId, const std::string &data);
    DeviceStatus getDeviceStatus(const std::string &deviceId);
    bool closeDevice(const std::string &deviceId);

private:
    // Helper functions
    bool isValidDevice(const std::string &deviceId) const;
    void log(const std::string &message) const;

    // Internal storage for devices
    std::unordered_map<std::string, Device> devices;
};

#endif // CORE_HPP