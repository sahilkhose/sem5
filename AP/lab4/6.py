#!/usr/bin/python3
"""
Practice script
"""
class Sahil:
	def __init__(self, a=None, b=None):
		self.a = a
		self.b = b
	def disp(self):
		print(self.a, self.b)
	@classmethod
	def xy(cls, x, y):
		return cls(y, x)
	@staticmethod
	def r(num):
		print(num+1)

def sahil():
	"""This is a function description!"""
	print("Hello")

if __name__ == "__main__":
	Sahil(2, 3).disp()

	print("@classmethod")
	Sahil.xy(3, 2).disp()
	Sahil().xy(3, 2).disp()

	print("@staticmethod")
	Sahil.r(2)
	Sahil().r(2)

	# print(sahil.__doc__)
	# import sys
	# print(sys.path)