"""GUI"""
from tkinter import *
from inspect import *

win = Tk()
# win.title("Sahil practice")
# win.geometry('300x300')
# win.configure(background = 'blue')

# print(dir(Button))
# print(getmembers(Button))
# [print(ele) for ele in getmembers(Button)]
print(signature(Button))

l1 = Label(win, text="Name").grid(row=0, column=0)
e1 = Entry(win).grid(row=0, column=1)
btn = Button(win, text="name", command=sys.exit).grid(row=1, column=1)

win.mainloop()