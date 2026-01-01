import serial, time

class Arduino:
    def __init__(self, port, baud = 9600):
        self.ser = serial.Serial(port, baud, timeout = 1)
        time.sleep(2)

    def toggle(self):
        self.ser.write(b"T")

    def close(self):
        self.ser.close()