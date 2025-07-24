//
// Created by Lukáš Blažek on 23.07.2025.
//

#ifndef TYPES_H
#define TYPES_H
#include <bitset>
#include <cstdint>

using Entity = uint32_t;

inline constexpr Entity MAX_ENTITIES = 5000;

using ComponentType = uint8_t;

inline constexpr ComponentType MAX_COMPONENTS = 50;

using Signature = std::bitset<MAX_COMPONENTS>;



#endif //TYPES_H
