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
    _formatKey(key);

    // loop over the key

    // Find the letter position in the alphabet

    // Create a CaesarCipher using this position as a key

    // Insert a std::pair of the letter and CaesarCipher into the lookup
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
        key_ = "KEY";
    }
    // If not empty, need to be certain letters are uppercase
    else {
        // Make sure the key is uppercase
        std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                       ::toupper);
    }
}

std::string VigenereCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{
    // // Create the output string
    // std::string outputText;

    // // Loop over the input text
    // char processedChar{'x'};
    // for (const auto& origChar : inputText) {
    //     // For each character in the input text, find the corresponding position in
    //     // the alphabet by using an indexed loop over the alphabet container
    //     for (std::size_t i{0}; i < Alphabet::size; ++i) {
    //         if (origChar == Alphabet::alphabet[i]) {
    //             // Apply the appropriate shift (depending on whether we're encrypting
    //             // or decrypting) and determine the new character
    //             // Can then break out of the loop over the alphabet
    //             switch (cipherMode) {
    //                 case CipherMode::Encrypt:
    //                     processedChar =
    //                         Alphabet::alphabet[(i + key_) % Alphabet::size];
    //                     break;
    //                 case CipherMode::Decrypt:
    //                     processedChar =
    //                         Alphabet::alphabet[(i + Alphabet::size - key_) %
    //                                            Alphabet::size];
    //                     break;
    //             }
    //             break;
    //         }
    //     }

    //     // Add the new character to the output text
    //     outputText += processedChar;
    // }
    if (cipherMode == CipherMode::Encrypt) {
        return inputText;
    } else {
        return "DECRYPT";
    }
}