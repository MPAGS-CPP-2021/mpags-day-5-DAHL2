#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include "CaesarCipher.hpp"
#include "Cipher.hpp"
#include "CipherMode.hpp"

#include <map>
#include <string>

/**
 * \file VigenereCipher.hpp
 * \brief Contains the declaration of the VigenereCipher class
 */

/**
 * \class VigenereCipher
 * \brief Encrypt or decrypt text using the Vigenere cipher with the given key
 */
class VigenereCipher : public Cipher {
  public:
    /**
     * \brief Create a new VigenereCipher with the given key
     *
     * \param key the key to use in the cipher
     */
    explicit VigenereCipher(const std::string& key);

    /**
     * \brief Set the internal key and ciphers of the Vigenere Cipher from the supplied key
     * 
     * \param key the key to use in the cipher
     */
    void setKey(const std::string& key);

    /**
     * \brief Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    std::string applyCipher(const std::string& inputText,
                            const CipherMode cipherMode) const override;

  private:
    /**
     * \brief Set the interal key value and size to the supplied key with correct formatting
     * 
     * \param key the key to use in the cipher
     */
    void _formatKey(const std::string& key);

    /// The cipher key
    std::string key_ = "";
    /// Size of the cipher key
    size_t key_size_ = 0;
    /// Lookup table
    std::map<char, CaesarCipher> charLookup_;

    /**
     * \brief Friend class to allow testing of key formatting
     * 
     * \param vc Vigenere cipher clas from which the key value must be taken from
     */
    friend std::string testKeyFormat(VigenereCipher vc);
};

#endif
