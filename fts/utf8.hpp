#ifndef UTF8_HPP
#define UTF8_HPP

#include <codecvt>
#include <string>
#include <locale>

inline char32_t chtocp(std::string character) {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    return converter.from_bytes(character)[0];
}

inline std::string cptoch(char32_t codepoint) {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    return converter.to_bytes(&codepoint, &codepoint + 1);
}

#endif
