import sqlite3
conn = sqlite3.connect('example.db')

c = conn.cursor()

c.execute('''CREATE TABLE students(name text, reg_no real, email text, ph_no real)''')
c.execute("INSERT INTO students VALUES ('sahil',180953218,'sahil@gmail.com',100100100)")

conn.commit()

conn.close()