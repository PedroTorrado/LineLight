<img src="https://github.com/PedroTorrado/LineLight/blob/main/Images/Line_Light_LOGO_v2.png" alt="Logo" width="100"/>

# LineLight

## Introduction

This project was created with the objective of creating a safer environment for all means of transport and vehicles in the streets.

This should be accomplished by having a device that helps drivers of means of transportation without turn signals (blinkers), 
through the use of LEDs controlled by the user which will signal the intention of the user to turn or to change lanes.

A big part of traffic safety or road safety is good communication between the drivers of all the different vehicles and/or means of transportation. This "good communication" means only, communication made in a way that everybody can easily and quickly realize the intentions of the drivers around them, so they can make the best decisions to keep the other drivers and themselves as safe as possible.

However, in our day to day, we constantly come across vehicles that do not have light signals, which makes its ways of signalling a lot less clear and safe (especially in darkened environments such as tunnels and during the night). And that's why this project has been created, so that, those types of means of transportation have a good and feature full way of coexisting in the streets with all other vehicles and/or means of transportation.

---

## Objectives

The device, apart from it's basic functionality should be:

  1. Compact and storable when not in use;
  
  2. Usable with various types of transport:
  
    -Bicycle;
    -Skateboard;
    -Scooter; 
    -etc.
    (And electric variants of the same)
    
  3. Intuitive to use;
  
  4. Alerts the user in case the action intended to signal doesn't work as intended;
  
  5. Resistance to harsh environments;
  
  6. Aesthetic and discrete;
  
  7. Easy to repair without full replacement;
  
---

To complete all these objectives, various functionalities are required to implement, such as,
wireless communication between a controller (Transmitter) and the main device (Reciever), which I called Controller and MainBoard throughout my files. (Objectives 1, 2 and 3)

---

For the 4th objective to be reached it's important that the components are able to have bidirectional communication so that once a signal is sent by the transmitter, the receiver can send a  signal back confirming it is working as intended.

<img src="https://github.com/PedroTorrado/LineLight/blob/main/Images/Bidirectional%20communication.png?raw=true" alt="drawing" width="700"/>

Caption:

  1. An action is taken on the controller by the user creating a signal;
  2. That signal is sent to the MainBoard;
  3. The Board acts as intended by the user;
  4. A signal is sent by the MainBoard;
  5. The controller confirms to the user that the board is acting as intended. 
  
But why is this function so important? Well, let's imagine for a moment a scenario where the user sends a signal to the MainBoard thinking he is signalling the vehicles around him that he is going to turn, and for some (exceptional) reason the MainBoard doesn't receive the signal, however, the user acts thinking that it did and that the drivers around him are aware that he is going to take his turn. The user is put in a very dangerous situation, way more dangerous than if he just used hand signs to signal the drivers around him. 

This way, by having a way to check if his signal has created the action he intended to, he can make his turn way more safely and be aware in case it doesn't so he can still use hand gestures to aware the drivers around him of his intentions (to turn in this case).

---

Briefly, the 5th objective is hinting at the importance that the device is not only well constructed but also (and very importantly) water-resistant because this device is supposed to be used outside while riding no matter the weather, and the worst the weather the more important that a device like this works flawlessly. Therefore it's really important to make sure that the device is made in a way that prevents water to enter into contact with the contacts from the PCB and with the battery itself. Since this is also related to the use and feel of the final device this is also related to the 6th objective. 

---

The 7th and last objective (to be defined by now), is related to the reparation of the device in case something is no longer functional, for this the device should be made modular so that in case some part of it breaks it's possible (and) easy to replace it and therefore fix the device.
