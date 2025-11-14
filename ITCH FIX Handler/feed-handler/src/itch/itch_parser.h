#pragma once
#include <cstddef>
#include <cstdint>

class ItchParser{
    public:
        ItchParser(const uint8_t* data, size_t size);

        void parseAll();

    private:
        const uint8_t* data_;
        size_t size_;
};
