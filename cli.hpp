#ifndef CLI_HPP
#define CLI_HPP

#include <string>
#include <vector>

class CLI
{
public:
    // Constructor and Destructor
    CLI();
    ~CLI();

    // Main loop to handle user input
    void start();

private:
    // Helper functions
    void displayHelp() const;
    void parseCommand(const std::string &input);
    void executeCommand(const std::vector<std::string> &tokens);

    // Command handlers
    void handleInit(const std::vector<std::string> &tokens);
    void handleRead(const std::vector<std::string> &tokens);
    void handleWrite(const std::vector<std::string> &tokens);
    void handleStatus(const std::vector<std::string> &tokens);
    void handleClose(const std::vector<std::string> &tokens);

    // Internal state
    bool isRunning;
};

#endif // CLI_HPP