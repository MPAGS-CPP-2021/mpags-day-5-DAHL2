//! Unit Tests for MPAGSCipher cipher classes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "CipherMode.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher(const Cipher& cipher, const CipherMode mode,
                const std::string& inputText, const std::string& outputText)
{
    return cipher.applyCipher(inputText, mode) == outputText;
}

std::string testKeyFormat(VigenereCipher vc)
{
    return vc.key_;
}

TEST_CASE("Caesar Cipher encryption", "[caesar]")
{
    REQUIRE(testCipher(CaesarCipher(10), CipherMode::Encrypt, "HELLOWORLD",
                       "ROVVYGYBVN"));
}

TEST_CASE("Caesar Cipher decryption", "[caesar]")
{
    REQUIRE(testCipher(CaesarCipher(10), CipherMode::Decrypt, "ROVVYGYBVN",
                       "HELLOWORLD"));
}

TEST_CASE("Playfair Cipher encryption", "[playfair]")
{
    REQUIRE(testCipher(PlayfairCipher("hello"), CipherMode::Encrypt,
                       "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING",
                       "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"));
}

TEST_CASE("Playfair Cipher decryption", "[playfair]")
{
    REQUIRE(testCipher(PlayfairCipher("hello"), CipherMode::Decrypt,
                       "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA",
                       "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"));
}

TEST_CASE("Vigenere Cipher encryption", "[vigenere]")
{
    REQUIRE(testCipher(VigenereCipher("key"), CipherMode::Encrypt, "HELLOWORLD",
                       "RIJVSUYVJN"));
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]")
{
    REQUIRE(testCipher(VigenereCipher("key"), CipherMode::Decrypt, "RIJVSUYVJN",
                       "HELLOWORLD"));
}

TEST_CASE("Vigenere Cipher key format", "[vigenere]")
{
    VigenereCipher vc{"this_is A badly DEFINE-d Key!1234567890"};
    REQUIRE(testKeyFormat(vc) == "THISISABADLYDEFINEDKEY");
}
