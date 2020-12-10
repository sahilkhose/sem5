class subsets():
	def __init__(self, inp_list):
		self.inp_list = inp_list
	def sub(self):
	    base = []   
	    all_subsets = [base] 
	    for i in range(len(self.inp_list)): 
	        orig = all_subsets[:] 
	        new = self.inp_list[i] 
	        for j in range(len(all_subsets)): 
	            all_subsets[j] = all_subsets[j] + [new] 
	        all_subsets = orig + all_subsets 
	          
	    return all_subsets

if __name__ == '__main__':
	l = list(map(int, input("enter the list of input: ").split()))
	print(subsets(l).sub())