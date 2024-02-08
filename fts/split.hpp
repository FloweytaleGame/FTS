#ifndef SPLIT_HPP
#define SPLIT_HPP

#include <string>
#include <vector>

/**
 * @brief Splits a string into an array of string by the delimiter.
 * 
 * @param str Base string that will be seperated.
 * @param delimiter String that will seperate the string into a vector of strings.
 * @return Array of strings that are seperated.
 */
inline std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = 0;
    while ((end = str.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

#endif
