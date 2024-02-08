#ifndef JOIN_HPP
#define JOIN_HPP

#include <vector>
#include <string>
#include <sstream>
#include <iterator>

inline std::string join(std::vector<std::string> strings, const char* delim) {
    std::ostringstream imploded;
    std::copy(strings.begin(), strings.end(), std::ostream_iterator<std::string>(imploded, delim));
    return imploded.str();
}

#endif
