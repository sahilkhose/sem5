import cmath
real = int(input("Enter real part:"))
img = int(input("Enter imaginary part:"))
num = complex(real, img)
print(f"sin({num}) = {cmath.sin(num)}")
print(f"square_root({num}) = {cmath.sqrt(num)}")
print(f"log({num}) = {cmath.log10(num)}")