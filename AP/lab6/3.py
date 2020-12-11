import sqlite3
conn = sqlite3.connect('example.db')
print("Database connected.")

c = conn.cursor()

c.execute('''CREATE TABLE students
	(ID INT PRIMARY KEY		NOT NULL, 
	NAME TEXT 	NOT NULL, 
	email CHAR(50)	NOT NULL, 
	ph_no INT);''')
print("Table created.")


c.execute("INSERT INTO students VALUES (180953218, 'sahil', 'sahil@gmail.com',100100100)")
c.execute("INSERT INTO students VALUES (180953222, 'abhinav', 'abhinav@gmail.com',100100101)")

conn.commit()
print("Records created.")
conn.close()