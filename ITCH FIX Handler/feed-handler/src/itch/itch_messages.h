#pragma once
#include <cstdint>

#pragma pack(push, 1)
struct AddOrderMessage{
    char messageType;
    uint64_t timestamp;
    uint64_t orderId;
    char side;
    uint32_t shares;
    char stock[8];
    uint32_t price;
};
#pragma pack(pop)
