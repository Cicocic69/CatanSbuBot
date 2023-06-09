# port name ttyACM0
import serial, time

if __name__ == '__main__':
    
    print('Running. Press CTRL-C to exit.')
    #
    #connessione Arduino-RPi tramite pota USB
    #
    with serial.Serial("/dev/ttyACM0", 9600, timeout=1) as arduino:
        time.sleep(0.1) # wait for serial to open
        if arduino.isOpen():
            print("{} connected!".format(arduino.port))
            try:
                while(True):
                    cmd = input("Enter command: ")
                    arduino.write(cmd.encode())
            
            except KeyboardInterrupt:
                print("KeyboardInterrupt has been caught.") 