"""Total number of chars, words, lines in a file"""
file = open("a.txt").read().split("\n")
lines = len(file)
words = 0
chars = 0
for line in file:
	for word in line.split():
		words+=1
		chars+=len(word) # not including spaces and \n
chars = chars + (words - 1)
print(f"Lines: {lines}, Words: {words}, Chars: {chars}")