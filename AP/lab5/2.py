class Vehicle:
	def __init__(self, owner_name=None, id_=None, manu_name=None):
		self.owner_name = owner_name
		self.id = id_
		self.manu_name = manu_name

class Passenger(Vehicle):
	def __init__(self, no_passengers=None, owner_name=None, id_=None, manu_name=None):
		super().__init__(owner_name, id_, manu_name)
		self.no_passengers = no_passengers

	def take_input(self):
		self.owner_name = input("Enter owner_name: ")
		self.id = input("Enter the id: ")
		self.manu_name = input("Enter the manu_name: ")
		self.no_passengers = input("Enter the no_passengers: ")

	def display(self):
		print(f"\nOwner name: {self.owner_name}, ID: {self.id}, Manu name: {self.manu_name}, Num of Passengers: {self.no_passengers}")

if __name__ == '__main__':
	p = Passenger()
	p.take_input()
	p.display()