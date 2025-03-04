#include "utils.hpp"
#include <iostream>
#include <stdexcept>

namespace Utils
{

    void log(const std::string &message, const std::string &level)
    {
        std::string timestamp = getCurrentTimestamp();
        std::cout << "[" << timestamp << "] [" << level << "] " << message << std::endl;
    }

    std::string getCurrentTimestamp()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
        return ss.str();
    }

    void handleError(const std::string &errorMessage, bool exitProgram)
    {
        log(errorMessage, "ERROR");
        if (exitProgram)
        {
            throw std::runtime_error(errorMessage);
        }
    }

    std::string toLower(const std::string &str)
    {
        std::string lowerStr = str;
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }

} // namespace Utils