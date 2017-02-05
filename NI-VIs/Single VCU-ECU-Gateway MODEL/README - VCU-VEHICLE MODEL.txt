Basic (FPGA) CAN Engine .vi
-Implements the reasing and transmision of messages(frames) accross the CAN bus.

Log from Network.vi
- reads data from the network stream set up by the 'Stream to Network.vi' and logs it to file

Position_speed.vi
- 'VEHICLE MODEL' algoritham

Read from Network.vi
- reads data from the network stream set up by the 'Stream to Network.vi' and displayes to screen.

Stream to Network.vi
- streams data coming in on CAN1 of the NI9853 module to the network.

VCU MODEL CAN0.vi
- VCU model implemented using the 'Basic (FPGA) CAN Engine .vi' on CAN0 of the NI9853 module

VEHICLE MODEL CAN1.vi 
- Vehicle model model implemented using the 'Basic (FPGA) CAN Engine .vi' on CAN1 of the NI9853 module