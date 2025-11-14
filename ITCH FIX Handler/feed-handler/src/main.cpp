#include <iostream>
#include "utils/mmap_reader.h"
#include "itch/itch_parser.h"

int main(int argc, char const *argv[])
{
    std::cout << "Feed handler starting..." << std::endl;

    if (argc < 2)
    {
        std::cerr << "Usage: ./feed_handler <itch_file>" << std::endl;
        return 1;
    }

    try
    {
        MMapReader reader(argv[1]);

        ItchParser parser(reader.data(), reader.size());
        parser.parseAll();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
