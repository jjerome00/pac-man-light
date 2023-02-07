# Pac Man Light

This is a simple hack of a Paladone "Pac Man and Ghosts" Light.

example:
https://www.amazon.com/Pac-Man-Ghosts-Light-USA/dp/B0851Y4314

This is overkill, but I push my hardware code up to github as a backup. Maybe you'll find something useful here.

## Default Operation (before modication)

The light operates on a single press button.

Button Press Cycle:
0. Device has power, but no lights on (i.e. "off")
1. all lights light up
2. ghosts chase pac man
3. lights up according to sound in room (like an equalizer)

If device loses power, the state is lost. 
You must press the button for device to activate again.

## Physcial Modifications

1. I cut the wires coming from USB power:
    - from USB: connect to Arduino Pins GND + VIN
    - from Arduino: GND + Pin D2 provides power to the original device
    - I essentially introduced the Arduino between the existing power between the usb power & the device
2. Connected Ardunio Pin D9 to one pins of the physical button
    - I set Pin D9 to LOW and it triggers a button press

The device now runs directly off main (USB) power (not battery).
I have it attached to a motion detector switch.

## Code behavior

Very simple.

1. Arduino receives power and activates
2. Arduino provides power to the light - [mode 0] light receives power but  still remain off
3. Arduino "presses" button - [mode 1] All Lights turn on
4. Arduino "presses" button - [mode 2] ghosts chase Pac Man
5. We're done. Light continues in mode 2

When power is cut off, everything turns off. No problem.
When power is on, restarts at step 1

## Real world stuff

I have an aquarium with a light that is attached to a motion control. When someone walks by the light turns on for ~5 minutes. I attached this light to the same system.

I used an Ardiuno Nano, which hover around $5 - $8 dollars
I soldered my wires, somtimes poorly

The physically button can still work with this setup, but there isn't much use for it.
I may add a physical switch at some point so that I can turn off the light if it's plugged in.










