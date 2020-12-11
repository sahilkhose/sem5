"""GUI"""
from tkinter import *
import sys
window = Tk()
window.title("Manipal Institute Of Technology")
window.geometry('400x400')
window.configure(background = "blue");
a = Label(window ,text = "Name").grid(row = 0,column = 0)
b = Label(window ,text = "Registration Number").grid(row = 1,column = 0)
c = Label(window ,text = "Email Id").grid(row = 2,column = 0)
d = Label(window ,text = "Contact Number").grid(row = 3,column = 0)
a1 = Entry(window).grid(row = 0,column = 1)
b1 = Entry(window).grid(row = 1,column = 1)
c1 = Entry(window).grid(row = 2,column = 1)
d1 = Entry(window).grid(row = 3,column = 1)
def clicked():
   res = "Welcome to " + txt.get()
   lbl.configure(text= res)
btn = Button(window ,text="Submit").grid(row=4,column=0)
window.bind(clicked)
window.mainloop()