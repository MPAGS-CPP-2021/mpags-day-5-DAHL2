#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

#include "Cipher.hpp"
#include "CipherType.hpp"

#include <memory>
#include <string>

/**
 * \file CipherFactory.hpp
 * \brief Contains a pointer function to the chosen type of cipher
 */

/**
 * \brief Creates a pointer to the specified type of cipher
 * 
 * \param type type of cipher to create
 * \param key key with which to implement the cipher
 * 
 * \return a unique pointer to the chosen cipher
 */
std::unique_ptr<Cipher> cipherFactory(const CipherType type,
                                      std::string const key);

#endif
