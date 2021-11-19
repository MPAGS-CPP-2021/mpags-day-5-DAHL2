//! Unit Tests for MPAGSCipher VigenereCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

std::string testVigenereKeyFormat(VigenereCipher vc)
{
    return vc.key_;
}

TEST_CASE("Vigenere Cipher key format", "[vigenere]")
{
    VigenereCipher vc{"this_is A badly DEFINE-d Key!1234567890"};
    REQUIRE(testVigenereKeyFormat(vc) == "THISISABADLYDEFINEDKEY");
}
