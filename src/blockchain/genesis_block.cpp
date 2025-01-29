#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

// Helper function to calculate SHA-256 hash
std::string sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

// Block structure
class Block {
public:
    int index;
    std::string previousHash;
    std::string timestamp;
    std::string data;
    int nonce;
    std::string hash;

    Block(int idx, const std::string& prevHash, const std::string& time, const std::string& blkData)
        : index(idx), previousHash(prevHash), timestamp(time), data(blkData), nonce(0) {
        hash = calculateHash();
    }

    std::string calculateHash() const {
        std::stringstream ss;
        ss << index << previousHash << timestamp << data << nonce;
        return sha256(ss.str());
    }

    void mineBlock(int difficulty) {
        std::string target(difficulty, '0'); // Create difficulty target (e.g., "0000")
        while (hash.substr(0, difficulty) != target) {
            nonce++;
            hash = calculateHash();
        }
        std::cout << "Block mined: " << hash << std::endl;
    }
};

int main() {
    std::cout << "Creating Genesis Block...\n";

    // Genesis block parameters
    int genesisIndex = 0;
    std::string genesisPreviousHash = "0";
    std::string genesisTimestamp = "2025-01-26 12:00:00";
    std::string genesisData = "Genesis Block for Aura Network";

    Block genesisBlock(genesisIndex, genesisPreviousHash, genesisTimestamp, genesisData);

    int miningDifficulty = 4; // Example difficulty level
    genesisBlock.mineBlock(miningDifficulty);

    // Display block information
    std::cout << "Genesis Block Information:" << std::endl;
    std::cout << "Index: " << genesisBlock.index << std::endl;
    std::cout << "Previous Hash: " << genesisBlock.previousHash << std::endl;
    std::cout << "Timestamp: " << genesisBlock.timestamp << std::endl;
    std::cout << "Data: " << genesisBlock.data << std::endl;
    std::cout << "Nonce: " << genesisBlock.nonce << std::endl;
    std::cout << "Hash: " << genesisBlock.hash << std::endl;

    return 0;
}
