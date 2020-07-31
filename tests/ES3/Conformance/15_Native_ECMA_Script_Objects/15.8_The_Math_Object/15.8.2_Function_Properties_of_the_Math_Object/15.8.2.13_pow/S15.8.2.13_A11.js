// Copyright 2009 the Sputnik authors.  All rights reserved.
// This code is governed by the BSD license found in the LICENSE file.

/**
 * @name: S15.8.2.13_A11;
 * @section: 15.8.2.13;
 * @assertion: If x is +Infinity and y>0, Math.pow(x,y) is +Infinity;
 * @description: Checking if Math.pow(x,y) equals to +Infinity, where x is +Infinity and y>0;
 */
 
// CHECK#1

x = +Infinity;
y = new Array();
y[3] = Infinity;
y[2] = 1.7976931348623157E308; //largest (by module) finite number
y[1] = 1;
y[0] = 0.000000000000001;
ynum = 4;

for (i = 0; i < ynum; i++)
{
	if (Math.pow(x,y[i]) !== +Infinity)
	{
		$ERROR("#1: Math.pow(" + x + ", " + y[i] + ") !== +Infinity");
	}
}
