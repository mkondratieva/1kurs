import doctest
def task(str='1.txt'):
	"""           '
	>>> f=open("1.txt","w")
	>>> b=f.write(" 1          1\\n 1 1")
	>>> f.close()
	>>> task()
	1.0
	>>> f=open("1.txt","w")
	>>> b=f.write("1 1\\n\\n k1")
	>>> f.close()
	>>> task()
	'Bad File'
	>>> task('\t f  ghfghfghfghfghfghfhgffvh')
	'File not found'

	"""
	try:
		f=open(str)
		n=0
		s=0.
		for line in f:
			for x in line.split():
				s+=int(x)
				n+=1
		s/=n
		return s
	except ValueError:
		return "Bad File"
	except FileNotFoundError:
		return "File not found"
	except ZeroDivisionError:
		return "Empty file"
def main():       
	print(task())
#main() 
doctest.testmod()

