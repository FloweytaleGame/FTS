#ifndef JOIN_HPP
#define JOIN_HPP

#include <vector>
#include <string>
#include <sstream>
#include <iterator>

/**
 * @brief Concatenates a vector of strings into one string, all seperated by the delimiter.
 * 
 * @param strings The vector of strings that will be joined.
 * @param delim A char pointer (string) that will seperate the strings when being joined.
 * @return A string with all the strings joined in one string seperated by the delimiter.
 */
inline std::string join(std::vector<std::string> strings, const char* delim) {
    std::ostringstream imploded;
    std::copy(strings.begin(), strings.end(), std::ostream_iterator<std::string>(imploded, delim));
    return imploded.str();
}

#endif
