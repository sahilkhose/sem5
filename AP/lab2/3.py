import random

### a part:
user_dict = {}
print("enter dictionary values, -1 to exit:")
while True:
	value = input()
	if value == "-1":
		break
	key = random.randrange(0, 100)
	while key in user_dict.keys():
		key = random.randrange(0, 100)
	user_dict[key] = value
print("\nThe dictionary generated is:")
print(user_dict)

### b and c part:
num_list = []
str_list = []
for ele in user_dict.values():
	if ele.isnumeric():
		num_list.append(int(ele))
	else:
		str_list.append(ele)
if len(num_list):
	print("\nAverage of numbers: ", sum(num_list) / len(num_list))
print("\nConcatenated strings: ", "".join(str_list))

### e part:
special_list = []
print("\nDisplaying all special characters values:")
for tag in user_dict.values():
	if not any([ele.isalnum() for ele in list(tag)]):
		special_list.append(tag)
		print(tag)

### d part:
print("\nAll numbers:")
print(num_list)
print("\nOthers:")
for key, val in user_dict.items():
	if not val.isnumeric() and val not in special_list:
		print(key, val)