#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include <ctime>

class Block {
private:
    int index;                      
    std::string previousHash;       
    std::string hash;               
    std::string data;               
    long timestamp;                
    int nonce;                     

public:
    
    Block(int idx, std::string prevHash, std::string blockData);

    
    std::string calculateHash();    
    void mineBlock(int difficulty); // 

   
    std::string getHash() const;
    std::string getPreviousHash() const;
    long getTimestamp() const;
};

#endif // BLOCK_H
