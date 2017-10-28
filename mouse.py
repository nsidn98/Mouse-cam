import serial
import re
import time
import pyautogui
pyautogui.FAILSAFE = False 

ser =serial.Serial('/dev/cu.usbmodem1421',9600,timeout=None) #change it according to your port
x=0
y=0
i=0
while 1:
	i+=1
	try:
		a=ser.readline()
		c=a.decode('ASCII')

		#time.sleep(0.01)
	except ser.SerialTimeoutException:
		print('Data could not be read')
		time.sleep(1)
	b=c.split()
	print(b)
	
	if(i<3):
		continue
	else:
		if(len(b)==2):
			x=int(b[0])
			y=int(b[1])
		elif(len(b)==3):				
			'''if len(b==3)  b=[button_click,x,y]  button_click='a','b'
			'a'=left-click
			'b'=right-click'''
			if b[0]=='a':
				pyautogui.click(button='left')
			elif b[0]=='b':
				pyautogui.click(button='right')
		elif(len(b)==4):
			'''b=[scroll_button,x,y,scroll_amount]
			'c'=vertical scroll
			'd'=horizontal scroll'''
			scroll_amount=int(b[3])
			if(b[0]=='c'):
				pyautogui.scroll(scroll_amount)
			elif(b[0]=='d'):
				pyautogui.hscroll(scroll_amount)

	pyautogui.moveRel(x,y,duration=0)
	
					




			

