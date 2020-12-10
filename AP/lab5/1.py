class Employee:
	def __init__(self, id_, name, salary, dept):
		self.id = id_
		self.name = name
		self.salary = salary
		self.dept = dept
		self.details = (self.id, self.name, self.salary, self.dept)
	def display(self):
		print(f"id: {self.id}, name: {self.name}, salary: {self.salary}, dept: {self.dept}")

		
if __name__ == '__main__':
	num = int(input("Enter the number of Employees: "))
	emp_list = [] # list storing the object
	emp_details_list = [] # list storing the tuples
	for i in range(num):
		emp_list.append(Employee(
			int(input("id: ")),
			input("name: "),
			int(input("salary: ")),
			input("dept: ")))
		emp_details_list.append(emp_list[i].details)
		print()
	print("Employees details: ")
	[print(ele) for ele in emp_details_list]
	print()
	id_ = int(input("enter Employee id to search: "))
	for emp in emp_list:
		if emp.id == id_:
			emp.display()
			break
	else:
		print("No such id was found!")