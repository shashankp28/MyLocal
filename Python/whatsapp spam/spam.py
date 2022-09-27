import pyautogui
import time

words = open('word.txt', 'r+')
time.sleep(5)

for word in words:
    pyautogui.typewrite('hi')
    pyautogui.press('enter')
    # time.sleep(0.000002)
