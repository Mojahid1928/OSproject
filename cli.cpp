#include "cli.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

CLI::CLI() : isRunning(true)
{
    std::cout << "Device Driver Emulator CLI Initialized. Type 'help' for commands." << std::endl;
}

CLI::~CLI()
{
    std::cout << "CLI Shutdown." << std::endl;
}

void CLI::start()
{
    std::string input;
    while (isRunning)
    {
        std::cout << ">> ";
        std::getline(std::cin, input);
        parseCommand(input);
    }
}

void CLI::displayHelp() const
{
    std::cout << "Available Commands:\n"
              << "  init <device_id> - Initialize a device.\n"
              << "  read <device_id> <size> - Read data from a device.\n"
              << "  write <device_id> <data> - Write data to a device.\n"
              << "  status <device_id> - Check the status of a device.\n"
              << "  close <device_id> - Close a device.\n"
              << "  help - Display this help message.\n"
              << "  exit - Exit the emulator.\n";
}

void CLI::parseCommand(const std::string &input)
{
    std::istringstream iss(input);
    std::vector<std::string> tokens;
    std::string token;

    // Split input into tokens
    while (iss >> token)
    {
        tokens.push_back(token);
    }

    if (tokens.empty())
    {
        return; // No command entered
    }

    // Convert the first token (command) to lowercase
    std::transform(tokens[0].begin(), tokens[0].end(), tokens[0].begin(), ::tolower);

    // Handle exit command
    if (tokens[0] == "exit")
    {
        isRunning = false;
        std::cout << "Exiting Device Driver Emulator..." << std::endl;
        return;
    }

    // Execute the command
    executeCommand(tokens);
}

void CLI::executeCommand(const std::vector<std::string> &tokens)
{
    const std::string &command = tokens[0];

    if (command == "help")
    {
        displayHelp();
    }
    else if (command == "init")
    {
        handleInit(tokens);
    }
    else if (command == "read")
    {
        handleRead(tokens);
    }
    else if (command == "write")
    {
        handleWrite(tokens);
    }
    else if (command == "status")
    {
        handleStatus(tokens);
    }
    else if (command == "close")
    {
        handleClose(tokens);
    }
    else
    {
        std::cout << "Unknown command. Type 'help' for a list of commands." << std::endl;
    }
}

void CLI::handleInit(const std::vector<std::string> &tokens)
{
    if (tokens.size() < 2)
    {
        std::cout << "Usage: init <device_id>" << std::endl;
        return;
    }
    std::string deviceId = tokens[1];
    std::cout << "Initializing device: " << deviceId << std::endl;
    // Call core system to initialize the device
}

void CLI::handleRead(const std::vector<std::string> &tokens)
{
    if (tokens.size() < 3)
    {
        std::cout << "Usage: read <device_id> <size>" << std::endl;
        return;
    }
    std::string deviceId = tokens[1];
    int size = std::stoi(tokens[2]);
    std::cout << "Reading " << size << " bytes from device: " << deviceId << std::endl;
    // Call core system to read from the device
}

void CLI::handleWrite(const std::vector<std::string> &tokens)
{
    if (tokens.size() < 3)
    {
        std::cout << "Usage: write <device_id> <data>" << std::endl;
        return;
    }
    std::string deviceId = tokens[1];
    std::string data = tokens[2];
    std::cout << "Writing data '" << data << "' to device: " << deviceId << std::endl;
    // Call core system to write to the device
}

void CLI::handleStatus(const std::vector<std::string> &tokens)
{
    if (tokens.size() < 2)
    {
        std::cout << "Usage: status <device_id>" << std::endl;
        return;
    }
    std::string deviceId = tokens[1];
    std::cout << "Checking status of device: " << deviceId << std::endl;
    // Call core system to get device status
}

void CLI::handleClose(const std::vector<std::string> &tokens)
{
    if (tokens.size() < 2)
    {
        std::cout << "Usage: close <device_id>" << std::endl;
        return;
    }
    std::string deviceId = tokens[1];
    std::cout << "Closing device: " << deviceId << std::endl;
    // Call core system to close the device
}