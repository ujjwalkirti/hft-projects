#pragma once
#include <cstddef>
#include <cstdint>
#include <string>

class MMapReader
{
public:
    MMapReader(const std::string &path);
    ~MMapReader();

    const uint8_t *data() const { return buffer_; }
    size_t size() const { return size_; }

private:
    int fd_;
    size_t size_;
    uint8_t *buffer_;
};
