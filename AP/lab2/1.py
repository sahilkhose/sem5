word_dict = {}
for word in input().split():
	if word not in word_dict:
		word_dict[word] = 1
	else:
		word_dict[word] +=1
print("Number of unique words:", len(word_dict))