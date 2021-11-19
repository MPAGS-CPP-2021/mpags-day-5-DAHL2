#include "VigenereCipher.hpp"
#include "Alphabet.hpp"
#include "CaesarCipher.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

VigenereCipher::VigenereCipher(const std::string& key)
{
    setKey(key);
}

void VigenereCipher::setKey(const std::string& key)
{
    // Ensure key is filled and capitalised
    _formatKey(key);

    size_t char_key{0};

    using lookupEntry = std::pair<char, CaesarCipher>;

    CaesarCipher char_cipher{0};

    for (char const& c : key_) {
        // Don't need to add duplicates of entries to the map
        if (charLookup_.count(c) > 0) {
            continue;
        }

        // Find the letter position in the alphabet
        char_key = Alphabet::alphabet.find(c);

        char_cipher = CaesarCipher(char_key);

        // Add the character and corresponding cipher to the map
        charLookup_.insert(lookupEntry{c, char_cipher});
    }
}

void VigenereCipher::_formatKey(const std::string& key)
{
    key_ = key;

    // Remove non-alphabet characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
                              [](char c) { return !std::isalpha(c); }),
               std::end(key_));

    // Check if the key is empty and replace with default if so
    if (key_.empty()) {
        std::cout << "No key found. Resorting to default key: \"KEY\"."
                  << std::endl;
        key_ = "KEY";
    }

    // If not empty, need to be certain letters are uppercase
    else {
        std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                       ::toupper);
    }

    key_size_ = key_.size();
}

std::string VigenereCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{
    std::string outputText{""};

    std::string input_char_string{""};
    char key_char{};

    // For each letter in input:
    for (size_t i{0}; i < inputText.size(); i++) {
        input_char_string = inputText[i];

        key_char = key_[i % key_size_];

        outputText +=
            charLookup_.at(key_char).applyCipher(input_char_string, cipherMode);
    }

    return outputText;
}