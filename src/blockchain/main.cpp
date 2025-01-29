#include <iostream>
#include "block.h"

int main() {

    int difficulty = 4;

    std::cout << "Creating Genesis Block..." << std::endl;
    Block genesisBlock(0, "0", "Genesis Block Data");

    genesisBlock.mineBlock(difficulty);

    std::cout << "Block Mined!" << std::endl;
    std::cout << "Index: " << 0 << std::endl;
    std::cout << "Hash: " << genesisBlock.getHash() << std::endl;
    std::cout << "Previous Hash: " << genesisBlock.getPreviousHash() << std::endl;
    std::cout << "Timestamp: " << genesisBlock.getTimestamp() << std::endl;

    return 0;
}
