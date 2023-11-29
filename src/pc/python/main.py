import sys
from communication.serial_service import SerialService

PORT = None
arduino = None

def main():
    arduino = SerialService()
    while True:
        print(arduino.read())

print("Booting …\n")
if (len(sys.argv) != 2):
    print("No port specified!\nUsage: python3 main.py <SERIALPORT>\nThe following ports are available:\n")
    print(SerialService.serial_ports())
else:
    PORT = sys.argv[1]
    main()
