#include "block.h"
#include <sstream>
#include <iomanip>
#include <openssl/sha.h> 


Block::Block(int idx, std::string prevHash, std::string blockData) 
    : index(idx), previousHash(prevHash), data(blockData), nonce(0) {
    timestamp = time(nullptr); 
    hash = calculateHash();    
}


std::string Block::calculateHash() {
    std::stringstream ss;
    ss << index << previousHash << timestamp << data << nonce;

   
    unsigned char hashResult[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)ss.str().c_str(), ss.str().size(), hashResult);

    
    std::stringstream hexStream;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        hexStream << std::hex << std::setw(2) << std::setfill('0') << (int)hashResult[i];

    return hexStream.str();
}


void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0'); 

    while (hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculateHash(); 
    }
}


std::string Block::getHash() const {
    return hash;
}

std::string Block::getPreviousHash() const {
    return previousHash;
}

long Block::getTimestamp() const {
    return timestamp;
}
