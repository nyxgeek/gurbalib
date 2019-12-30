# Introduction
Inside woodland critter christmas there is a directory for generating automatic LPC files, it is designed to be customized per domain or area.

# Example
```
/domains/woodland/gen
```

## exits
the exists file is a list of each room and its associated exits, the file looks like this
```
1_2:w,se:
3_2:sw,se,ne:
4_1:sw,e:
5_1:w,s,e:
6_1:w,se:
5_2:n,s:
7_2:nw,sw,e:
```

### room name
The first entry in a line on the file is the room name in the form of numeric co-ordinates, x_y, this has to be setup this way or else map.py will not handle the exit linking correctly

### exits
a comma separated list of exits is next

### remaining fields
the remaining fields are unused and map.py could be modified to take hidden exits or specific room descriptions or other attributes

### It is important to make a complete grid map before moving on to the next step, and then mape the exits file

## map.py
map.py is the actual lpc generator, it is designed to be run off a map file. The map file lists the room and exists attached to that room.

