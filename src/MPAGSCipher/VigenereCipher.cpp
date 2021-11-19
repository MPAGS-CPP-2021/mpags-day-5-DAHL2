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

    for (char const& c : key_) {
        // Don't need to add duplicates of entries to the map
        if (charLookup_.count(c) > 0) {
            continue;
        }

        // Find the letter position in the alphabet
        char_key = Alphabet::alphabet.find(c);

        // Add the character and corresponding cipher to the map
        charLookup_.insert(lookupEntry{c, CaesarCipher(char_key)});
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
    // Reserve the sting space for slightly faster processing
    outputText.reserve(inputText.size());

    std::string input_char_string{""};
    char key_char{};

    // For each letter in input:
    for (size_t i{0}; i < inputText.size(); i++) {
        // Need input character as a string for CaesarCipher
        input_char_string = inputText[i];

        // Modulus to make the key repeat as needed
        key_char = key_[i % key_size_];

        // We lookup the cipher at the given character, then apply that cipher
        //  with the input letter as a string
        outputText +=
            charLookup_.at(key_char).applyCipher(input_char_string, cipherMode);
    }

    return outputText;
}