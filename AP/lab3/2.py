def unique(list_):
	return(list(set(list_)))
if __name__ == '__main__':
	print(unique([*map(float, input("Enter the numbers: ").split())]))