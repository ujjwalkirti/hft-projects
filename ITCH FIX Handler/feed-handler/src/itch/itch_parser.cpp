#include "itch/itch_parser.h"
#include <iostream>
#include "itch/itch_messages.h"

static size_t getMessageSize(char type) {
    switch (type) {
        case 'A': return 32;
        case 'F': return 40;
        case 'E': return 31;
        case 'C': return 35;
        case 'X': return 23;
        case 'D': return 19;
        case 'U': return 34;
        case 'P': return 44;
        case 'Q': return 40;
        case 'R': return 39;
        case 'H': return 15;
        case 'Y': return 20;
        default:  return 1;
    }
}


ItchParser::ItchParser(const uint8_t *data, size_t size)
    : data_(data), size_(size) {}

void ItchParser::parseAll()
{
    size_t pos = 0;

    while (pos < size_)
    {
        char msgType = data_[pos];
        size_t msgSize = getMessageSize(msgType);

        if (pos + msgSize > size_){
            std::cerr << "Truncated message at the end of file. \n" << std::endl;
            return;
        }

        if(msgType == 'A'){
            const AddOrderMessage* msg = reinterpret_cast<const AddOrderMessage*>(data_ + pos);

            std::cout << "---- Add Order ----\n";
            std::cout << "Timestamp: " << msg->timestamp << "\n";
            std::cout << "Order ID:  " << msg->orderId << "\n";
            std::cout << "Side:      " << msg->side << "\n";
            std::cout << "Shares:    " << msg->shares << "\n";

            std::cout << "Stock:     ";
            for (int i = 0; i < 8; i++)
                std::cout << msg->stock[i];
            std::cout << "\n";

            std::cout << "Price:     " << msg->price << "\n";
            std::cout << "-------------------\n";

        }
        pos += msgSize;
    }
}
