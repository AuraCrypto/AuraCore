#include <iostream>
#include "block.h"

int main() {
    // سختی شبکه (تعداد صفرهای موردنیاز در ابتدای هش)
    int difficulty = 4;

    // ساخت بلاک اولیه (Genesis Block)
    std::cout << "Creating Genesis Block..." << std::endl;
    Block genesisBlock(0, "0", "Genesis Block Data");

    // ماین کردن بلاک اولیه
    genesisBlock.mineBlock(difficulty);

    // نمایش اطلاعات بلاک اولیه
    std::cout << "Block Mined!" << std::endl;
    std::cout << "Index: " << 0 << std::endl;
    std::cout << "Hash: " << genesisBlock.getHash() << std::endl;
    std::cout << "Previous Hash: " << genesisBlock.getPreviousHash() << std::endl;
    std::cout << "Timestamp: " << genesisBlock.getTimestamp() << std::endl;

    return 0;
}
