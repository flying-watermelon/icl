/**
 * @file ICL.h
 * @version 1.0
 */
#ifndef __ICL_H__
#define __ICL_H__

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////

/**
 * @defgroup info info
 * A function set that can be used for fetching the general information or the
 * meta data of the ICL itself or its underlying implementation.
 * @{
 */

/**
 * @brief Get the ICL version.
 * @return
 *     A pointer to the string containing the version of the ICL.
 */
const char *icl_info_getVersion();

/**
 * @brief Get the implementation of the ICL.
 * @return
 *     A pointer to the string containing the implementation information of the
 *     ICL. The format should be `<name>:<version>`, where the `<name>` should
 *     be in kebab-case.
 */
const char *icl_info_getImplementation();

/**
 * @}
 */

///////////////////////////////////////////////////////////////////////////////

/**
 * @defgroup i2c i2c
 * Functions that serve as an abstraction of I2C protocol.
 * @{
 */

/**
 * @brief Set the baud rate of the I2C.
 * @param [in] baud
 *     Baud rate of the I2C data transferring.
 * @return
 *     Zero if there is no error, otherwise an non-zero error code.
 */
int icl_i2c_setBaudRate(int baud);

/**
 * @brief Write a batch of bytes to the specified slave address.
 * @param [in] slaveAddress
 *     The I2C address of the slave address. Maximum 10 bits, higher bits will
 *     be ignored.
 * @param [in] count
 *     The length of the byte array.
 * @param [in] bytes
 *     A byte array containing all the bytes that will be sent to the slave
 *     device.
 * @return
 *     Zero if there is no error, otherwise an non-zero error code.
 */
int icl_i2c_writeBytes(uint16_t slaveAddress, size_t count, const uint8_t *bytes);

/**
 * @brief Read a batch of bytes from the specified slave address.
 * @param [in] slaveAddress
 *     The I2C address of the slave address. Maximum 10 bits, higher bits will
 *     be ignored.
 * @param [in] count
 *     The length in bytes of the information that is going to be read.
 * @param [out] bytes
 *     The content of the read data.
 * @return
 *     Zero if there is no error, otherwise an non-zero error code.
 */
int icl_i2c_readBytes(uint16_t slaveAddress, size_t count, uint8_t *byte);

/**
 * @}
 */

///////////////////////////////////////////////////////////////////////////////

/**
 * @defgroup spi spi
 * Functions that serve as an abstraction of SPI protocol.
 * @{
 */

/**
 * @brief Set the clock speed of the SPI.
 * @param [in] hz
 *     Clock speed in Hz of the SPI data transferring.
 * @return
 *     Zero if there is no error, otherwise an non-zero error code.
 */
int icl_spi_setSpeed(int hz);

/**
 * @brief Transfer a batch of bytes between the master and the slave devices.
 * @param [in] chip
 *     Select chip using an integer number.
 * @param [in] sent
 *     An array of bytes that are going to be sent to the slave device.
 * @param [out] received
 *     An array of bytes that are received from the slave device.
 * @return
 *     Zero if there is no error, otherwise an non-zero error code.
 */
int icl_spi_transferBytes(int chip, size_t count, uint8_t *send, uint8_t *received);

/**
 * @}
 */

#ifdef __cplusplus
} // extern "C"
#endif

#endif
