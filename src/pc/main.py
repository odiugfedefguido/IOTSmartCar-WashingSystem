import sys

from communication.serial_service import SerialService
from gui.dashboard import Dashboard

print("Booting …\n")
if (len(sys.argv) != 2):
    print("No port specified!\nUsage: python3 main.py <SERIALPORT>\nThe following ports are available:\n")
    print(SerialService.serial_ports())
else:
    Dashboard(sys.argv[1])
