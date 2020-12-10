sentence = input("Enter a sentence: ")
print(" ".join([word.capitalize() for word in sentence.split()]))