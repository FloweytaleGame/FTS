#include <iostream>

#include "fts/fts.hpp"

int main() {
    FTSLib_Save save {
        "bananananana",
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        11,
        std::bitset<2>(1),
        std::bitset<29>(2),
    };
    
    std::string encoded_save = FTSLib_encode_file(save);
    std::cout << "Encoded save file: " << encoded_save << std::endl << std::endl;

    FTSLib_Save decoded_save = FTSLib_decode_file(encoded_save);
    std::cout << "Decoded:" << std::endl;
    std::cout << "Character name: " << decoded_save.character_name << std::endl;
    std::cout << "HP: " << +decoded_save.hp << std::endl;
    std::cout << "Max HP: " << +decoded_save.max_hp << std::endl;
    std::cout << "AT: " << +decoded_save.at << std::endl;
    std::cout << "DF: " << +decoded_save.df << std::endl;
    std::cout << "EXP: " << +decoded_save.exp << std::endl;
    std::cout << "LOVE: " << +decoded_save.love << std::endl;
    std::cout << "INV: " << +decoded_save.inv << std::endl;
    std::cout << "SPEED: " << +decoded_save.speed << std::endl;
    std::cout << "MURDER LEVEL: " << +decoded_save.murder_level << std::endl;
    std::cout << "X: " << +decoded_save.x << std::endl;
    std::cout << "Y: " << +decoded_save.y << std::endl;
    std::cout << "PATH: " << +decoded_save.path.to_ulong() << std::endl;
    std::cout << "ACHIEVEMENTS: " << +decoded_save.achievements.to_ulong() << std::endl;

    return 0;
}
