/*
 * FreeRTOS+TCP <DEVELOPMENT BRANCH>
 * Copyright (C) 2022 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

#ifndef FREERTOS_IP_CONFIG_H
#define FREERTOS_IP_CONFIG_H

/* Define the byte order of the target MCU */
#define ipconfigBYTE_ORDER pdFREERTOS_LITTLE_ENDIAN

/* Enable DHCP */
#define ipconfigUSE_DHCP 1

/* Enable DNS */
#define ipconfigUSE_DNS 1
#define ipconfigDNS_CACHE_ENTRIES 4

/* Enable ARP */
#define ipconfigUSE_ARP 1
#define ipconfigARP_CACHE_ENTRIES 10

/* Enable TCP */
#define ipconfigUSE_TCP 1
#define ipconfigTCP_MSS 1460
#define ipconfigTCP_KEEP_ALIVE 1

/* Enable UDP */
#define ipconfigUDP_TIME_TO_LIVE 64

#endif /* FREERTOS_IP_CONFIG_H */