def reverse(s):
	return s[::-1]

if __name__ == "__main__":
	str_input = input("Enter a string: ")
	print(f"Reversed string: {reverse(str_input)}")