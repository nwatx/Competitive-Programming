import numpy as np

class Case3:
	def __init__(self, shape):
		self.grid = np.zeros(shape=shape)
		self.x = 0
		self.y = 0

	def calculate_binomial(self, steps):
		# 2d binomial distribution
		