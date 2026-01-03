import pytesseract, cv2, keyboard
from serial_ctl import Arduino

arduino = Arduino(port="COM4")

print("F8 to toggle light - Esc to Exit")

keyboard.add_hotkey("l", arduino.toggle)
keyboard.wait('esc')

arduino.close()