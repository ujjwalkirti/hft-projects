#include <iostream>
#include <fstream>
#include "itch/itch_messages.h"
#include <ctime>
#include "itch/itch_messages_generator.h"

using namespace std;

void ItchMessageGenerator()
{
    fstream fout;

    fout.open("./test.itch", ios::out | ios::binary);

    if (fout)
    {
        AddOrderMessage msg;
        msg.messageType = 'A';
        msg.timestamp = time(0);
        msg.orderId = 0;
        msg.side = 'B';
        msg.shares = 0;
        msg.stock[0] = 'A';
        msg.stock[1] = 'B';
        msg.stock[2] = 'C';
        msg.stock[3] = 'D';
        msg.stock[4] = 'E';
        msg.stock[5] = 'F';
        msg.stock[6] = 'G';
        msg.stock[7] = 'H';
        msg.price = 0;

        // add 10 messages
        for (int i = 0; i < 10; i++)
        {
            fout.write(reinterpret_cast<const char *>(&msg), sizeof(AddOrderMessage));
        }

    }else{
        cout << "Error opening file" << endl;
    }
    fout.close();
}
