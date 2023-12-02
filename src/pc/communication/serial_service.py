import serial 
import sys
import glob

class SerialService:
    def __init__(self, port):
        self.board = serial.Serial(port=port, baudrate=9600, timeout=.1) 

    def write(self, text):
        self.board.write(bytes(text, 'utf-8')) 

    def read(self):
        return self.board.readline() 

    @staticmethod
    def serial_ports():
        """ Lists serial port names
            Reference: https://stackoverflow.com/questions/12090503/listing-available-com-ports-with-python#14224477

            :raises EnvironmentError:
                On unsupported or unknown platforms
            :returns:
                A list of the serial ports available on the system
        """
        if sys.platform.startswith('win'):
            ports = ['COM%s' % (i + 1) for i in range(256)]
        elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
            # this excludes your current terminal "/dev/tty"
            ports = glob.glob('/dev/tty[A-Za-z]*')
        elif sys.platform.startswith('darwin'):
            ports = glob.glob('/dev/tty.*')
        else:
            raise EnvironmentError('Unsupported platform')

        result = []
        for port in ports:
            try:
                s = serial.Serial(port)
                s.close()
                result.append(port)
            except (OSError, serial.SerialException):
                pass
        return result

        
    