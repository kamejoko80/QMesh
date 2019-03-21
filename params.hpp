/*
 * Copyright (c) 2019, Daniel R. Fay.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PARAMS_HPP
#define PARAMS_HPP

// Defines key parameters

// Frame parameters
#define FRAME_PAYLOAD_LEN 32

// Radio parameters
#define RADIO_INVERT_IQ false
#define RADIO_HOP_PERIOD 1
#define RADIO_FREQ_HOP false
#define RADIO_CRC_ON true
#define RADIO_FIXED_LEN true
#define RADIO_SYM_TIMEOUT 12
#define RADIO_PREAMBLE_LEN 12
// 0: 125 kHz, 1: 250 kHz, 2: 500 kHz, 3: Reserved
#define RADIO_BANDWIDTH 2
#define RADIO_SF 9
// 1: 4/5, 2: 4/6, 3: 4/7, 4: 4/8
#define RADIO_CODERATE 1
// Tx power, in mW
#define RADIO_POWER 1
// Transmit timeout, in ms
#define RADIO_TX_TIMEOUT 1000
#define RADIO_FREQUENCY 915000000
// Amount of padding between frames, in ms
#define FRAME_PADDING_MS 5
// Number of past packets to check the current packet against
#define PKT_CHK_HISTORY 32

#endif /* PARAMS_HP */