G21
G90 ;absolute positioning
M82 ;set extruder to absolute mode
M107 ;start with the fan off
G28
G29
G1 Z15.0 F9000 ;move the platform down 15mm
G92 E0 ;zero the extruded length
G1 F200 E15 ;extrude 15mm of feed stock
G92 E0 ;zero the extruded length again
G1 F9000 ; Put printing message on LCD screen
M 117 Printing...
