//! Unit Tests for MPAGSCipher VigenereCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

std::string testKeyFormat(VigenereCipher vc)
{
    return vc.key_;
}

TEST_CASE("Vigenere Cipher key format", "[vigenere]")
{
    VigenereCipher vc{"this_is A badly DEFINE-d Key!1234567890"};
    REQUIRE(testKeyFormat(vc) == "THISISABADLYDEFINEDKEY");
}

TEST_CASE("Vigenere Cipher encryption", "[vigenere]")
{
    VigenereCipher vc{"key"};
    REQUIRE(vc.applyCipher("HELLOWORLD", CipherMode::Encrypt) == "RIJVSUYVJN");
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]")
{
    VigenereCipher vc{"key"};
    REQUIRE(vc.applyCipher("RIJVSUYVJN", CipherMode::Decrypt) == "HELLOWORLD");
}
