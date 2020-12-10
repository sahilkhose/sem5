import time
user_name = input("Enter the user_name: ")
print(f"Welcome {user_name}, the time is: {time.asctime(time.localtime(time.time()))}")