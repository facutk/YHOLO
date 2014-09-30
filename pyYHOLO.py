import serial
#import random
import time

text = """
  **   **    
 **** ****   
***********  
  *******    
   *****     
     *       
"""




text = """
**     **  **   **    ***    **         ***     
 **   **   **   **   ** **   **        ** **    
  ** **    *******  **   **  **       **   **   
   ***     *******  **   **  **       **   **   
   ***     **   **   ** **   *******   ** **    
   ***     **   **    ***    *******    ***     
"""

text = text.splitlines()

m = []
text.pop(0)
for line in text:
    l = []
    for char in line:
        symbol = 1
        if char == ' ':
            symbol = 0
        l.append( symbol )
    m.append(l)

t = []
for k in range( len( m[0] ) ):
    col = []
    for j in range( len(m) ):
        col.append( m[j][k] )
    t.append( col )

seq = []
for col in t:
    x = [ str(n) for n in col ]
    string_num = ''.join( x )
    string_num = string_num[::-1]
    num = int( string_num, 2 )
    seq.append( num )

rev_seq = seq[::-1]
front_back = seq + rev_seq
print front_back
#exit()

ser = serial.Serial('/dev/ttyUSB0', 9600)

delay = 10000/1000000.0

time.sleep(delay)

def send_value( value ):
    char = str( chr( value ) )
    ser.write( char )

send_value( 0 )
exit()

while True:
    #value = int( random.random() * 64 )
    for value in front_back:
        send_value( value )
        print value
        time.sleep(delay)
