/* * OSS-7 - An opensource implementation of the DASH7 Alliance Protocol for ultra
 * lowpower wireless sensor communication
 *
 * Copyright 2015 University of Antwerp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*! \file hwi2c.h
 * \addtogroup I2C
 * \ingroup HAL
 * @{
 * \brief Provides an API for I2C
 * \author maarten.weyn@uantwerpen.be
 * \author jens.vanhooydonck@student.uantwerpen.be
 * \author contact@christophe.vg
 */


#ifndef I2C_H_
#define I2C_H_

#include "types.h"
#include "link_c.h"

// expose i2c_handle with unknown internals
typedef struct i2c_handle i2c_handle_t;

__LINK_C i2c_handle_t* 	i2c_init(uint8_t i2c_port_idx, uint8_t pins, uint32_t baudrate); // TODO remove pins argument after all drivers are migrated
__LINK_C int8_t		 	i2c_deinit(i2c_handle_t* i2c);
__LINK_C void i2c_acquire(i2c_handle_t* i2c);
__LINK_C void i2c_release(i2c_handle_t* i2c);

__LINK_C int8_t        	i2c_write(i2c_handle_t* i2c,      uint8_t address, uint8_t* tx_buffer, int length);
__LINK_C int8_t        	i2c_read(i2c_handle_t* i2c,       uint8_t address, uint8_t* rx_buffer, int length);

// register_address_size in bits
__LINK_C int8_t        	i2c_write_memory(i2c_handle_t* i2c, uint8_t to, uint16_t register_address, uint8_t register_address_size, uint8_t* payload, int length);
// register_address_size in bits
__LINK_C int8_t 		i2c_read_memory(i2c_handle_t* i2c, uint8_t to, uint16_t register_address, uint8_t register_address_size, uint8_t* payload, int length);
__LINK_C int8_t        	i2c_write_read(i2c_handle_t* i2c, uint8_t address, uint8_t* tx_buffer, int lengthtx, uint8_t* rx_buffer, int lengthrx);


#endif

/** @}*/
