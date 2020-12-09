n = int(input("Enter value of n: "))
str_list = [input() for _ in range(n)]
count = 0
for string in str_list:
	if string.endswith(string[0]) and len(string) > 1:
		count += 1
print("Count is: ", count)
[print(string) for string in str_list if len(string)%2 != 0]