//! Unit Tests for MPAGSCipher cipher classes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "Cipher.hpp"
#include "CipherFactory.hpp"
#include "CipherMode.hpp"
#include "CipherType.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

#include <memory>
#include <string>
#include <vector>

TEST_CASE("Good luck finding the problem!", "[everything]")
{
    std::vector<std::unique_ptr<Cipher>> ciphers;
    // Manually adding ciphers to the vector because they can have different types of key
    ciphers.push_back(cipherFactory(CipherType::Caesar, "10"));
    ciphers.push_back(cipherFactory(CipherType::Playfair, "hello"));
    ciphers.push_back(cipherFactory(CipherType::Vigenere, "key"));

    // Been sneaky and picked a message with no repeated pairs and even number of letters
    const std::string inputString{"THISISMYINPUTMESSAGE"};

    std::vector<std::string> encryptedStrings;
    encryptedStrings.push_back("DRSCSCWISXZEDWOCCKQO");
    encryptedStrings.push_back("QOMQMQNXKPUZSNLRULCA");
    encryptedStrings.push_back("DLGCMQWCGXTSDQCCWYQI");

    for (size_t i{0}; i < ciphers.size(); i++) {
        REQUIRE(ciphers[i]->applyCipher(inputString, CipherMode::Encrypt) ==
                encryptedStrings[i]);
        REQUIRE(ciphers[i]->applyCipher(encryptedStrings[i],
                                        CipherMode::Decrypt) == inputString);
    }
}

// // What follows is the sensible way to do this...
// //  But this is a coding excercise so we are using the above method which pretty useless!
// TEST_CASE("Caesar Cipher encryption", "[caesar]")
// {
//     REQUIRE(testCipher(CaesarCipher(10), CipherMode::Encrypt, "HELLOWORLD",
//                        "ROVVYGYBVN"));
// }

// TEST_CASE("Caesar Cipher decryption", "[caesar]")
// {
//     REQUIRE(testCipher(CaesarCipher(10), CipherMode::Decrypt, "ROVVYGYBVN",
//                        "HELLOWORLD"));
// }

// TEST_CASE("Playfair Cipher encryption", "[playfair]")
// {
//     REQUIRE(testCipher(PlayfairCipher("hello"), CipherMode::Encrypt,
//                        "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING",
//                        "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"));
// }

// TEST_CASE("Playfair Cipher decryption", "[playfair]")
// {
//     REQUIRE(testCipher(PlayfairCipher("hello"), CipherMode::Decrypt,
//                        "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA",
//                        "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"));
// }

// TEST_CASE("Vigenere Cipher encryption", "[vigenere]")
// {
//     REQUIRE(testCipher(VigenereCipher("key"), CipherMode::Encrypt, "HELLOWORLD",
//                        "RIJVSUYVJN"));
// }

// TEST_CASE("Vigenere Cipher decryption", "[vigenere]")
// {
//     REQUIRE(testCipher(VigenereCipher("key"), CipherMode::Decrypt, "RIJVSUYVJN",
//                        "HELLOWORLD"));
// }
