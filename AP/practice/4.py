"""another practice"""
import sqlite3 

def create_db():
	conn = sqlite3.connect("a.db")
	c = conn.cursor()

	c.execute("""CREATE TABLE IF NOT EXISTS sahil 
		(name text,
		num int,
		reg real);""")
	c.execute("""INSERT INTO sahil VALUES ("sahil", 2, 2.3) """)
	a = c.execute("""SELECT * from sahil """)
	print(*a)
	conn.commit()
	conn.close()

from tkinter import *

def create_gui():
	win = Tk()
	win.geometry("300x300")
	win.title("this is amazing!")
	win.configure(bg="blue")

	Button(win, text="sahil").grid(row=0, column=0)

	win.mainloop()

if __name__ == "__main__":
	create_gui()