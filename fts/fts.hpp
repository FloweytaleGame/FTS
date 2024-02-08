#ifndef FTS_HPP
#define FTS_HPP

#include <bitset>
#include <string>
#include <cstdint>

extern "C" {
    /**
     * @brief A structure containing all attributes of a FloweyTale save file.
     * 
     */
    struct __declspec(dllexport) FTSLib_Save {
    public:
        std::string        character_name;
        uint8_t            hp;
        uint8_t            max_hp;
        uint8_t            at;
        uint8_t            df;
        uint32_t           exp;
        uint8_t            love;
        uint8_t            inv;
        uint8_t            speed;
        uint8_t            murder_level;
        int16_t            x;
        int16_t            y;
        std::bitset<2>     path;
        std::bitset<29>    achievements;
    };
    __declspec(dllexport) FTSLib_Save FTSLib_decode_file(std::string file_content);    // defined in fts.cpp
    __declspec(dllexport) std::string FTSLib_encode_file(FTSLib_Save save);            // defined in fts.cpp
}

#endif
