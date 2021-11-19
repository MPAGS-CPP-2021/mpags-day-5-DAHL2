#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

#include "CipherMode.hpp"

#include <string>

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of a the Cipher class
 */

/**
 * \class Cipher
 * \brief Contains a generic Cipher class able to encrypt/decrypt some input text
 */
class Cipher {
  public:
    /**
     * \brief Compiler constructor function
     */
    Cipher() = default;

    /**
     * \brief Compiler copy function
     * 
     * \param rhs object to be copied
     */
    Cipher(const Cipher& rhs) = default;

    /**
     * \brief Compiler move function
     * 
     * \param rhs object to be moved
     */
    Cipher(Cipher&& rhs) = default;

    /**
     * \brief Compiler operator assigned copy function
     * 
     * \param rhs object to be copied
     */
    Cipher& operator=(const Cipher& rhs) = default;

    /**
     * \brief Compiler operator assigned move function
     * 
     * \param rhs object to be moved
     */
    Cipher& operator=(Cipher&& rhs) = default;

    /**
     * \brief Compiler destructor function
     */
    virtual ~Cipher() = default;

    /**
     * \brief Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    virtual std::string applyCipher(const std::string& input,
                                    const CipherMode mode) const = 0;
};

#endif
