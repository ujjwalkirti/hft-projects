#include <iostream>
#include "utils/mmap_reader.h"
#include "itch/itch_parser.h"
#include "itch/itch_messages_generator.h"

using namespace std;

int main(int argc, char const *argv[])
{
    std::cout << "Feed handler starting..." << std::endl;

    cout<< "Generating test file..." << endl;
    ItchMessageGenerator();

    cout<< "Parsing test file..." << endl;
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
