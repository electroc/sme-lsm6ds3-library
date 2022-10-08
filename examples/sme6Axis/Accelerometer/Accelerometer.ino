 /*
 * Accelerometer.ino
 *
 *  Created on: 29/09/2016 23:02:00
 * by Zero-2 (Zero2sat@gmail.com)
 * 
 * License Information
 * -------------------
 *
 * Copyright (c) Axel Elettronica Srl. All right reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <Arduino.h>
#include "SME_LSM6DS3.h"
#include "Wire.h"

void setup() {
    Wire.begin();
    Serial.begin(115200);    
    while(!Serial){};
	accelerometer.begin();
	if(accelerometer.isActive()){
		Serial.println("Accelerometer already active");
	}else{
		if(accelerometer.powerOn()){
			Serial.println("Accelerometer Power ON");
		}else{
			Serial.println("Accelerometer Not Powered On");
		}
	}
 
	 accelerometer.changeFullScale(XL_FS_2G);   // default most values
	 //accelerometer.changeFullScale(XL_FS_4G);
	 //accelerometer.changeFullScale(XL_FS_8G);
	 //accelerometer.changeFullScale(XL_FS_16G);    // least values

	 //accelerometer.changeOutputDataRate(POWER_12_5_HZ);
	 //accelerometer.changeOutputDataRate(POWER_26_HZ);
	 //accelerometer.changeOutputDataRate(POWER_52_HZ);
	 //accelerometer.changeOutputDataRate(POWER_104_HZ);    //default
	 //accelerometer.changeOutputDataRate(POWER_208_HZ);
	 //accelerometer.changeOutputDataRate(POWER_416_HZ);
	 accelerometer.changeOutputDataRate(POWER_833_HZ);
	 //accelerometer.changeOutputDataRate(POWER_1_66_KHZ);
	 //accelerometer.changeOutputDataRate(POWER_3_33_KHZ);
	 //accelerometer.changeOutputDataRate(POWER_6_66_KHZ);

	 //accelerometer.changeBandwidth(XL_Band_50Hz);
	 //accelerometer.changeBandwidth(XL_Band_100Hz);
	 //accelerometer.changeBandwidth(XL_Band_200Hz);
	 accelerometer.changeBandwidth(XL_Band_400Hz);  // default

	 //accelerometer.changeOperatingMode(XL_HM_Normal);
	 accelerometer.changeOperatingMode(XL_HM_High_Performance); // default
 
}

void loop() {
    //Serial.println("++++++++++++++++++++++++++++++++++++++++");
    //Serial.println("Accelerometer Values ");
    Serial.print("Raw  X = ");
    Serial.print(accelerometer.getRawXAxis());
    Serial.print(" Y = ");
    Serial.print(accelerometer.getRawYAxis());
    Serial.print(" Z = ");
    Serial.println(accelerometer.getRawZAxis());
    /*
    Serial.print("X = ");
    Serial.print(accelerometer.getConvertedXAxis(), 2);
    Serial.print("g  Y = ");
    Serial.print(accelerometer.getConvertedYAxis(), 2);
    Serial.print("g  Z = ");
    Serial.print(accelerometer.getConvertedZAxis(), 2);
    Serial.println("g");
    Serial.println("++++++++++++++++++++++++++++++++++++++++");
     * 
     */
    //delay(100);
}
