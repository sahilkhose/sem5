print("Enter 2 lists:")
l1 = [*map(int, input().split())]
l2 = [*map(int, input().split())]
print("List 1: ", l1)
print("List 2: ", l2)
a = [ele for ele in l1 if ele%2 != 0]
[a.append(ele) for ele in l2 if ele%2 == 0]
print("Final List: ", a)