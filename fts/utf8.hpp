#ifndef UTF8_HPP
#define UTF8_HPP

#include <codecvt>
#include <string>
#include <locale>

/**
 * @brief Converts a UTF-8 character into a codepoint.
 * 
 * @param character The UTF-8 character that will be converted into a codepoint.
 * @return The codepoint itself (can be converted into an int).
 */
inline char32_t chtocp(std::string character) {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    return converter.from_bytes(character)[0];
}

/**
 * @brief Converts a UTF-8 codepoint into a UTF-8 character.
 * 
 * @param character The UTF-8 codepoint that will be converted into a character.
 * @return The converted character.
 */
inline std::string cptoch(char32_t codepoint) {
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    return converter.to_bytes(&codepoint, &codepoint + 1);
}

#endif
