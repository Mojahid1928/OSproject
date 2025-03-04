#include <iostream>
#include <string>
#include "core.hpp"
#include "cli.hpp"
#include "utils.hpp"

using namespace EmulatorCore;
using namespace EmulatorCLI;
using namespace EmulatorUtils;

void displayHelp(const std::vector<std::string>& args) {
    std::cout << "Available commands:" << std::endl;
    std::cout << "  register <device> - Register a new device (keyboard, mouse, ...)" << std::endl;
    std::cout << "  unregister <device> - Unregister an existing device" << std::endl;
    std::cout << "  status - Show the status of all registered devices" << std::endl;
    std::cout << "  help - Display this help message" << std::endl;
    std::cout << "  exit - Exit the emulator" << std::endl;
}

void registerDeviceCommand(Core& core, const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cerr << "Usage: register <device>" << std::endl;
        return;
    }

    std::string deviceName = toLower(args[1]);
    if (deviceName == "keyboard") {
        core.registerDevice(DeviceType::Keyboard);
    } else if (deviceName == "mouse") {
        core.registerDevice(DeviceType::Mouse);
    } else {
        std::cerr << "Unknown device: " << args[1] << std::endl;
    }
}

void unregisterDeviceCommand(Core& core, const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cerr << "Usage: unregister <device>" << std::endl;
        return;
    }

    std::string deviceName = toLower(args[1]);
    if (deviceName == "keyboard") {
        core.unregisterDevice(DeviceType::Keyboard);
    } else if (deviceName == "mouse") {
        core.unregisterDevice(DeviceType::Mouse);
    } else {
        std::cerr << "Unknown device: " << args[1] << std::endl;
    }
}

void statusCommand(Core& core, const std::vector<std::string>& args) {
    auto statuses = core.getAllStatuses();
    for (const auto& status : statuses) {
        std::cout << status << std::endl;
        

int main()
{
    Core core;
    CLI cli;

    cli.addCommand({"help", "Display help information", displayHelp});
    cli.addCommand({"register", "Register a new device", [&](const vector<string> &args)
                    { registerDeviceCommand(core, args); }});
    cli.addCommand({"unregister", "Unregister an existing device", [&](const vector<string> &args)
                    { unregisterDeviceCommand(core, args); }});
    cli.addCommand({"status", "Show the status of all registered devices", [&](const vector<string> &args)
                    { statusCommand(core, args); }});

    string input;
    cout << "Device Driver Emulator CLI. Type 'help' for a list of commands." << endl;

    while (true)
    {
        cout << "> ";
        getline(cin, input);

        if (toLower(input) == "exit")
        {
            break;
        }

        cli.executeCommand(input);
    }

    return 0;
}
