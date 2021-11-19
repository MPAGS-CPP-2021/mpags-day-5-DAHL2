//! Unit Tests for MPAGSCipher VigenereCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

TEST_CASE("Vigenere Cipher encryption", "[playfair]")
{
    VigenereCipher vc{"key"};
    REQUIRE(vc.applyCipher("HELLOWORLD", CipherMode::Encrypt) == "RIJVSUYVJN");
}

TEST_CASE("Vigenere Cipher decryption", "[playfair]")
{
    VigenereCipher vc{"key"};
    REQUIRE(vc.applyCipher("RIJVSUYVJN", CipherMode::Decrypt) == "HELLOWORLD");
}
