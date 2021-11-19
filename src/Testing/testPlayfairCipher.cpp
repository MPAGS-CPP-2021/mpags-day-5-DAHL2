//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "PlayfairCipher.hpp"

std::string testPlayfairKeyFormat(PlayfairCipher pc)
{
    return pc.key_;
}

TEST_CASE("Playfair Cipher key format", "[playfair]")
{
    PlayfairCipher pc{"this_is A badly DEFINE-d Key!1234567890"};
    REQUIRE(testPlayfairKeyFormat(pc) == "THISABDLYEFNKCGMOPQRUVWXZ");
}