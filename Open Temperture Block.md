<p align="center">
<img src="/Images/Open_Temperture_Block.png" width="300">
</p>

# Open Temperture Block

_**TL;DR**_ This guide shows the process for engineering, fabrication and operating of the OTB (Open Temperature Block).  The OTB is a bench tool for controlling the temperature of DIY biological experiments to include and not limited to PCR, heat shock, hibernation, and incubation.  


###Background




##Engineering Design Process

	1.	Define the Problem: 

The goal is to create a DIY, open source, heating and cooling device for the use in biological experiments.  The DIY portion of this device will be assembled using basic tools. Being open source allows for revision, evolution, and free dissemination.  The heating control will allow for PCR reactions, heat shock experiments, incubation, and hibernation.

	2.	Identify Constraints: 

| Name | Parameters |
| ----- | -----|
| Size | Microplate footprint (127.76 mm x 85.48 mm)|
| Weight | For shipping lighter is better |
| Cost | < $1000 USD (Competitor range: $900 <-> $20K, Average $5k )
| Power | 120VAC and 240VAC input
| Temperture Range |  ≤ 3°C to ≥ 100°C for a duration of < 30 Minutes |
|Componets| Readily sourced; electronics, hardware, microcontroller|
| Decibles | 60 decibels
| Water Tight | Does not leak
| Geometry | Rectangular
| Cleanability | Allows for cleaning.
| Assembly | Uses standard hex screws.

	3.	Brainstorm: 
  | Idea | Pro | Con |
  | ----- | -----| ----- |
  |Peltier (TEC)| Cost effective, heats and cools, small size| Uses a lot of power to remove heat.
  |Heat Element| Cost effective, any size filament|  Doesn't cool
  |Compressor heat exchanger|Power Efficient|Expensive, Slow, not DIY.

	4.	Select promising solution: 

The engineered solution will use a Thermal Electric Cooler (TEC) and a heat exchanger.  To create the OTB there will be three systems; power, data, heat.


<img src="/Images/TEC_function.gif">

The OTB is powered by 12V `17AMP` power supply. This will power the Peltier, fans, pump, and microcontroller.

The OTB data system is broken into device logic, and external control. Device logic describes the microcontroller interaction with the Peltier, Temperature Probes, input devices. To accurately control the Peltier the microcontroller supplies a PWM signal to the high-power motor controller. This will change the electrical duty cycle allowing for precise Peltier control. The microcontroller samples temperatures from two thermistors.  One thermistor is located on the heat block and the other is attached to the heat exchanger.  These values will provide the logic needed to safely control the heat and cooling operations. External control consists of an I2C slave data line, display with buttons, and Wifi. The I2C data line allows for sending and receiving data from a Master I2C device. The display consists of an OLED display, and four buttons.  The OLED in conjunction with the buttons allows the user to navigate through menus, and execute functions. Lastly, the Wifi provides a wireless gateway to Communicate with the OTB via web page and RESTapi.

The heat system consist of a Peltier, water block, pump, fan, and radiator.  In the heating phase, the microcontroller sends positive voltage to the Peltier.  In the cooling phase, the microcontroller sends a negative voltage to the Peltier.  Durning all heating and cooling operations the pump is moving water through the water block, through tubing, to the radiator and back to the water block.  The radiator uses an electric fan to blow air over the fins an exchange heat to the environment.

MATH:

Sketch:

	5.	Prototype 
### Temperture Block
<img src="/Images/Open_Temperture_Block.png" width="300">

### Heat Exchanger and Power Train
<img src="/Images/OTC_Heat_Exchanger.png" width="300">




	6.	Test 


	7.	Iterate 


	8.	Communicate Results. 



