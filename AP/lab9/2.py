class Circle:
	def __init__(self, name, parent):
		self.name = name
		self.parent = parent
		self.child = None
		if parent:
			parent.child = self
	def cleanup(self):
		self.child = self.parent = None
	def __del__(self):
		print("Enter __del__ on:", self.name)

def test1():
	a = Circle("a", None)
	b = Circle("b", a)

def test2():
	c = Circle("c", None)
	d = Circle("d", c)
	d.cleanup()

test1()
# test2()
