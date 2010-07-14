'''
# Connect 4
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

class Connect4:
	
	def __init__(self):		
		self.lin = 6
		self.col = 7
		self.diff = 1
		self.onminimax = False
		self.m = [[-1 for i in range(self.col)] for j in range(self.lin)]
		self.dir = [[0, -1], [-1, -1], [-1, 0], [-1, 1], [0, 1]]
		self.score = [0, 0]
		self.score_m = []
		self.v = []
		for i in range(self.lin):
			self.v.append([])
			self.score_m.append([])
			for j in range(self.col):
				self.v[i].append([])
				self.score_m[i].append([])
				for d in range(len(self.dir)):
					self.v[i][j].append(False)
					self.score_m[i][j].append([0, 0])
		self.value = [0, 1, 4, 32, 512, 512, 512, 512]
		self.cline = [5] * self.col
		self.colors = [ 0xff0000, 0x0000ff ]
		self.playing = 0
		self.scol = -1
		self.p1 = True
		
		self.canvas = appuifw.Canvas(redraw_callback=self.handle_redraw)
		self.cW, self.cH = self.canvas.size
		self.cdraw = Draw(self.canvas)
		appuifw.app.body = self.canvas
		self.backup_img=Image.new((self.cW, self.cH))
		self._draw = Draw(self.backup_img)
		appuifw.body = self._draw
		self.calcPos()
		self.drawGameBoard()		
		app_lock = e32.Ao_lock()
		app_lock.wait()
		
	def calcPos(self):
		'''Calculates the side of a game cell, the limits of the board, then
		binds the board event '''
		self.side = (self.cW - 4) / self.col 		# side of the square
		if self.cW > self.cH: self.side = (self.cH - 4) / self.col
		yleft = self.cH - self.side * self.lin		# space left vertically
		xleft = self.cW - self.side * self.col		# space left horizontally
		self.xb = xleft / 2							# board's xmin
		self.yb = yleft / 2							# board's ymin
		self.xm = self.xb + self.side * self.col	# board's xmax
		self.ym = self.yb + self.side * self.lin	# board's ymax
		board = ((self.xb, self.yb), (self.xm, self.ym))
		self.canvas.bind(key_codes.EButton1Down, self.checkColumn, board)
		self.lcs = (self.cW - 100) / 5
		board = ((0, 10),(self.cW, 10 + self.lcs))
		self.canvas.bind(key_codes.EButton1Down, self.changeLevel, board)
	
	def changeLevel(self, pos):
		level = (pos[0] * 5) / self.cW + 1
		if level != self.diff:
			self.diff = level
			self.drawGameBoard()
		
	def checkColumn(self, pos):
		'''Checks which column was touched, if it was already selected,
		drops a piece on the selected column, else selects the column'''
		x = pos[0] - self.xb			# x position (relative to the board)
		s = self.side					# side of the square
		c = x / s						# column selected
		if self.scol == c: self.doPlay(c, self.playing);
		else: self.scol = c				# sets selected column to 'c'			
		self.drawGameBoard()			# redraw game board
	
	def doPlay(self, col, v):
		'''Drops a piece in column 'col', with the color of the current player,
		unless the column is already full. Returns True if succesful, False otherwise'''
		if v == -1: self.cline[col] += 1	
		line = self.cline[col]			# line where the piece will stop
		r = self.m[line][col]
		self.m[line][col] = v #TO AQUI
		if v != -1: self.cline[col] -= 1# sets current line on that column up
		
		self.playing = 1 - self.playing	# changes current player
		self.scol = -1					# deselect column
					# sets matrix value to player (red, blue)	
		
		win_score = self.checkWin()
		#if not self.onminimax: print "win_score = %d" % win_score
		if abs(win_score) == 1000:
			if not self.onminimax: 
				if v: self.replay("You lost!")
				else: self.replay("Congratulations, you won!")
				return win_score
		if v == -1: score = self.updateScore(line, col, r)
		else: score = self.updateScore(line, col)
		if abs(win_score) == 1000:
			return win_score
		#if not self.onminimax:
			#self.showMatrix()
			#print "Score (RED, BLUE) = (%d, %d)" % (self.score[0], self.score[1])
			
		# if the game is in 1P mode and it's blue's turn, play for blue
		# using the minimax algorithm, with a depth level of 3
		# and prune with the alpha-beta algorithm
		#print "Played, scorem (%d) after: " % id(scorem)
		#print "\n".join(str(k) for k in scorem[5])
		
		if self.p1 and self.playing == 1 and not self.onminimax:
			self.onminimax = True
			#tb = time.clock()
			result = self.minimax(0, -10000, 10000, 1)
			#ta = time.clock()
			#print "Time spent: %.3fs, Best column: %d, score = %d" % (ta - tb, result[1], result[0])
			self.onminimax = False
			#print "BM Score (RED, BLUE) = (%d, %d)" % (self.score[0], self.score[1])	
			self.doPlay(result[1], self.playing)
		return score
		
	def updateScore(self, line, col, r = -1):
		dscore = self.score_m[line][col]
		p = self.m[line][col]
		if r == -1:
			for d in range(len(self.dir)):
				self.score[1 - p] -= self.value[dscore[d][1 - p]]
				self.score[p] -= self.value[dscore[d][p]]
				nl = line + self.dir[d][0]
				nc = col  + self.dir[d][1]
				if nl < 0 or nc < 0 or nc >= self.col: continue
				if self.m[nl][nc] != -1: continue
				x = dscore[d][p] + 1
				self.score[p] += self.value[x]
				self.score_m[nl][nc][d][p] = x
		else:
			#print "Removendo a jogada em (%d, %d)" % (line, col)
			for d in range(len(self.dir)):
				nl = line + self.dir[d][0]
				nc = col  + self.dir[d][1]
				if nl < 0 or nc < 0 or nc >= self.col: continue
				if self.m[nl][nc] == -1:
					v = self.score_m[nl][nc][d][r]
					self.score[r] -= self.value[v]
					#print "zerando score_m[%d][%d][%d][%d]" % (nl, nc, d, r)
					self.score_m[nl][nc][d][r] = 0
			for d in range(len(self.dir)):
				nl = line - self.dir[d][0]
				nc = col  - self.dir[d][1]
				if nl >= self.lin or nc < 0 or nc >= self.col: continue
				if self.m[nl][nc] != -1:
					toadd = self.m[nl][nc]
					x = dscore[d][toadd]
					self.score[toadd] += self.value[x]
		return self.score[1] - self.score[0]
		
	def minimax(self, d, a, b, max):
		bestcol = -1
		if d == self.diff:
			score = self.score[1] - self.score[0]
			return score, bestcol
		for i in range(self.col):
			if self.cline[i] == -1: continue		
			rscore = self.doPlay(i, self.playing)		
			if abs(rscore) < 1000:
				result = self.minimax(d + 1, a, b, 1 - max)
				if max:
					if result[0] > a:
						a = result[0]
						bestcol = i
				elif result[0] < b:
					b = result[0]
					bestcol = i
			self.doPlay(i, -1)
			if abs(rscore) == 1000:
				return rscore, i
			if b <= a: break
		ret = b
		if max: ret = a
		return ret, bestcol
		
	def check(self, line, col, v = 1, d = -1):
		if v == 4: 							# Found four pieces forming a line
			self.fw = self.m[line][col]
			return
		for i in range(len(self.dir)):		# Searches in all directions
			if d != -1 and i != d: continue	# if it's not the same direction
			nl = line + self.dir[i][0]
			nc = col  + self.dir[i][1]		# calculates the new line 
			if nl < 0 or nc >= self.col or nc < 0: continue
			if d == -1 and self.v[nl][nc][i]: continue
			if not self.v[nl][nc][d] and self.m[nl][nc] == self.m[line][col]:
				self.v[nl][nc][d] = True
				self.check(nl, nc, v + 1, i)
				if self.fw != -1: return
	
	def clearVisited(self):
		for i in range(self.lin):
			for j in range(self.col):
				for d in range(len(self.dir)):
					self.v[i][j][d] = 0
					
	def checkWin(self):
		self.fw = -1
		self.clearVisited()
		for i in range(self.lin - 1, min(self.cline), -1):
			for j in range(self.col):
				if self.m[i][j] != -1:
					self.check(i, j)
					if self.fw != -1: return 2000 * self.fw - 1000
		return 0
					
	def drawGameBoard(self):
		self._draw.clear()
		if self.scol != -1:
			x1 = self.xb + self.scol * self.side
			rect = ((x1, self.yb), (x1 + self.side, self.ym))			
			self._draw.rectangle(rect, fill=0xffffaa)
		for i in range(5):
			color = 0x3366cc
			if i + 1 == self.diff: color = 0xff9933
			x1 = 10 + (self.lcs + 20) * i
			self._draw.rectangle(((x1, 15), (x1 + self.lcs, 15 + self.lcs)), 0, color)
			x1 = x1 + self.lcs/2 - 5
			self._draw.text((x1, 47), unicode(str(i + 1)), fill=0xffffff)
		for j in range(self.col):
			x1 = self.xb + j * self.side
			for i in range(self.cline[j] + 1, self.lin):
				y1 = self.yb + i * self.side
				rect = ((x1, y1), (x1 + self.side, y1 + self.side))
				color = self.colors[self.m[i][j]]
				self._draw.rectangle(rect, fill=color)
		for i in range(self.lin + 1):
			y = self.yb + i * self.side
			self._draw.line((self.xb, y, self.xm, y), 0)
		for j in range(self.col + 1):
			x = self.xb + j * self.side
			self._draw.line((x, self.yb, x, self.ym), 0)
		self.handle_redraw(())
		
	def handle_redraw(self, param):
		if self.backup_img: self.cdraw.blit(self.backup_img)
	
	def replay(self, msg):
		again = appuifw.query(unicode(msg) + u' Play again?', 'query')
		if again: self.__init__()
		else: sys.exit(0)		

Connect4()
	