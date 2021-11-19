#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "Cipher.hpp"
#include "CipherType.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

#include <memory>
#include <string>

std::unique_ptr<Cipher> cipherFactory(const CipherType type,
                                      std::string const key)
{
    switch (type) {
        case CipherType::Caesar: {
            return std::make_unique<CaesarCipher>(key);
        }
        case CipherType::Playfair: {
            return std::make_unique<PlayfairCipher>(key);
        }
        case CipherType::Vigenere: {
            return std::make_unique<VigenereCipher>(key);
        }
    }
    // gcc thinks it can get through the switch case so need to catch it!
    return std::make_unique<CaesarCipher>(key);
}
