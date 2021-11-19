#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

#include <map>
#include <string>

class VigenereCipher {
  public:
    explicit VigenereCipher(const std::string& key);

    void setKey(const std::string& key);

    std::string applyCipher(const std::string& inputText,
                            const CipherMode cipherMode) const;

  private:
    void _formatKey(const std::string& key);

    /// The cipher key
    std::string key_ = "";
    /// Lookup table
    std::map<char, CaesarCipher> charLookup_;
};

#endif
