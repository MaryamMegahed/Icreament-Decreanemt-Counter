/*
 * seven_segment.h
 *
 *  Created on: May 24, 2023
 *      Author: marya
 */

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "Std_Types.h"

 void config_seven_segment(uint8 PortName, uint8 first_PinNum, uint8 last_PinNum);
 void seven_segment_output(uint8 PortName, uint8 first_PinNum,uint8 counter);


#endif /* SEVEN_SEGMENT_H_ */
