"""Database"""
import sqlite3
con = sqlite3.connect("temp.db") 

con.cursor().execute("""CREATE TABLE IF NOT EXISTS sahil
	(ID INT PRIMARY KEY,
	NAME TEXT,
	EMAIL TEXT);""")

#con.cursor().execute("""INSERT INTO sahil VALUES (0, "sahil", "sahil@gmail.com")""")

# print(dir(Button))
# print(dir(con))

a = con.cursor().execute("""SELECT * from sahil""")
print(*a)

con.commit()
con.close()