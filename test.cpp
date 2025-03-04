#include "core.hpp"
#include "utils.hpp"
#include <iostream>

void runTests()
{
    std::cout << "===== Running Tests =====\n";

    // Test Device Driver
    DeviceDriver driver("TestDriver");
    driver.initialize();
    driver.readData();
    driver.writeData();
    driver.shutdown();

    // Test Emulator
    Emulator emulator;
    emulator.loadDriver(driver);
    emulator.execute();
    emulator.unloadDriver();

    // Test Memory Manager
    MemoryManager memoryManager;
    memoryManager.allocateMemory(256);
    memoryManager.freeMemory();

    // Test Process Scheduler
    ProcessScheduler scheduler;
    scheduler.scheduleProcess("Process1");
    scheduler.scheduleProcess("Process2");
    scheduler.runScheduler();

    // Test Logging
    Utils::logMessage("Testing log system.");

    std::cout << "===== Tests Completed =====\n";
}

int main()
{
    runTests();
    return 0;
}
