#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

namespace Utils
{

    // Logging utility
    void log(const std::string &message, const std::string &level = "INFO");

    // Timestamp utility
    std::string getCurrentTimestamp();

    // Error handling utility
    void handleError(const std::string &errorMessage, bool exitProgram = false);

    // String utility
    std::string toLower(const std::string &str);

} // namespace Utils

#endif // UTILS_HPP