class SpecialFile:
	def __init__(self, filename):
		self.__file = open(filename, "w")
		self.__file.write("Start Special File\n")
	def write(self, str):
		self.__file.write(str)
	def writelines(self, str_list):
		self.__file.writelines(str_list)
	def __del__(self):
		print("entered __del__")
		self.close()
	def close(self):
		if self.__file:
			self.__file.write("End Special File")
			self.__file.close()
			self.__file = None

if __name__ == "__main__":
	f = SpecialFile("test.txt")
	f.writelines("this is the beginning\n")
	# f.close()
	del f
	# f.write("End of program")