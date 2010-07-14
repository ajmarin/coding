'''
# Mastermind
#
# Author: Alexandre Marin
# Version: 1.0
# This software is in the public domain. No copyright is claimed, and you
# may use it for any purpose without license.
# No warranty for any purpose is expressed or implied by the author of
# this software.
'''
 
import appuifw
from graphics import *
import e32
import key_codes #import key_codes - required for touch event detection
import math
import random
import sys
# disable directional pad
appuifw.app.directional_pad = False

class Mastermind:
	
	def __init__(self):
		self.canvas = appuifw.Canvas(redraw_callback=self.handle_redraw)
		Total_x, Total_y = self.canvas.size
		self.cdraw = Draw(self.canvas)
		appuifw.app.body = self.canvas
		self.backup_img=Image.new((Total_x, Total_y))
		self._draw = Draw(self.backup_img)
		self.gcnt = 0
		self.gcol = 0
		self.gr = 25
		self.NOC = 6
		self.cnames = [ u"red", u"green", u"blue", 
						u"yellow", u"purple", u"black" ]
		self.g = [[self.NOC, self.NOC, self.NOC, self.NOC]] * 9
		self.colors = [ 0xff0000, 0x00c000, 0x0000ff,
						0xff9900, 0xcc0099, 0x000000, 0xffffff]
		self.c = [(0, 0)] * self.NOC
		self.rect = [((0,0), (0,0))] * self.NOC		
		appuifw.body = self._draw
		self.d = Total_x / self.NOC - 4
		self.r = self.d / 2
		self.sx = 2
		self.sy = Total_y - self.d - 60
		methods = [ self.red,
					self.green, 
					self.blue, 
					self.yellow, 
					self.purple, 
					self.black ]
		# Calculates coordinates for the circles and bind their functions
		for i in range(self.NOC):
			x, y = self.sx + (self.d + 4) * i, self.sy
			self.c[i] = (x + self.r, y + self.r)
			self.rect[i] = ((x, y), (x + self.d, y + self.d))
			self.canvas.bind(key_codes.EButton1Down, methods[i], self.rect[i])	
			self._draw.ellipse(self.rect[i], fill=self.colors[i])
		bw, bh, xl, yl, dl = Total_x/2 - 10, 40, self.sx, self.sy + 10, self.d
		button1 = ((xl, yl + dl), (xl + bw, yl + dl + bh))
		self._draw.rectangle(button1, fill=0x555555)
		self._draw.text((xl + bw/2 - 5, yl + dl + 30), u'OK', 0x10bdff)
		self.canvas.bind(key_codes.EButton1Down, self.evaluateGuess, button1)
		ox = xl + bw + 10
		button2 = ((ox, yl + dl), (ox + bw, yl + dl + bh))
		self._draw.rectangle(button2, fill=0x555555)
		self._draw.text((ox + bw/2 - 5, yl + dl + 30), u'<-', 0x10bdff)
		self.canvas.bind(key_codes.EButton1Down, self.removeGuess, button2)
		self.createSecret()
		app_lock = e32.Ao_lock()
		self.handle_redraw(())
		app_lock.wait()
	
	def createSecret(self):
		self.secret = [6] * 4
		for i in range(len(self.secret)):
			self.secret[i] = random.randint(0, self.NOC - 1)
		#self._draw.text((10, 200), unicode(";".join(str(s) for s in self.secret)), 0x000000) 
		
	def handle_redraw(self, param):
		if self.backup_img: self.cdraw.blit(self.backup_img)
		
	def removeGuess(self, pos):
		if self.gcol == 0: return
		self.gcol -= 1
		x, y = 2 + (self.gr + 2) * self.gcol, 2 + (self.gr + 2) * self.gcnt
		corners = ((x, y), (x + self.gr, y + self.gr))
		self._draw.ellipse(corners, fill=self.colors[6])
		self.handle_redraw(())
		
	def addGuess(self, cnum):		
		if self.gcnt == 9 or self.gcol == 4: return
		print "accessing [%d][%d]" % (self.gcnt, self.gcol)
		self.g[self.gcnt][self.gcol] = cnum
		x, y = 2 + (self.gr + 2) * self.gcol, 2 + (self.gr + 2) * self.gcnt
		corners = ((x, y), (x + self.gr, y + self.gr))
		self._draw.ellipse(corners, fill=self.colors[self.g[self.gcnt][self.gcol]])
		self.handle_redraw(())
		self.gcol += 1
			
	def evaluateGuess(self, pos):
		if self.gcol != 4: return
		guessing = self.g[self.gcnt]
		answer = ""
		used = [False] * 4
		matched = [False] * 4
		for i in range(len(self.secret)):
			if guessing[i] == self.secret[i]: 
				answer += "X"
				used[i] = True
				matched[i] = True
		for i in range(len(self.secret)):
			if matched[i]: continue
			for j in range(len(self.secret)):
				if used[j]: continue
				if guessing[i] == self.secret[j]:
					answer += "0"
					used[j] = True
					break
		x, y = 2 + (self.gr + 2) * self.gcol, 17 + (self.gr + 2) * self.gcnt
		if not answer: answer = "__"
		self._draw.text((x, y), unicode(answer), 0x000000)
		self.gcnt += 1
		self.gcol = 0
		if answer == "XXXX": self.replay('Congratulations, you won!'); return
		elif self.gcnt == 9: self.replay('You lost!'); return		
		self.handle_redraw(())
	
	def replay(self, msg):
		again = appuifw.query(unicode(msg) + u'Play again?', 'query')
		if again: self.__init__()
		else: sys.exit(0)
		
	def __testpos(self,idx, pos):
		''' Tests whether a given point (pos) 
		is inside the circle of index (idx) '''
		dist = math.hypot(pos[0] - self.c[idx][0], pos[1] - self.c[idx][1])
		return dist <= self.r
	
	def red(self, pos):
		self.guess(0, pos)
	def green(self, pos):
		self.guess(1, pos)
	def blue(self, pos):
		self.guess(2, pos)
	def yellow(self, pos):
		self.guess(3, pos)
	def purple(self, pos):
		self.guess(4, pos)
	def black(self, pos):
		self.guess(5, pos)	
		
	def guess(self, idx, pos=None):
		if self.__testpos(idx, pos): self.addGuess(idx)

Mastermind()
	