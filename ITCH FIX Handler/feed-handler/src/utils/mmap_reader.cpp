#include "utils/mmap_reader.h"
#include <stdexcept>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

MMapReader::MMapReader(const std::string &path)
{
    fd_ = open(path.c_str(), O_RDONLY);

    if (fd_ < 0)
    {
        throw std::runtime_error("Failed to open file:" + path);
    }

    struct stat st{};

    if (fstat(fd_, &st) < 0)
    {
        close(fd_);
        throw std::runtime_error("Failed to stat file: " + path);
    }

    size_ = st.st_size;

    buffer_ = static_cast<uint8_t *>(mmap(nullptr, size_, PROT_READ, MAP_PRIVATE, fd_, 0));
    if (buffer_ == MAP_FAILED)
    {
        close(fd_);
        throw std::runtime_error("mmap failed");
    }
}

MMapReader::~MMapReader()
{
    munmap(buffer_, size_);
    close(fd_);
}
