def mul(list_):
	if not len(list_):
		return("Enter a non-empty list!")
	res = 1.
	for ele in list_:
		res = res * ele
	return res

if __name__ == '__main__':
	list_ = [*map(float, input("Enter list: ").split())]
	print(mul(list_))