### Support Websites
[Buy Open Soruce Open_Temperture_Block](https://www.celleleven.com/product/Open_Temperture_Block/)

[Wikipedia](https://en.wikipedia.org/wiki/Michaelis%E2%80%93Menten_kinetics)

[Background Experiment](https://user.eng.umd.edu/~nsw/ench485/lab14.htm)


## Hardware
| QTY | Name | Quanity | Cost | Item Cost | Total Cost | URL |
| --- | --- | --- | --- | --- | --- | --- |
| 6 | Peltier | 10 | 28.99 | 2.899 | 17.394 | https://amzn.to/3pDVF7H |
| 2 | 120x40 Water Cooling Block | 2 | 18.99 | 9.495 | 18.99 | https://amzn.to/3pyl8zk |
| 1 | 96 Well Aluminum Block | 1 | 169.13 | 169.13 | 169.13 | https://amzn.to/3DyzIvE |
| 1 | 24 Well Aluminum Block | 1 | 71.89 | 71.89 | 71.89 | https://amzn.to/3dthdhx |
| 1 | 384 Well Aluminum Block | 1 | 0 | 0 | 0 |  |
| 3 | Thermistors | 10 | 13.99 | 1.399 | 4.197 | https://amzn.to/3IsNvaJ |
| 1 | Wifi Microcontroller | 1 | 44.61 | 44.61 | 44.61 | https://amzn.to/3lIX8YV |
| 1 | 240x360 Radator | 1 | 29.99 | 29.99 | 29.99 | https://amzn.to/3duD08s |
| 3 | 120 Fan | 4 | 17.99 | 4.4975 | 13.4925 | https://amzn.to/2LkDNhD |
| 1 | 2 Relay Module | 4 | 8.99 | 2.2475 | 2.2475 | https://amzn.to/3rHmMkP |
| 6 | Vinyl Tubbing | 50 | 26.99 | 0.5398 | 3.24| https://amzn.to/3pyTouq |
| 8 | Hose clamps | 25 | 10 | 0.4 | 3.2 | https://amzn.to/3lLbY14 |
| 1 | Pump | 1 | 37.79 | 37.79 | 37.79 | https://amzn.to/3y0tPpT |
| 1 | Power Supply | 1 | 28.99 | 28.99 | 28.99 | https://amzn.to/3dsQ0LN |
| 0 | Stand Offs | 1 | 0 | 0 | 0 |  |
| 1 | Case | 1 | 60 | 60 | 60 |  |
| 6 | 12G Copper wire | 25 | 36.66 | 1.4664 | 8.80 | https://amzn.to/3lL9YpA |
| 4 | G1/4 Thread Soft Tube Barb | 6 | 11.15 | 1.86 | 7.43 | https://amzn.to/3pxsC5G |
| 1 | Ardunio PCB Board | 1 | 10.99 | 10.99 | 10.99 | https://amzn.to/3pyTouq |
| 1 | Real Time Clock (RTC) | 5 | 17.49 | 3.50 | 3.50 | https://amzn.to/3IfnBqF |
| 1 | DC-DC Buck | 1 | 30 | 30 | 30 | https://amzn.to/3Gn74iR |

 **Total** $565.88


## Assembly
### Software

<img scr="Images/OTB_PCR_SeqDia.svg">

1. [Download Arduino IDE](https://www.arduino.cc/en/main/software)
2. Download this Zip File to your computer
3. Navigate to the ``Open_Temperture_Block Code`` folder
4. Upload Polariemter Code to Arduino

### Electronics
1. Solder wires and components onto Arduino Sheild PCB
2. Solder OLED, (4) Buttons, Wires, and JST-XHP connector to PCB
<img src="/Images/OTB_Electronics_Prototype01.jpg" width="500">

### Case
1. [Laser Cut or 3D Print Frame gcode](https://www.thingiverse.com/thing:4484626) <br>Roof<br>Base<br>Spine<br>Rib<br>Wall-Right<br>Wall-Left<br>Dash<br>Dash Stands x 2 <br> Cooling Block Top <br> Cooling Block Bottom<br>Buttons

### Hardware
1. Add Arduino to base with screws
2. Attach Sheild to Arduino
3. Fit RJ-11 Plug into Wall-Right hole and screw in T-slots
4. Connect wires to JST-XHP connectors
5. Add Fan to rib with screws

<img src="/Images/fan_diagram.png" width="300">

6. Attach rib to Wall-Right
7. Snake wires through the rib
8.  Attach 28BYJ-48 Stepper driver and motor to spine
9. Add Wall-Left and screw in T-slots
10. Connect JST-XHP wires to 29BYJ-48 Stepper
11. Snake wires through the spine
12. Assemble Cooling Block
13. Attach Colling Block to Rib
14. Add Roof and screw in T-Slots
15. 16. Assemble the DashBoard
16. Attach the remaining wire to the DashBoard
17. Attach DashBoard to Roof and screw in T-slots
18. Power On



## Directions
#### Get Solution Rotation Angle
1. Plug-in Device
2. Loading Splash will run on OLED Screen
3. Remove Cuvet and allow for calibration
4. Add solution to Cuvet and place in Open_Temperture_Block
5. Click the button that reads "Run Sample"

####  Get Michaelis-Menton Rate
1. Plug-in Device
2. Loading Splash will run on OLED Screen
3. Remove Cuvet and allow for calibration
4. Add solution to Cuvet and place in Open_Temperture_Block
5. Click the button that reads "Michaelis-Menton Kinetics"


## Trouble Shooting
1. Recalibrate
2. Go to settings and change EPROMS calibration values

## Authors

* **[S James Parsons Jr](https://www.linkedin.com/in/sjamesparsonsjr/)**

## Purchase
[![Donation](https://i1.wp.com/calumetartcenter.com/wp-content/uploads/2013/02/paypal-buy-now-button.png?fit=284%2C136&ssl=1)](https://i1.wp.com/calumetartcenter.com/wp-content/uploads/2013/02/paypal-buy-now-button.png?fit=284%2C136&ssl=1)



## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details





##Fabrication

Electronics

Wire Arduino Uno with dashboard circuit, RJ11 port, two thermistors, ~~Ultra sonic Sensor~~ BTS7960, fan, and water pump.

Wire Peltier's to DTS7960 and 12VAC power supply to circuit.

Physically validate wires are correctly installed using a voltmeter to verify continuity.  

If no shorts, power the circuit.

Physically validate wires contain the correct voltage using the voltmeter starting at the source.

Power down circuit.

Coding

1. Using Arduino IDE / Wokwi.com, install all libraries, define all pin variables, initialize starting variable with values. Install dash and I2C functions.

2. Code the setup script. Debug any errors.

3. Code the thermistor function. Debug any errors. Upload to Arduino and calibrate.  Repeat previous steps for second thermistor.   

4. Code the DTS7960 function. Debug any errors.

5. Code the fan function.

6. Code the Pump



Heating Block

1. 3D Print Mockups holder.
2. Fabricate heat transfer plate; Mark dimensions, oil, cut, clean, and deburr.
3. Tape plates together, drill and tap four 4mm holes for screws, deburr, and clean.
4. Assemble block by stacking bottom plate, water block, Peltier, and top plate and screwing together, being cautious not to crack the TEC units.  **NOTE: Should I use Thermal Paste?**
5. Attach plastic tubbing.  Using a razor blade cut two long pieces of PVC tubing (xx mm) length and 1 short piece of PVC tubing (xx mm) in length. Attach short piece on the inner two barbs of the heating block. **NOTE: Do this before assmeby, unless barbs are easy to access**
6. Wire management, using zip ties align the Peltier wires in the same direction as the PVC tubes.
7. Tin TEC wires and power wires.  Add heat shrink to all TEC wires. Crimp on ring connectors to 12 TEC wires and two power wires.  Connect all rings using nut and bolt. Heat shrink terminal junction.














#NOTE
**Material**
Melting	Conductivity
Aluminum 1221  239
Lead 621.5 34.7
Steel 2500 45
Copper 1984 397
Bismuth 520 7.97
PLA	180 0.13
Gallium 29.7 40.6










100.
