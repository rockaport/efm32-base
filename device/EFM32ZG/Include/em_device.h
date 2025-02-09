/***************************************************************************//**
 * @file
 * @brief CMSIS Cortex-M Peripheral Access Layer for Silicon Laboratories
 *        microcontroller devices
 *
 * This is a convenience header file for defining the part number on the
 * build command line, instead of specifying the part specific header file.
 *
 * @verbatim
 * Example: Add "-DEFM32G890F128" to your build options, to define part
 *          Add "#include "em_device.h" to your source files
 * @endverbatim
 *
 * @version 5.8.0
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#ifndef EM_DEVICE_H
#define EM_DEVICE_H

#if defined(EFM32ZG108F16)
#include "efm32zg108f16.h"

#elif defined(EFM32ZG108F32)
#include "efm32zg108f32.h"

#elif defined(EFM32ZG108F4)
#include "efm32zg108f4.h"

#elif defined(EFM32ZG108F8)
#include "efm32zg108f8.h"

#elif defined(EFM32ZG110F16)
#include "efm32zg110f16.h"

#elif defined(EFM32ZG110F32)
#include "efm32zg110f32.h"

#elif defined(EFM32ZG110F4)
#include "efm32zg110f4.h"

#elif defined(EFM32ZG110F8)
#include "efm32zg110f8.h"

#elif defined(EFM32ZG210F16)
#include "efm32zg210f16.h"

#elif defined(EFM32ZG210F32)
#include "efm32zg210f32.h"

#elif defined(EFM32ZG210F4)
#include "efm32zg210f4.h"

#elif defined(EFM32ZG210F8)
#include "efm32zg210f8.h"

#elif defined(EFM32ZG222F16)
#include "efm32zg222f16.h"

#elif defined(EFM32ZG222F32)
#include "efm32zg222f32.h"

#elif defined(EFM32ZG222F4)
#include "efm32zg222f4.h"

#elif defined(EFM32ZG222F8)
#include "efm32zg222f8.h"

#else
#error "em_device.h: PART NUMBER undefined"
#endif
#endif /* EM_DEVICE_H */
