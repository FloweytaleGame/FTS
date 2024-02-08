#include <bitset>
#include <string>
#include <vector>
#include <cstdint>

#include "fts.hpp"
#include "split.hpp"
#include "join.hpp"
#include "utf8.hpp"

/**
 * Constructs an FTSLib save from the save file as a string.
 * 
 * @param file_content String of the raw save file that will be decoded.
 * @return Save decoded from the raw save file.
*/
extern "C" __declspec(dllexport) FTSLib_Save FTSLib_decode_file(std::string file_content) {
    // get all attribute strings as a vector
    std::vector<std::string> attributes = split(file_content, ",");

    // uses chtocp to convert the corresponding codepoint from the character, which is a number and used as data.
    std::string        character_name = attributes[0];
    uint8_t            hp             = (uint8_t)         chtocp(attributes[1]);
    uint8_t            max_hp         = (uint8_t)         chtocp(attributes[2]);
    uint8_t            at             = (uint8_t)         chtocp(attributes[3]);
    uint8_t            df             = (uint8_t)         chtocp(attributes[4]);
    uint32_t           exp            = (uint32_t)        chtocp(attributes[5]);
    uint8_t            love           = (uint8_t)         chtocp(attributes[6]);
    uint8_t            inv            = (uint8_t)         chtocp(attributes[7]);
    uint8_t            speed          = (uint8_t)         chtocp(attributes[8]);
    uint8_t            murder_level   = (uint8_t)         chtocp(attributes[9]);
    int16_t            x              = (int16_t)         chtocp(attributes[10]);
    int16_t            y              = (int16_t)         chtocp(attributes[11]);
    std::bitset<2>     path           = (std::bitset<2>)  chtocp(attributes[12]);
    std::bitset<29>    achievements   = (std::bitset<29>) chtocp(attributes[13]);

    // constructs save and returns it.
    FTSLib_Save save {
        character_name,
        hp,
        max_hp,
        at,
        df,
        exp,
        love,
        inv,
        speed,
        murder_level,
        x,
        y,
        path,
        achievements,
    };
    return save;
}

extern "C" __declspec(dllexport) std::string FTSLib_encode_file(FTSLib_Save save) {
    // will store all attributrs
    std::vector<std::string> attributes;

    // puts to cptoch to convert the data into text, where every character is characterized by its codepoint, having each value caracterized by a codepoint.
    attributes.push_back(                   save.character_name);
    attributes.push_back(cptoch((char32_t)  save.hp));
    attributes.push_back(cptoch((char32_t)  save.max_hp));
    attributes.push_back(cptoch((char32_t)  save.at));
    attributes.push_back(cptoch((char32_t)  save.df));
    attributes.push_back(cptoch((char32_t)  save.exp));
    attributes.push_back(cptoch((char32_t)  save.love));
    attributes.push_back(cptoch((char32_t)  save.inv));
    attributes.push_back(cptoch((char32_t)  save.speed));
    attributes.push_back(cptoch((char32_t)  save.murder_level));
    attributes.push_back(cptoch((char32_t)  save.x));
    attributes.push_back(cptoch((char32_t)  save.y));
    attributes.push_back(cptoch((char32_t)  save.path.to_ulong()));
    attributes.push_back(cptoch((char32_t)  save.achievements.to_ulong()));

    // joins the vector back into a string.
    return join(attributes, ",");
}
