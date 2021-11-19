//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Alphabet.hpp"
#include "CaesarCipher.hpp"

std::size_t testCaesarKeyFormat(CaesarCipher cc)
{
    return cc.key_;
}

TEST_CASE("Caesar Cipher key from integer", "[caesar]")
{
    CaesarCipher cc{50u};
    REQUIRE(testCaesarKeyFormat(cc) == 50 % Alphabet::size);
}

TEST_CASE("Caesar Cipher key from string", "[caesar]")
{
    CaesarCipher cc{"21"};
    REQUIRE(testCaesarKeyFormat(cc) == 21 % Alphabet::size);
}