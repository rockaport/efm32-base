/***************************************************************************//**
 * @file
 * @brief Provide stdio retargeting configuration parameters.
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef __SILICON_LABS_RETARGETSERIALCONFIG_H__
#define __SILICON_LABS_RETARGETSERIALCONFIG_H__

#include "bsp.h"

/***************************************************************************//**
 *
 * When retargeting serial output the user can choose which peripheral
 * to use as the serial output device. This choice is made by configuring
 * one or more of the following defines: RETARGET_USART0, RETARGET_LEUART0,
 * RETARGET_VCOM.
 *
 * This table shows the supported configurations and the resulting serial
 * output device.
 *
 * +----------------------------------------------------------------------+
 * | Defines                            | Serial Output (Locations)       |
 * |----------------------------------------------------------------------+
 * | None                               | USART0 (Rx #18, Tx #18)         |
 * | RETARGET_USART0                    | USART0 (Rx #18, Tx #18)         |
 * | RETARGET_VCOM                      | VCOM using USART0 #0            |
 * | RETARGET_LEUART0                   | LEUART0 (Rx #18, Tx #18)        |
 * | RETARGET_LEUART0 and RETARGET_VCOM | VCOM using LEUART0              |
 * +----------------------------------------------------------------------+
 *
 * Note that the default configuration is the same as RETARGET_USART0.
 *
 ******************************************************************************/

#if !defined(RETARGET_USART0) \
  && !defined(RETARGET_LEUART0)
#define RETARGET_USART0    /* Use USART0 by default. */
#endif

#if defined(RETARGET_USART0)
  #define RETARGET_IRQ_NAME    USART0_RX_IRQHandler         /* UART IRQ Handler */
  #define RETARGET_CLK         cmuClock_USART0              /* HFPER Clock */
  #define RETARGET_IRQn        USART0_RX_IRQn               /* IRQ number */
  #define RETARGET_UART        USART0                       /* UART instance */
  #define RETARGET_TX          USART_Tx                     /* Set TX to USART_Tx */
  #define RETARGET_RX          USART_Rx                     /* Set RX to USART_Rx */
  #define RETARGET_TX_LOCATION _USART_ROUTELOC0_TXLOC_LOC18 /* Location of of USART TX pin */
  #define RETARGET_RX_LOCATION _USART_ROUTELOC0_RXLOC_LOC18 /* Location of of USART RX pin */
  #define RETARGET_TXPORT      gpioPortD                    /* UART transmission port */
  #define RETARGET_TXPIN       10                           /* UART transmission pin */
  #define RETARGET_RXPORT      gpioPortD                    /* UART reception port */
  #define RETARGET_RXPIN       11                           /* UART reception pin */
  #define RETARGET_USART       1                            /* Includes em_usart.h */

#elif defined(RETARGET_LEUART0)
  #define RETARGET_IRQ_NAME    LEUART0_IRQHandler           /* LEUART IRQ Handler */
  #define RETARGET_CLK         cmuClock_LEUART0             /* HFPER Clock */
  #define RETARGET_IRQn        LEUART0_IRQn                 /* IRQ number */
  #define RETARGET_UART        LEUART0                      /* LEUART instance */
  #define RETARGET_TX          LEUART_Tx                    /* Set TX to LEUART_Tx */
  #define RETARGET_RX          LEUART_Rx                    /* Set RX to LEUART_Rx */
  #define RETARGET_TX_LOCATION _LEUART_ROUTELOC0_TXLOC_LOC18/* Location of of LEUART TX pin */
  #define RETARGET_RX_LOCATION _LEUART_ROUTELOC0_RXLOC_LOC18/* Location of of LEUART RX pin */
  #define RETARGET_TXPORT      gpioPortD                    /* LEUART transmission port */
  #define RETARGET_TXPIN       10                           /* LEUART transmission pin */
  #define RETARGET_RXPORT      gpioPortD                    /* LEUART reception port */
  #define RETARGET_RXPIN       11                           /* LEUART reception pin */
  #define RETARGET_LEUART      1                            /* Includes em_leuart.h */

#else
#error "Illegal USART selection."
#endif

#if defined(RETARGET_VCOM)
  #define RETARGET_PERIPHERAL_ENABLE() \
  GPIO_PinModeSet(BSP_BCC_ENABLE_PORT, \
                  BSP_BCC_ENABLE_PIN,  \
                  gpioModePushPull,    \
                  1);
  #if defined(RETARGET_USART0)
    #undef RETARGET_TX_LOCATION
    #undef RETARGET_RX_LOCATION
    #undef RETARGET_TXPORT
    #undef RETARGET_TXPIN
    #undef RETARGET_RXPORT
    #undef RETARGET_RXPIN
    #define RETARGET_TX_LOCATION _USART_ROUTELOC0_TXLOC_LOC0 /* Location of of USART TX pin */
    #define RETARGET_RX_LOCATION _USART_ROUTELOC0_RXLOC_LOC0 /* Location of of USART RX pin */
    #define RETARGET_TXPORT      gpioPortA                   /* UART transmission port */
    #define RETARGET_TXPIN       0                           /* UART transmission pin */
    #define RETARGET_RXPORT      gpioPortA                   /* UART reception port */
    #define RETARGET_RXPIN       1                           /* UART reception pin */
  #endif
#else
  #define RETARGET_PERIPHERAL_ENABLE()
#endif

#endif
